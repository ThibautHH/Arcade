/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"


Snake::Snake()
: _score(0)
{
}

void Snake::loadMap()
{
    std::cout << "Snake loadMap" << std::endl;
}

size_t Snake::getScore()
{
    return _score;
}

void Snake::setScore(size_t score)
{
    _score = score;
}
