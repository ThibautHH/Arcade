/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DynamicLibrary
*/

#ifndef ARCADE_CORE_DYNAMICLIBRARY_HPP_
    #define ARCADE_CORE_DYNAMICLIBRARY_HPP_

    #include <dlfcn.h>
    #include <functional>
    #include <memory>

namespace Arcade::Core {
    /**
     * @brief An abstract class capable of loading shared libraries
     */
    class DynamicLibrary {
        public:
            /**
             * @brief Represents an exception thrown when a libdl function fails
             *
             * @remark @ref std::exception::what "what()" will return the error message from @ref dlerror "dlerror()"
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
             * @remark This pointer will automatically call @ref dlclose "dlclose(void *)" on the raw handle when destroyed
             */
            typedef std::unique_ptr<void, decltype(dlclose) *> handle_ptr;
#pragma GCC diagnostic pop
            const handle_ptr _handle;

            DynamicLibrary(const char *path);
    };
}

#endif /* !ARCADE_CORE_DYNAMICLIBRARY_HPP_ */
