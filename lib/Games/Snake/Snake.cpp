/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

Snake::Snake() : _mapSize({0, 0}), _score(0), _animationTime(0)
{
}


void Snake::init(std::string args, size_t nb_args)
{

}

void Snake::close(void)
{

}

bool Snake::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{

}

std::string Snake::getGameName(void)
{
    return "Snake";
}

Arcade::Games::Vector2i Snake::getMapSize(void)
{
}

std::vector<std::vector<Arcade::Games::ISprite>> Snake::getMap(void)
{
}

std::string Snake::getScore(void)
{
    return std::to_string(_score);
}

float Snake::getAnimationTime(void)
{
}

std::vector<Arcade::Games::IText *> getTexts(void)
{

}
