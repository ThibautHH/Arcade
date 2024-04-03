/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#include "ModuleLibrary.hpp"

using namespace Arcade::Core;

template<typename T, const char symbol[]>
ModuleLibrary<T, symbol>::ModuleLibrary()
    : DynamicLibrary(), _moduleCreator(nullptr)
{
}

template<typename T, const char symbol[]>
ModuleLibrary<T, symbol>::ModuleLibrary(const char *path)
    : DynamicLibrary(path), _moduleCreator(this->getModuleCreator())
{
}

template<typename T, const char symbol[]>
ModuleLibrary<T, symbol>::module_creator *ModuleLibrary<T, symbol>::getModuleCreator() const
{
    return (module_creator *)dlexec(std::bind(dlsym, this->_handle.get(), ModuleCreatorSymbol));
}

template<typename T, const char symbol[]>
void ModuleLibrary<T, symbol>::reload(const char *path)
{
    this->loadLibrary(path);
    this->_moduleCreator = this->getModuleCreator();
}

template<typename T, const char symbol[]>
std::unique_ptr<T> ModuleLibrary<T, symbol>::createModule() const
{
    return std::unique_ptr<T>(this->_moduleCreator());
}
