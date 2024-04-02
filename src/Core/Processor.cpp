/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Processor
*/

#include "Processor.hpp"
#include "Core.hpp"
#include "DLLoader.hpp"
#include <iostream>
#include <filesystem>

using namespace Arcade::Core;

const std::vector<std::string> GRAPH_LIB_PATH = {
    "./lib/Display/NCurses/arcade_ncurses.so",
    "./lib/Display/SFML/arcade_sfml.so",
    "./lib/Display/SDL2/arcade_sdl2.so",
};

const std::vector<std::string> GAME_LIB_PATH = {
    "./lib/Games/Nibbler/arcade_nibbler.so",
    "./lib/Games/Snake/arcade_snake.so",
};

Processor::Processor(const char *av)
{
    for (auto &path : GRAPH_LIB_PATH) {
        if (std::filesystem::exists(path)) {
            std::cout << "Loading --> " << path << std::endl;
            DLLoader<Arcade::Displays::IDisplayModule> loader(path);
            auto lib = loader.getInstance();
            if (lib != nullptr) {
                std::cout << "Loaded --> " << path << std::endl;
                _displayModules.push_back(lib);
            }
        }
    }

    for (auto &path : GAME_LIB_PATH) {
        if (std::filesystem::exists(path)) {
            std::cout << "Loading --> " << path << std::endl;
            DLLoader<Arcade::Games::IGameModule> loader(path);
            auto lib = loader.getInstance();
            if (lib != nullptr) {
                std::cout << "Loaded --> " << path << std::endl;
                _gameModules.push_back(lib);
            }
        }
    }

    DLLoader<Arcade::Displays::IDisplayModule> loader(av);
    auto lib = loader.getInstance();
    if (lib != nullptr) {
        _currentDisplayModule = lib;
    }
}

void Processor::run()
{
    if (_displayModules.size() == 0) {
        std::cerr << "No display module found" << std::endl;
        return;
    }
    if (_gameModules.size() == 0) {
        std::cerr << "No game module found" << std::endl;
        return;
    }

    Arcade::Core::Core core(
        _displayModules, _gameModules, _currentDisplayModule
    );
}
