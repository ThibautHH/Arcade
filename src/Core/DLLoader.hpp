/*
** EPITECH PROJECT, 2024
** bs_arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <iostream>
#include <dlfcn.h>

template <typename T>
class DLLoader {
    public:
        DLLoader(const std::string &path) : _path(path) {};
        ~DLLoader() = default;

        T *getInstance()
        {
            void *handle;
            T *(*entryPoint)();
            void (*deletePoint)(T *);

            handle = dlopen(_path.c_str(), RTLD_LAZY);
            if (!handle) {
                std::cerr << "Cannot open library: " << dlerror() << std::endl;
                return nullptr;
            }
            entryPoint = (T *(*)())dlsym(handle, "entryPoint");
            if (!entryPoint) {
                std::cerr << "Cannot load symbol entryPoint: " << dlerror() << std::endl;
                return nullptr;
            }
            deletePoint = (void (*)(T *))dlsym(handle, "deletePoint");
            if (!deletePoint) {
                std::cerr << "Cannot load symbol deletePoint: " << dlerror() << std::endl;
                return nullptr;
            }
            return entryPoint();
        };

    protected:
        const std::string &_path;
    private:
};

#endif /* !DLLOADER_HPP_ */
