/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Processor
*/

#include "Processor.hpp"
#include "Core.hpp"
#include <iostream>
#include <filesystem>

using namespace Arcade::Core;

Processor::Processor(const char *path)
    : _moduleLibrary(path)
{
    for (const auto& displayPath : DISPLAYS_PATH) {
        auto _lib = ModuleLibrary<Displays::IDisplayModule>(displayPath.data());
        if (libraryExists(displayPath.data())) {
            _displayModules.push_back(_lib.createModule());
            std::cout << "Display library loaded: " << displayPath << std::endl;
        } else {
            std::cerr << "Display library not found: " << displayPath << std::endl;
        }
    }

    for (const auto& gamePath : GAMES_PATH) {
        if (libraryExists(gamePath.data())) {
            auto _lib = ModuleLibrary<Games::IGameModule>(gamePath.data());
            _gameModules.push_back(_lib.createModule());
            std::cout << "Game library loaded: " << gamePath << std::endl;
        } else {
            std::cerr << "Game library not found: " << gamePath << std::endl;
        }
    }
}

void Processor::run()
{
    Core core(_displayModules, _gameModules);
}
