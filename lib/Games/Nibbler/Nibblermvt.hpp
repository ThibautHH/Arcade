/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibblermvt
*/

#ifndef NIBBLERMVT_HPP_
#define NIBBLERMVT_HPP_

#include <vector>
#include "../IGameModule.hpp"

namespace Arcade::Games {

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class Nibblermvt {
        public:
            Nibblermvt();
            ~Nibblermvt() = default;


            void moveRight(std::vector<std::vector<Arcade::Games::ISprite *>> map);
            void moveLeft(std::vector<std::vector<Arcade::Games::ISprite *>> map);
            void moveUp(std::vector<std::vector<Arcade::Games::ISprite *>> map);
            void moveDown(std::vector<std::vector<Arcade::Games::ISprite *>> map);

            void moveBody();
            void updateSnake(std::vector<std::vector<Arcade::Games::ISprite *>> map, float deltaTime);
            void addBodyPart();

            void setDirection(Direction direction) { _direction = direction; };
            Direction getDirection(void) { return _direction; };

            void setHeadPos(Vector2i headPos) { _headPos = headPos; };
            Vector2i getHeadPos(void) { return _headPos; };

            void setBodyPos(std::vector<Vector2i> bodyPos) { _bodyPos = bodyPos; };
            std::vector<Vector2i> getBodyPos(void) { return _bodyPos; };

        protected:
            Direction _direction;
            Vector2i _headPos;
            std::vector<Vector2i> _bodyPos;
            std::size_t _speed;

    };
}

#endif /* !Nibblermvt_HPP_ */
