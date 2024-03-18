/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#include "DynamicLibrary.hpp"

using namespace Arcade::Core;

DynamicLibrary::DynamicLibrary(const char *path)
    : _handle(dlexec(std::bind(dlopen, path, RTLD_LAZY)), dlclose)
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
