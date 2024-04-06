/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snakemvt
*/

#include "Snakemvt.hpp"

Arcade::Games::Snakemvt::Snakemvt()
{
    _direction = RIGHT;
    _speed = 100;
    _headPos = {8, 8};
    _bodyPos.push_back({7, 8});
    _bodyPos.push_back({6, 8});
    _bodyPos.push_back({5, 8});
    _bodyPos.push_back({4, 8});
}

void Arcade::Games::Snakemvt::moveBody()
{
    for (int i = _bodyPos.size() - 1; i > 0; i--) {
        _bodyPos[i] = _bodyPos[i - 1];
    }
    _bodyPos[0] = _headPos;
}

void Arcade::Games::Snakemvt::moveRight(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    moveBody();
    _headPos.x += 1;
}

void Arcade::Games::Snakemvt::moveLeft(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    moveBody();
    _headPos.x -= 1;
}

void Arcade::Games::Snakemvt::moveUp(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    moveBody();
    _headPos.y -= 1;
}

void Arcade::Games::Snakemvt::moveDown(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    moveBody();
    _headPos.y += 1;
}

void Arcade::Games::Snakemvt::addBodyPart()
{
    _bodyPos.push_back(_bodyPos[_bodyPos.size() - 1]);
}

void Arcade::Games::Snakemvt::updateSnake(std::vector<std::vector<Arcade::Games::ISprite *>> map, float deltaTime)
{
    _speed += deltaTime * 1000;
    if (_speed < 25)
        return;
    _speed = 0;
    switch (_direction) {
        case RIGHT:
            moveRight(map);
            break;
        case LEFT:
            moveLeft(map);
            break;
        case UP:
            moveUp(map);
            break;
        case DOWN:
            moveDown(map);
            break;
    }
}