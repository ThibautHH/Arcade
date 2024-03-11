/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#include <dlfcn.h>
#include "ModuleLibrary.hpp"

using namespace Arcade::Core;

const ModuleLibraryBase::handle_ptr ModuleLibraryBase::openLibrary(const std::string &path)
{
    dlerror();
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    const char *error = dlerror();
    if (error)
        throw std::runtime_error(error);
    return handle_ptr(handle, dlclose);
}

ModuleLibraryBase::ModuleLibraryBase(const std::string &path)
    : _handle(openLibrary(path))
{
}

template<typename T>
ModuleLibrary<T>::ModuleLibrary(const std::string &path)
    : ModuleLibraryBase(path), _moduleCreator(loadModuleCreator())
{
}

template<typename T>
ModuleLibrary<T>::module_creator ModuleLibrary<T>::loadModuleCreator() const
{
    dlerror();
     T *(* const creator)(void) = dlsym(_handle.get(), ModuleCreatorSymbol);
    const char *error = dlerror();
    if (error)
        throw std::runtime_error(error);
    return creator;
}

template<typename T>
std::unique_ptr<T> ModuleLibrary<T>::createModule() const
{
    return this->_moduleCreator();
}
