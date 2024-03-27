/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include "../IDisplayModule.hpp"

Ncurses::Ncurses()
{
}

void Ncurses::init(void)
{
}

void Ncurses::close(void)
{
}

void Ncurses::clear(void)
{
}

std::map<Arcade::Displays::KeyType, int> Ncurses::getInputs(void) const
{
    return std::map<Arcade::Displays::KeyType, int>();
}

void Ncurses::setGameName(std::string name)
{
    _gameName = name;
}

void Ncurses::setMapSize(Arcade::Displays::Vector2i vector)
{
}

void Ncurses::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
}

void Ncurses::displayGame(void)
{
}

void Ncurses::setAnimationTime(float time)
{
}

float Ncurses::getDeltaT(void)
{
    return 0;
}

void Ncurses::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
}
