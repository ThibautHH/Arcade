/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Processor
*/

#ifndef ARCADE_CORE_PROCESSOR_HPP_
    #define ARCADE_CORE_PROCESSOR_HPP_

    #include "ModuleLibrary.hpp"

namespace Arcade::Core {
    class Processor {
        public:
            Processor(const char *path);

            void run();

        private:
            const ModuleLibrary<Displays::IModule> _moduleLibrary;
    };
}

#endif /* !ARCADE_CORE_PROCESSOR_HPP_ */
