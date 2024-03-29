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
    /**
     * @brief Main class of the Core binary
     *
     * This class is responsible for loading arcade shared libraries
     * and running the game.
     * It interfaces with the display and game modules, communicating the
     * user inputs and the game screen.
     */
    class Processor {
        public:
            /**
             * @brief Create a new Processor running an initial display module.
             *
             * @param path The path to the initial display module.
             */
            Processor(const char *path);

            /**
             * @brief Start the Arcade core.
             *
             * This method will start the game/display loop.
             */
            void run();

        private:
            const ModuleLibrary<Displays::IModule> _moduleLibrary;
    };
}

#endif /* !ARCADE_CORE_PROCESSOR_HPP_ */
