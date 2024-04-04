/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#include <string_view>

#include "ModuleLibrary.hpp"

using namespace std::literals;
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
    try {
        return (module_creator *)dlexec(std::bind(dlsym, this->_handle.get(), ModuleCreatorSymbol));
    } catch (const DynamicLibraryException &e) {
        const std::string_view what(e.what());
        if (what.ends_with("undefined symbol: "s + ModuleCreatorSymbol))
            throw NoEntrySymbolException(what.data());
        throw;
    }
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
