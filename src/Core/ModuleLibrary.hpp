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
    class ModuleLibraryBase {
        public:
            class DynamicLibraryException : public std::runtime_error {
                public:
                    DynamicLibraryException(const char *message)
                        : std::runtime_error(message)
                    {}
            };

        protected:
            static constexpr const char ModuleCreatorSymbol[] = "createModule";

            static void *dlexec(std::function<void *(void)> f);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
            typedef std::unique_ptr<void, decltype(dlclose) *> handle_ptr;
#pragma GCC diagnostic pop
            const handle_ptr _handle;

            ModuleLibraryBase(const char *path);
    };

    template<typename T>
    class ModuleLibrary : public ModuleLibraryBase {
        public:
            ModuleLibrary(const char *path);

            std::unique_ptr<T> createModule() const;

        private:
            typedef T *(module_creator)(void);
            const std::function<module_creator> _moduleCreator;
    };

    template class ModuleLibrary<Displays::IModule>;
    template class ModuleLibrary<Games::IModule>;
}

#endif /* !ARCADE_CORE_MODULELIBRARY_HPP_ */
