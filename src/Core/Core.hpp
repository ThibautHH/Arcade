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
            Core(std::map<std::string, Arcade::Displays::IDisplayModule *> displayModules,
                std::map<std::string, Arcade::Games::IGameModule *> gameModules,
                std::string currentDisplayModule
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
            std::map<std::string, Arcade::Displays::IDisplayModule *> _displayModules;
            std::map<std::string, Arcade::Games::IGameModule *> _gameModules;
            std::string _currentDisplayModule;
            std::string _currentGameModule;
    };
}

#endif /* !CORE_HPP_ */
