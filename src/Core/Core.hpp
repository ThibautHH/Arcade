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
            Core();

            /**
             * @brief Destroy the Core object
             *
             */
            ~Core();

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
    };
}

#endif /* !CORE_HPP_ */
