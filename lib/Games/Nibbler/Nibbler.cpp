/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler() : _mapSize({0, 0}), _score(0), _animationTime(0)
{
}

void Nibbler::init(std::string args, size_t nb_args)
{

}

void Nibbler::close(void)
{

}

bool Nibbler::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    return true;
}

std::string Nibbler::getGameName(void)
{
    return "Nibbler";
}

Arcade::Games::Vector2i Nibbler::getMapSize(void)
{
    return _mapSize;
}

std::vector<std::vector<Arcade::Games::ISprite>> Nibbler::getMap(void)
{
    // return _map;
}

std::string Nibbler::getScore(void)
{
    return std::to_string(_score);
}

float Nibbler::getAnimationTime(void)
{
    return _animationTime;
}

std::vector<Arcade::Games::IText *> Nibbler::getTexts(void)
{
    return std::vector<Arcade::Games::IText *>();
}

extern "C" Arcade::Games::IGameModule *entryPoint(void)
{
    return new Nibbler();
}

extern "C" void deletePoint(Arcade::Games::IGameModule *entry)
{
    delete entry;
}
