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

void Nibbler::init(void)
{

}

void Nibbler::close(void)
{

}

void Nibbler::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{

}

std::string Nibbler::getGameName(void)
{
    return "Nibbler";
}

Arcade::Games::Vector2i Nibbler::getMapSize(void)
{
}

std::vector<std::vector<Arcade::Games::ISprite>> Nibbler::getMap(void)
{
}

unsigned int Nibbler::getScore(void)
{
    return _score;
}

float Nibbler::getAnimationTime(void)
{
}

std::vector<Arcade::Games::IText *> getTexts(void)
{

}