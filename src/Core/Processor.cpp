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
    for (const auto &path : GRAPH_LIB_PATH) {
        if (!std::filesystem::exists(path)) {
            std::cerr << "Error: " << path << " not found" << std::endl;
            exit(84);
        }
        DLLoader<Arcade::Displays::IDisplayModule> loader(path);
        _displayModules[path] = loader.getInstance();
    }
    for (const auto &path : GAME_LIB_PATH) {
        if (!std::filesystem::exists(path)) {
            std::cerr << "Error: " << path << " not found" << std::endl;
            exit(84);
        }
        DLLoader<Arcade::Games::IGameModule> loader(path);
        _gameModules[path] = loader.getInstance();
    }
    _currentDisplayModule = av;
}

void Processor::run()
{
    Arcade::Core::Core core(
        _displayModules, _gameModules, _currentDisplayModule
    );
    core.coreLoop();
}
