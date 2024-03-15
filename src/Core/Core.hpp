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

namespace Arcade {

    class Core {
        public:
            Core();
            ~Core();
        private:
            Arcade::Displays::IDisplayModule *_currentLib;
            Arcade::Games::IGameModule *_currentGame;
    };
}

#endif /* !CORE_HPP_ */
