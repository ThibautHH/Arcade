/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Processor
*/

#ifndef ARCADE_CORE_PROCESSOR_HPP_
    #define ARCADE_CORE_PROCESSOR_HPP_

    #include "ModuleLibrary.hpp"
    #include "../Displays/Sprite.hpp"

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
            static std::map<Arcade::Games::KeyType, int> translateInputs(std::map<Arcade::Displays::KeyType, int> inputs);
            static Displays::Vector2i translateVector(Games::Vector2i inputs);
            static Displays::Sprite translateSprite(Games::ISprite &inputs);
            static std::map<Arcade::Games::Color, Arcade::Displays::Color> DisplayColors;
            static std::map<Arcade::Games::Shape, Arcade::Displays::Shape> DisplayShapes;

            ModuleLibrary<Displays::IDisplayModule> _displayModuleLibrary;
            ModuleLibrary<Games::IGameModule> _gameModuleLibrary;
            std::unique_ptr<Displays::IDisplayModule> _displayModule;
            std::unique_ptr<Games::IGameModule> _gameModule;
    };
}

#endif /* !ARCADE_CORE_PROCESSOR_HPP_ */
