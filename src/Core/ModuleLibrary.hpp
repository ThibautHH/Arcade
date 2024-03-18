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
     * @tparam T The type of module to load, either a display or a game module.
     */
    template<typename T>
    class ModuleLibrary : public DynamicLibrary {
        public:
            /**
             * @brief Create a new ModuleLibrary
             *
             * @param path The path to the Arcade shared library module to load
             */
            ModuleLibrary(const char *path);

            /**
             * @brief Create a new module instance
             *
             * @return A unique pointer to the new module
             */
            std::unique_ptr<T> createModule() const;

        private:
            static constexpr const char ModuleCreatorSymbol[] = "createModule";

            typedef T *(module_creator)(void);
            const std::function<module_creator> _moduleCreator;
    };

    template class ModuleLibrary<Displays::IDisplayModule>;
    template class ModuleLibrary<Games::IGameModule>;
}

#endif /* !ARCADE_CORE_MODULELIBRARY_HPP_ */
