/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#include "ModuleLibrary.hpp"

using namespace Arcade::Core;

template<typename T>
ModuleLibrary<T>::ModuleLibrary()
    : DynamicLibrary(), _moduleCreator(nullptr)
{
}

template<typename T>
ModuleLibrary<T>::ModuleLibrary(const char *path)
    : DynamicLibrary(path), _moduleCreator(this->getModuleCreator())
{
}

template<typename T>
ModuleLibrary<T>::module_creator *ModuleLibrary<T>::getModuleCreator() const
{
    return (module_creator *)dlexec(std::bind(dlsym, this->_handle.get(), ModuleCreatorSymbol));
}

template<typename T>
void ModuleLibrary<T>::reload(const char *path)
{
    this->loadLibrary(path);
    this->_moduleCreator = this->getModuleCreator();
}

template<typename T>
std::unique_ptr<T> ModuleLibrary<T>::createModule() const
{
    return std::unique_ptr<T>(this->_moduleCreator());
}
