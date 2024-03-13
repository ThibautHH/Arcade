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

namespace Core {

    class Core {
        public:
            Core();
            ~Core();
        private:
            Arcade::Displays::IDisplayModule *display;
            Arcade::Games::IGameModule *game;
    };
}

#endif /* !CORE_HPP_ */
