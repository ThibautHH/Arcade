/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibblermvt
*/

#include "Nibblermvt.hpp"

Arcade::Games::Nibblermvt::Nibblermvt()
{
    _direction = RIGHT;
    _speed = 100;
    _headPos = {8, 25};
    _bodyPos.push_back({7, 25});
    _bodyPos.push_back({6, 25});
    _bodyPos.push_back({5, 25});
    _bodyPos.push_back({4, 25});
}

void Arcade::Games::Nibblermvt::moveBody()
{
    for (int i = _bodyPos.size() - 1; i > 0; i--) {
        _bodyPos[i] = _bodyPos[i - 1];
    }
    _bodyPos[0] = _headPos;
}

void Arcade::Games::Nibblermvt::moveRight(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    moveBody();
    _headPos.x += 1;
}

void Arcade::Games::Nibblermvt::moveLeft(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    moveBody();
    _headPos.x -= 1;
}

void Arcade::Games::Nibblermvt::moveUp(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    moveBody();
    _headPos.y -= 1;
}

void Arcade::Games::Nibblermvt::moveDown(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    moveBody();
    _headPos.y += 1;
}

void Arcade::Games::Nibblermvt::addBodyPart()
{
    _bodyPos.push_back(_bodyPos[_bodyPos.size() - 1]);
}

void Arcade::Games::Nibblermvt::updateSnake(std::vector<std::vector<Arcade::Games::ISprite *>> map, float deltaTime)
{
    _speed++;
    if (_speed % 10 != 0)
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