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
     * This class is responsible for loading arcade shared libraries and running the game.
     * It interfaces with the display and game modules, communicating the user inputs and the game screen.
     */
    class Processor {
        public:
            /**
             * @brief Create a new Processor running an initial display module
             *
             * @param path The path to the initial display module
             */
            Processor(const char *path);

            /**
             * @brief Start the Arcade core program logic
             */
            void run();

        private:
            ModuleLibrary<Displays::IDisplayModule> _displayModuleLibrary;
            ModuleLibrary<Games::IGameModule> _gameModuleLibrary;
            std::unique_ptr<Displays::IDisplayModule> _displayModule;
            std::unique_ptr<Games::IGameModule> _gameModule;
    };
}

#endif /* !ARCADE_CORE_PROCESSOR_HPP_ */
