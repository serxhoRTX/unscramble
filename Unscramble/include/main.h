#pragma once
#include <endstone/plugin/plugin.h>
#include <algorithm>
#include <random>
#include <endstone/color_format.h>
#include <endstone/event/player/player_chat_event.h>
#include <endstone/scheduler/scheduler.h>

class Unscramble : public endstone::Plugin
{
private:
    static std::vector<std::string> word_pool;
    static bool active;
    static bool status;
    static int time_interval;
    static std::string partial_message;

public:
    void onLoad() override{
        getLogger().info("unscramble was loaded");
    }

    void onEnable() override{
        getLogger().info("unscramble was enabled");
        readConfigs();
            registerEvent(&Unscramble::onChatEvent, *this);
            getServer().getScheduler().runTaskTimer (*this, [&]()
            {
                sendUnscramble();
                getServer().getScheduler().runTaskLater(*this , [&]() { checkTimeout(); }, 1200 );
            }, 0, time_interval);

    }

    void onDisable() override{
        getLogger().info("unscramble was disabled");
    }

    static void readConfigs();

    void sendUnscramble() const {
        if (!status) return;
        active = true;
        std::vector<char> word_vector;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(word_pool.begin() , word_pool.end() , g);
        std::string word_sample = word_pool[0];

        for (char c : word_sample){
            word_vector.push_back(c);
        }

        shuffle(word_vector.begin(), word_vector.end(), g);
        word_sample = "";
        for (const char c : word_vector){
            word_sample += c;
        }

        getServer().broadcastMessage(endstone::ColorFormat::Bold + endstone::ColorFormat::Blue +
                 "UNSCRAMBLE " + endstone::ColorFormat::Reset + "- Unscramble the word " + endstone::ColorFormat::MaterialDiamond + word_sample +
                 endstone::ColorFormat::Reset + " to get a reward !");

    }

    void checkTimeout(){
        if (!status) return;
        if (!active) return;
        active = false;
        getServer().broadcastMessage("No one was able to unscramble the " + endstone::ColorFormat::MaterialDiamond + word_pool[0] + endstone::ColorFormat::Reset + " in time :(");
    }

    bool onCommand(endstone::CommandSender &sender, const endstone::Command &command, const std::vector<std::string> &args) override{
        if (command.getName() == "unscramble"){

            sender.sendMessage((status) ? "unscramble has been disabled" : "unscramble has been enabled");
            if (status)
                status = false;
            else status = true;

        }
        return true;
    }


    void onChatEvent(endstone::PlayerChatEvent &event){
        if (!active) return;
        if (event.getMessage() == word_pool[0]){


            getServer().broadcastMessage( endstone::ColorFormat::White + event.getPlayer().getName() +
                endstone::ColorFormat::Reset + " has unscrambled the word " + endstone::ColorFormat::MaterialDiamond + word_pool[0] +
                endstone::ColorFormat::Reset + " and won " + partial_message);

            active = false;

            fallbackFunction(event.getPlayer());
            event.cancel();
        }
    }
    void fallbackFunction(const endstone::Player &player){
    /* write yourp code below  here are some examples
        player.sendMessage("hello");
        player.sendMessage("hello " + player.getName()); */


    }
};
