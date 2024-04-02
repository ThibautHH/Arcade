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
    std::vector<Arcade::Displays::IDisplayModule *> displayModules,
    std::vector<Arcade::Games::IGameModule *> gameModules,
    Arcade::Displays::IDisplayModule *currentLib)
{
    std::cout << "Core constructor" << std::endl;
}

Core::Core::~Core()
{
}

void Core::Core::coreLoop()
{
}
