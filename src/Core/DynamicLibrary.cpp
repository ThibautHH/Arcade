/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#include "DynamicLibrary.hpp"

using namespace Arcade::Core;

DynamicLibrary::DynamicLibrary()
    : _handle(nullptr, dlclose)
{
}

DynamicLibrary::DynamicLibrary(const char *path)
    : _handle(open(path), dlclose)
{
}

void *DynamicLibrary::dlexec(std::function<void *(void)> dlfunc)
{
    dlerror();
    void * const result = dlfunc();
    const char *error = dlerror();
    if (error)
        throw DynamicLibraryException(error);
    return result;
}

void *DynamicLibrary::open(const char *path)
{
    return dlexec(std::bind(dlopen, path, RTLD_LAZY));
}

void DynamicLibrary::loadLibrary(const char *path)
{
    this->_handle.reset(open(path));
}

bool DynamicLibrary::isLoaded() const noexcept
{
    return _handle.get() != nullptr;
}
