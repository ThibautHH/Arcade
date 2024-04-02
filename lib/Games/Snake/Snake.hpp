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

    // class Sprite : public Arcade::Games::ISprite {
    //     public:
    //         Sprite(std::string path, Arcade::Games::Shape shape, Arcade::Games::Color color, Arcade::Games::Vector2i pos, Arcade::Games::Vector2i size, int rotation = 0, Arcade::Games::Vector2i direction = {0, 0})
    //             : _path(path), _shape(shape), _color(color), _pos(pos), _size(size), _rotation(rotation), _direction(direction) {};
    //         ~Sprite() = default;

    //         void setPath(std::string path) { _path = path; }
    //         std::string getPath(void) { return _path; }

    //         void setShape(Arcade::Games::Shape shape) { _shape = shape; };
    //         Arcade::Games::Shape getShape(void) { return _shape; };

    //         void setColor(Arcade::Games::Color color) { _color = color; };
    //         Arcade::Games::Color getColor(void) { return _color; };

    //         void setPos(Arcade::Games::Vector2i pos) { _pos = pos; };
    //         Arcade::Games::Vector2i getPos(void) { return _pos; };

    //         void setSize(Arcade::Games::Vector2i size) { _size = size; };
    //         Arcade::Games::Vector2i getSize(void) { return _size; };

    //         void setRotation(int rotation) { _rotation = rotation; };
    //         int getRotation(void) { return _rotation; };

    //         void setDirection(Arcade::Games::Vector2i direction) { _direction = direction; };
    //         Arcade::Games::Vector2i getDirection(void) { return _direction; };

    //     private:
    //         std::string _path;
    //         Arcade::Games::Shape _shape;
    //         Arcade::Games::Color _color;
    //         Arcade::Games::Vector2i _pos;
    //         Arcade::Games::Vector2i _size;
    //         int _rotation;
    //         Arcade::Games::Vector2i _direction;
    // };

    public:
        Snake();
        ~Snake() = default;

        void init(std::string args, size_t nb_args) override;
        void close(void) override;
        bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT) override;
        std::string getGameName(void) override;
        Arcade::Games::Vector2i getMapSize(void) override;
        // std::vector<std::vector<Arcade::Games::ISprite>> getMap(void) override;
        std::string getScore(void) override;
        float getAnimationTime(void);
        std::vector<Arcade::Games::IText *> getTexts(void);
    private:
        size_t _score;
        // std::vector<std::vector<Arcade::Games::ISprite>> _map;
        Arcade::Games::Vector2i _mapSize;
        float _animationTime;
        std::vector<Arcade::Games::IText *> _texts;

};

#endif /* !SNAKE_HPP_ */
