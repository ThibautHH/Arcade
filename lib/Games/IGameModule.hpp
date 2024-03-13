/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
    #define IGAMEMODULE_HPP_

#include <string>
#include "../Data.hpp"

namespace Arcade::Games {

    class IGameModule {
        public:
            virtual ~IGameModule() = default;

            virtual void loadMap() = 0;
            virtual size_t getScore() = 0;
            virtual void setScore(size_t score) = 0;
            virtual Arcade::Data tick() = 0;
        private:
    };

}

#endif /* !IGAMEMODULE_HPP_ */