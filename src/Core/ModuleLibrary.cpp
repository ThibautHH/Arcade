/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#include "ModuleLibrary.hpp"

using namespace Arcade::Core;

template<typename T>
ModuleLibrary<T>::ModuleLibrary(const char *path)
    : DynamicLibrary(path),
    _moduleCreator((module_creator *)dlexec(std::bind(dlsym, _handle.get(), ModuleCreatorSymbol)))
{
}

template<typename T>
std::unique_ptr<T> ModuleLibrary<T>::createModule() const
{
    return std::unique_ptr<T>(this->_moduleCreator());
}
