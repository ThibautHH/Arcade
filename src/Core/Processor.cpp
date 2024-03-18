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
    : _displayModuleLibrary(path), _gameModuleLibrary(),
    _displayModule(_displayModuleLibrary.createModule()),
    _gameModule(nullptr)
{
}

void Processor::run()
{
}
