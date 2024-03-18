/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

using namespace Arcade;

Core::Core::Core(
    std::vector<std::shared_ptr<Displays::IDisplayModule>> displayModules,
    std::vector<std::shared_ptr<Games::IGameModule>> gameModules
) : _displayModules(std::move(displayModules)),
    _gameModules(std::move(gameModules))
{
}

Core::Core::~Core()
{
}

void Core::Core::menuLoop()
{
}
