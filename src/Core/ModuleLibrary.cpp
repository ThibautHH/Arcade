/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#include "ModuleLibrary.hpp"

using namespace Arcade::Core;

void *ModuleLibraryBase::dlexec(std::function<void *(void)> dlfunc)
{
    dlerror();
    void * const result = dlfunc();
    const char *error = dlerror();
    if (error)
        throw std::runtime_error(error);
    return result;
}

ModuleLibraryBase::ModuleLibraryBase(const char *path)
    : _handle(dlexec(std::bind(dlopen, path, RTLD_LAZY)), dlclose)
{
}

template<typename T>
ModuleLibrary<T>::ModuleLibrary(const char *path)
    : ModuleLibraryBase(path),
    _moduleCreator((module_creator *)dlexec(std::bind(dlsym, _handle.get(), ModuleCreatorSymbol)))
{
}

template<typename T>
std::unique_ptr<T> ModuleLibrary<T>::createModule() const
{
    return std::unique_ptr<T>(this->_moduleCreator());
}
