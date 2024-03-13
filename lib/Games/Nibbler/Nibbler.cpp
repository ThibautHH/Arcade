/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
: _score(0)
{
}

void Nibbler::loadMap()
{
    std::cout << "Nibbler loadMap" << std::endl;
}

size_t Nibbler::getScore()
{
    return _score;
}

void Nibbler::setScore(size_t score)
{
    _score = score;
}

Arcade::Data Nibbler::tick()
{
    std::cout << "Nibbler tick" << std::endl;
    return Arcade::Data();
}
