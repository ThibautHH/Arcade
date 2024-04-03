/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <stdio.h>
#include <iostream>
#include "../IGameModule.hpp"

class Nibbler : public Arcade::Games::IGameModule {

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
        Nibbler();
        ~Nibbler() = default;

        void init(std::string args, size_t nb_args) override;
        void close(void) override;
        bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT) override;
        std::string getGameName(void) override;
        Arcade::Games::Vector2i getMapSize(void) override;
        std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void) override;
        std::string getScore(void) override;
        float getAnimationTime(void);
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> getTexts(void);
    private:
        size_t _score;
        std::vector<std::vector<Arcade::Games::ISprite *>> _map;
        Arcade::Games::Vector2i _mapSize;
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> _texts;
        float _animationTime;
};

#endif /* !NIBBLER_HPP_ */
