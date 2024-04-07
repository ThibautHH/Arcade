/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Processor
*/

#ifndef ARCADE_CORE_PROCESSOR_HPP_
    #define ARCADE_CORE_PROCESSOR_HPP_

    #include <optional>

    #include "ModuleLibrary.hpp"
    #include "Menu.hpp"

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
            static std::map<Games::KeyType, int> translateInputs(std::map<Displays::KeyType, int> inputs);
            static Displays::Vector2i translateVector(Games::Vector2i vector);
            static std::unique_ptr<Arcade::Displays::ISprite> translateSprite(Games::ISprite *sprite);
            static std::map<Games::Color, Displays::Color> DisplayColors;
            static std::map<Games::Shape, Displays::Shape> DisplayShapes;

            void displayGame(Games::IGameModule &game, const std::map<Games::KeyType, int> &inputs);
            void displayMenu(const std::map<Arcade::Games::KeyType, int> &inputs);
            void switchDisplayModule(const std::string &path);
            void changeDisplayModule(bool previous = false);
            std::optional<Menu> _menu;
            std::size_t _currentDisplayIndex = 0;
            DisplayLibrary _displayModuleLibrary;
            GameLibrary _gameModuleLibrary;
            std::unique_ptr<Displays::IDisplayModule> _displayModule;
            std::unique_ptr<Games::IGameModule> _gameModule;
    };
}

#endif /* !ARCADE_CORE_PROCESSOR_HPP_ */
