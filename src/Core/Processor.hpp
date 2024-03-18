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
            const ModuleLibrary<Displays::IDisplayModule> _moduleLibrary;

            std::vector<std::shared_ptr<Displays::IDisplayModule>> _displayModules;
            std::vector<std::shared_ptr<Games::IGameModule>> _gameModules;

            bool libraryExists(const char* path) {
                void* handle = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
                if (handle) {
                    dlclose(handle);
                    return true;
                } else {
                    return false;
                }
            }

            static constexpr std::string_view DISPLAYS_PATH[] = {
                "./lib/Display/NCurses/arcade_ncurses.so",
                //"./lib/Display/SFML/arcade_sfml.so",
                //"./lib/Display/SDL2/arcade_sdl2.so"
            };

            static constexpr std::string_view GAMES_PATH[] = {
                //"./lib/Games/Snake/arcade_snake.so",
                //"./lib/Games/Nibbler/arcade_nibbler.so"
            };
    };
}

#endif /* !ARCADE_CORE_PROCESSOR_HPP_ */
