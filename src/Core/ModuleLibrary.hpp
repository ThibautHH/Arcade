/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#ifndef ARCADE_CORE_MODULELIBRARY_HPP_
    #define ARCADE_CORE_MODULELIBRARY_HPP_

    #include <dlfcn.h>
    #include <functional>
    #include <memory>

    #include "../../lib/Display/IDisplayModule.hpp"
    #include "../../lib/Games/IGameModule.hpp"

    #include "DynamicLibrary.hpp"

namespace Arcade::Core {
    /**
     * @brief A class to load and create Arcade shared library modules
     *
     * @tparam T The type of module to load, either a display or a game module
     */
    template<typename T, const char symbol[]>
    class ModuleLibrary : public DynamicLibrary {
        public:
            class NoEntrySymbolException : public DynamicLibraryException
            {
                public:
                    NoEntrySymbolException(const char *message)
                        : DynamicLibraryException(message)
                    {}
            };

            static bool canLoad(const char *path)
            {
                bool canLoad = true;
                try {
                    ModuleLibrary<T, symbol> l(path);
                } catch (const NoEntrySymbolException &e) {
                    canLoad = false;
                }
                return canLoad;
            }

            /**
             * @brief Create an empty ModuleLibrary
             */
            ModuleLibrary();

            /**
             * @brief Create a new ModuleLibrary
             *
             * @param path The path to the Arcade shared library module to load
             */
            ModuleLibrary(const char *path);

            /**
             * @brief Reload the module library using the shared library at the given path
             *
             * @remark This method will automatically @ref dlclose any previously loaded module
             * @param path The path to tthe Arcade shared library module to load
             * @throw DynamicLibraryException If the library fails to load
             */
            void reload(const char *path);

            /**
             * @brief Create a new module instance
             *
             * @return A unique pointer to the new module
             */
            std::unique_ptr<T> createModule() const;

        private:
            static constexpr const char *ModuleCreatorSymbol = symbol;

            typedef T *(module_creator)(void);
            std::function<module_creator> _moduleCreator;

            module_creator *getModuleCreator() const;
    };

    struct ModuleLibrarySymbols {
        static constexpr const char DisplaysSymbol[] = "displayEntryPoint";
        static constexpr const char GamesSymbol[] = "gameEntryPoint";
    };

    template class ModuleLibrary<Displays::IDisplayModule, ModuleLibrarySymbols::DisplaysSymbol>;
    typedef ModuleLibrary<Displays::IDisplayModule, ModuleLibrarySymbols::DisplaysSymbol> DisplayLibrary;
    template class ModuleLibrary<Games::IGameModule, ModuleLibrarySymbols::GamesSymbol>;
    typedef ModuleLibrary<Games::IGameModule, ModuleLibrarySymbols::GamesSymbol> GameLibrary;
}

#endif /* !ARCADE_CORE_MODULELIBRARY_HPP_ */
