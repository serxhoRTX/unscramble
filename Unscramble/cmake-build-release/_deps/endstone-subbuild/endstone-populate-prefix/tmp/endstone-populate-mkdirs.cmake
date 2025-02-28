# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-src")
  file(MAKE_DIRECTORY "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-build"
  "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-subbuild/endstone-populate-prefix"
  "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-subbuild/endstone-populate-prefix/tmp"
  "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-subbuild/endstone-populate-prefix/src/endstone-populate-stamp"
  "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-subbuild/endstone-populate-prefix/src"
  "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-subbuild/endstone-populate-prefix/src/endstone-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-subbuild/endstone-populate-prefix/src/endstone-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/serxh/CLionProjects/Unscramble/cmake-build-release/_deps/endstone-subbuild/endstone-populate-prefix/src/endstone-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
