/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"


Pacman::Pacman()
: _score(0)
{
}

void Pacman::loadMap()
{
    std::cout << "Pacman loadMap" << std::endl;
}

size_t Pacman::getScore()
{
    return _score;
}

void Pacman::setScore(size_t score)
{
    _score = score;
}

Arcade::Data Pacman::tick()
{
    std::cout << "Pacman tick" << std::endl;
    return Arcade::Data();
}