/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

#include "../Data.hpp"

namespace Arcade::Displays {

    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;

            virtual void drawMap(Arcade::Data data) = 0;
            virtual void drawScore(Arcade::Data data) = 0;
        private:
    };

}

#endif /* !IDISPLAYMODULE_HPP_ */
