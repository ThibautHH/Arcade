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
    template<typename T>
    class ModuleLibrary : public DynamicLibrary {
        public:
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
            static constexpr const char ModuleCreatorSymbol[] = "entryPoint";

            typedef T *(module_creator)(void);
            std::function<module_creator> _moduleCreator;

            module_creator *getModuleCreator() const;
    };

    template class ModuleLibrary<Displays::IDisplayModule>;
    template class ModuleLibrary<Games::IGameModule>;
}

#endif /* !ARCADE_CORE_MODULELIBRARY_HPP_ */
