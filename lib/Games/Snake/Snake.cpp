/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

Snake::Snake()
: _mapSize({0, 0}), _score(0), _animationTime(0)
{
    // _map.resize(_mapSize.y);
    // for (int i = 0; i < _mapSize.y; i++)
    //     _map[i].resize(_mapSize.x);
}

void Snake::init(std::string args, size_t nb_args)
{
    // _map[8][10] = Snake::Sprite("../../../assets/Snake/Apple.png", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::RED, {8, 10}, {1, 1});
    // _map[8][8] = Snake::Sprite("../../../assets/Snake/Head.png", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 8}, {1, 1});
    // _map[8][7] = Snake::Sprite("../../../assets/Snake/Body.png", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 7}, {1, 1});
    // _map[8][6] = Snake::Sprite("../../../assets/Snake/Body.png", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 6}, {1, 1});
    // _map[8][5] = Snake::Sprite("../../../assets/Snake/Tail.png", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 5}, {1, 1});
}

void Snake::close(void)
{
}

bool Snake::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    // (void) deltaT;

    // for (int i = 0; i < _mapSize.y; i++)
    //     for (int j = 0; j < _mapSize.x; j++)
    //         if (inputs[Arcade::Games::KeyType::VER] == 1)
    //             if (_map[i][j].getPath() == "../../../assets/Snake/Head.png") {
    //                 _map[i + 1][j].setPath("../../../assets/Snake/Head.png");
    //             }
    //         else if (inputs[Arcade::Games::KeyType::VER] == -1)
    //             if (_map[i][j].getPath() == "../../../assets/Snake/Head.png") {
    //                 _map[i - 1][j].setPath("../../../assets/Snake/Head.png");
    //             }
    //         else if (inputs[Arcade::Games::KeyType::HOR] == 1)
    //             if (_map[i][j].getPath() == "../../../assets/Snake/Head.png") {
    //                 _map[i][j + 1].setPath("../../../assets/Snake/Head.png");
    //             }
    //         else if (inputs[Arcade::Games::KeyType::HOR] == -1)
    //             if (_map[i][j].getPath() == "../../../assets/Snake/Head.png") {
    //                 _map[i][j - 1].setPath("../../../assets/Snake/Head.png");
    //             }
    // return true;
}

std::string Snake::getGameName(void)
{
    return "Snake";
}

Arcade::Games::Vector2i Snake::getMapSize(void)
{
    return _mapSize;
}

std::vector<std::vector<Arcade::Games::ISprite>> Snake::getMap(void)
{
    // return _map;
}

std::string Snake::getScore(void)
{
    return std::to_string(_score);
}

float Snake::getAnimationTime(void)
{
    return _animationTime;
}

std::vector<Arcade::Games::IText *> Snake::getTexts(void)
{
    return std::vector<Arcade::Games::IText *>();
}

extern "C" Arcade::Games::IGameModule *entryPoint()
{
    return new Snake();
}

extern "C" void deletePoint(Arcade::Games::IGameModule *entry)
{
    delete entry;
}
