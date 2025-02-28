#include "main.h"
#include <yaml-cpp/yaml.h>

#include "../cmake-build-release/_deps/yaml-cpp-src/src/scanscalar.h"

std::vector<std::string> Unscramble::word_pool;
bool Unscramble::active = false;
bool Unscramble::status = true;
int Unscramble::time_interval = 600;
std::string Unscramble::partial_message = "";

void Unscramble::readConfigs(){
    if (!word_pool.empty()) return;
    const std::string path = R"(plugins\config.yaml)";
    YAML::Node configs = YAML::LoadFile(path);

    if (YAML::Node words = configs["Words"])
        for (auto word : words){
            word_pool.push_back(word.as<std::string>());
        }
    if (YAML::Node count = configs["Time-interval"])
        time_interval = count.as<int>() * 60 * 20;
    if (YAML::Node message = configs["Message"])
        partial_message = message.as<std::string>();
}

ENDSTONE_PLUGIN("unscramble", "0.1.0", Unscramble)
{
    description = "A simple unscramble plugin ";

    command("unscramble")
        .description("enable or disable unscramble.")
        .usages("/unscramble")
        .permissions("unscramble.command.unscramble");

    permission("unscramble.command.unscramble")
        .description("Allow users to use the /unscramble command.")
        .default_(endstone::PermissionDefault::Operator);
}
