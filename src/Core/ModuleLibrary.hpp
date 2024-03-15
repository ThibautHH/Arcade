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

    #include "../Displays/IModule.hpp"
    #include "../Games/IModule.hpp"

namespace Arcade::Core {
    /**
     * @brief An abstract class capable of loading shared libraries
     */
    class ModuleLibraryBase {
        public:
            /**
             * @brief Represents an exception thrown when a libdl function fails
             *
             * @remark @see std::exception#what() will return the error message from @see dlerror
             */
            class DynamicLibraryException : public std::runtime_error {
                public:
                    DynamicLibraryException(const char *message)
                        : std::runtime_error(message)
                    {}
            };

        protected:
            /**
             * @brief Execute a libdl function and check for errors
             *
             * @param f The function to execute, with its arguments bound
             * @return The result of the function
             * @throw DynamicLibraryException If the function fails
             */
            static void *dlexec(std::function<void *(void)> f);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
            /**
             * @brief libdl handle to the loaded shared library
             *
             * @remark This handle will automatically @see dlclose the library when destroyed
             */
            typedef std::unique_ptr<void, decltype(dlclose) *> handle_ptr;
#pragma GCC diagnostic pop
            const handle_ptr _handle;

            ModuleLibraryBase(const char *path);
    };

    /**
     * @brief A class to load and create Arcade shared library modules
     *
     * @tparam T The type of module to load, either a display or a game module.
     */
    template<typename T>
    class ModuleLibrary : public ModuleLibraryBase {
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

    template class ModuleLibrary<Displays::IModule>;
    template class ModuleLibrary<Games::IModule>;
}

#endif /* !ARCADE_CORE_MODULELIBRARY_HPP_ */
