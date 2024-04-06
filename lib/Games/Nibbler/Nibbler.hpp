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
#include "Nibblermvt.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <tuple>
#include "../IGameModule.hpp"

class Nibbler : public Arcade::Games::IGameModule {

    class NibblerSprite : public Arcade::Games::ISprite {
        public:
            NibblerSprite(std::string path = "",
            Arcade::Games::Shape shape = Arcade::Games::Shape::RECTANGLE,
            Arcade::Games::Color color = Arcade::Games::Color::WHITE,
            Arcade::Games::Vector2i pos = {0, 0},
            Arcade::Games::Vector2i size = {0, 0},
            int rotation = 0,
            Arcade::Games::Vector2i direction = {0, 0})
                : _path(path),
                _shape(shape),
                _color(color),
                _pos(pos),
                _size(size),
                _rotation(rotation),
                _direction(direction) {};
            ~NibblerSprite() = default;

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
        Arcade::Games::Vector2i getMapSize(void) override;
        std::vector<std::vector<Arcade::Games::ISprite *>> getMap(void) override;
        std::string getScore(void) override;
        float getAnimationTime(void);
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> getTexts(void);
        void clearMap(void);

        void handle_mvt(std::map<Arcade::Games::KeyType, int> inputs);
        void load_map(void);
        void handle_collision_wall(void);
        bool thereIsWall(Arcade::Games::Vector2i pos);
    private:
        size_t _score;
        std::vector<std::vector<Arcade::Games::ISprite *>> _map;
        Arcade::Games::Vector2i _mapSize;
        float _animationTime;
        std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> _texts;
        bool _gameover;
        bool _win;
        Arcade::Games::Nibblermvt _snake;
        Arcade::Games::Vector2i _applePos;

        std::string _head_up = "assets/Graphics/head_up.png";
        std::string _head_down = "assets/Graphics/head_down.png";
        std::string _head_left = "assets/Graphics/head_left.png";
        std::string _head_right = "assets/Graphics/head_right.png";
        std::string _body = "assets/Graphics/body.png";
        std::string _tail = "assets/Graphics/tail.png";
        std::string _apple = "assets/Graphics/apple.png";
        std::string _wall = "assets/Graphics/wall.png";
        std::string _background = "assets/Graphics/background.png";

        std::string _map1 = "assets/Maps/map1.txt";
        std::string _map2 = "assets/Maps/map2.txt";
        std::string _map3 = "assets/Maps/map3.txt";

        int _mapIndex;
        std::vector<std::string> _maps;
        std::vector<Arcade::Games::Vector2i> _apples;
        std::vector<Arcade::Games::Vector2i> _walls;
};

#endif /* !NIBBLER_HPP_ */
