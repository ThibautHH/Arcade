/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <stdio.h>
#include <iostream>
#include "../IGameModule.hpp"

class Snake : public Arcade::Games::IGameModule {

    class SnakeSprite : public Arcade::Games::ISprite {
        public:
            SnakeSprite(std::string path = "",
            Arcade::Games::Shape shape = Arcade::Games::Shape::RECTANGLE,
            Arcade::Games::Color color = Arcade::Games::Color::WHITE,
            Arcade::Games::Vector2i pos = {0, 0},
            Arcade::Games::Vector2i size = {0, 0},
            int rotation = 0,
            Arcade::Games::Vector2i direction = {0, 0})
                : _path(_path),
                _shape(shape),
                _color(color),
                _pos(pos),
                _size(size),
                _rotation(rotation),
                _direction(direction) {};
            ~SnakeSprite() = default;

            void setPath(std::string path) { _path = path; }
            std::string getPath(void) { return _path; }

            void setRotation(int rotation) { _rotation = rotation; };
            int getRotation(void) { return _rotation; };

            void setDirection(Arcade::Games::Vector2i direction) { _direction = direction; };
            Arcade::Games::Vector2i getDirection(void) { return _direction; };

            void setShape(Arcade::Games::Shape shape) { _shape = shape; };
            Arcade::Games::Shape getShape(void) { return _shape; };

            void setColor(Arcade::Games::Color color) { _color = color; };
            Arcade::Games::Color getColor(void) { return _color; };

        private:
            std::string _path;
            Arcade::Games::Shape _shape;
            Arcade::Games::Color _color;
            Arcade::Games::Vector2i _pos;
            Arcade::Games::Vector2i _size;
            int _rotation;
            Arcade::Games::Vector2i _direction;
    };

    public:
        Snake();
        ~Snake() = default;

        void init(std::string args, size_t nb_args) override;
        void close(void) override;
        bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT) override;
        Arcade::Games::Vector2i getMapSize(void) override;
        std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void) override;
        std::string getScore(void) override;
        float getAnimationTime(void);
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> getTexts(void);

        void generateApple(std::vector<std::vector<Arcade::Games::ISprite *>> map);
        void moveSnake(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction);
        void checkWallCollision(std::vector<std::vector<Arcade::Games::ISprite *>> map);
        void checkApple(std::vector<std::vector<Arcade::Games::ISprite *>> map);
        void AddSnakeLength(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction);

    private:
        size_t _score;
        std::vector<std::vector<Arcade::Games::ISprite *>> _map;
        Arcade::Games::Vector2i _mapSize;
        float _animationTime;
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> _texts;

        std::string _head_up = "../../../assets/snake/head_up.png";
        std::string _head_down = "../../../assets/snake/head_down.png";
        std::string _head_left = "../../../assets/snake/head_left.png";
        std::string _head_right = "../../../assets/snake/head_right.png";
        std::string _body = "../../../assets/snake/body.png";
        std::string _tail = "../../../assets/snake/tail.png";
        std::string _apple = "../../../assets/snake/apple.png";

};
#endif /* !SNAKE_HPP_ */
