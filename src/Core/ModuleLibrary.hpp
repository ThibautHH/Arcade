/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ModuleLibrary
*/

#ifndef ARCADE_CORE_MODULELIBRARY_HPP_
    #define ARCADE_CORE_MODULELIBRARY_HPP_

    #include <functional>
    #include <memory>
    #include <string>

namespace Arcade::Core {
    template<typename T>
    class IModuleLibrary {
        public:
          virtual ~IModuleLibrary() = default;

          virtual std::unique_ptr<T> createModule() const = 0;
    };

    class ModuleLibraryBase {
        protected:
            static constexpr const char ModuleCreatorSymbol[] = "createModule";

            typedef std::unique_ptr<void, std::function<int(void *)>> handle_ptr;
            const handle_ptr _handle;

            ModuleLibraryBase(const std::string &path);

        private:
            static const handle_ptr openLibrary(const std::string &path);
    };

    template<typename T>
    class ModuleLibrary : public IModuleLibrary<T>, public ModuleLibraryBase {
        public:
            ModuleLibrary(const std::string &path);

            std::unique_ptr<T> createModule() const final;

        private:
            typedef std::function<T *(void)> module_creator;
            const module_creator _moduleCreator;

            module_creator loadModuleCreator() const;
    };
}

#endif /* !ARCADE_CORE_MODULELIBRARY_HPP_ */
