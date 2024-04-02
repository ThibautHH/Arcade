/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include "Core.hpp"
#include "DLLoader.hpp"

using namespace Arcade;

Core::Core::Core(
    std::map<std::string, Arcade::Displays::IDisplayModule *> displayModules,
    std::map<std::string, Arcade::Games::IGameModule *> gameModules,
    std::string currentDisplayModule
) : _displayModules(displayModules),
    _gameModules(gameModules),
    _currentDisplayModule(currentDisplayModule),
    _currentGameModule("./lib/Games/Snake/arcade_snake.so")
{
}

Core::Core::~Core()
{
}

void Core::Core::coreLoop()
{
    Arcade::Displays::IDisplayModule *displayModule = _displayModules[_currentDisplayModule];
    Arcade::Games::IGameModule *gameModule = _gameModules[_currentGameModule];
    std::map<Arcade::Displays::KeyType, int> inputs;

    displayModule->init();
    gameModule->init("", 0);

    while (1) {
        displayModule->clear();
        inputs = displayModule->getInputs();
        if (inputs[Arcade::Displays::KeyType::ESC] == 1)
            break;
        displayModule->displayGame();
    }
    displayModule->close();
    gameModule->close();
}
