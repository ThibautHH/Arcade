/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ITile
*/

#ifndef ITILE_HPP_
    #define ITILE_HPP_

#include <string>
#include "../Sprite/ISprite.hpp"

namespace Arcade::Displays {

    class ITile {
        public:
            virtual ~ITile() = default;

            virtual char getCharRepresentation() const = 0;
            virtual ISprite& getGraphicalRepresentation() const = 0;
    };

    class WallTile : public ITile {
        public:
            char getCharRepresentation() const override {
                return '#';
            }
            ISprite& getGraphicalRepresentation() const override {
                static WallSprite sprite;
                return sprite;
            }
    };

}

#endif /* !ITILE_HPP_ */
