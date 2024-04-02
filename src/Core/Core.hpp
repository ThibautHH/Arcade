/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

#include "../../lib/Display/IDisplayModule.hpp"
#include "../../lib/Games/IGameModule.hpp"
#include "ModuleLibrary.hpp"


/**
 * @namespace Arcade::Core
 * @brief Contains classes and functions related to the core functionality of the arcade game.
 */
namespace Arcade::Core {

    /**
     * @class Core
     * @brief Core class of the arcade game.
     */
    class Core {
        public:
            /**
             * @brief Construct a new Core object
             *
            */
            Core(std::vector<Arcade::Displays::IDisplayModule *> displayModules,
                std::vector<Arcade::Games::IGameModule *> gameModules,
                Arcade::Displays::IDisplayModule *currentLib
            );

            /**
             * @brief Destroy the Core object
             *
             */
            ~Core();

            /**
             * @brief Run the arcade game
             *
             */
            void coreLoop();

            /**
             * @brief Loop for the menu
             *
             */
        private:
            /**
             * @brief Current library used by the Arcade
             *
             */
            Arcade::Displays::IDisplayModule *_currentLib;

            /**
             * @brief Current game used by the Arcade
             *
             */
            Arcade::Games::IGameModule *_currentGame;

            /**
             * @brief List of available display modules
             *
             */
            std::vector<std::shared_ptr<Displays::IDisplayModule>> _displayModules;

            /**
             * @brief List of available game modules
             *
             */
            std::vector<std::shared_ptr<Games::IGameModule>> _gameModules;
    };
}

#endif /* !CORE_HPP_ */
