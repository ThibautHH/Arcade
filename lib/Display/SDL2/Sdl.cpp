/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl
*/

#include "Sdl.hpp"

Sdl::Sdl()
{
}

void Sdl::init(void)
{
}

void Sdl::close(void)
{
}

void Sdl::clear(void)
{
}

std::map<Arcade::Displays::KeyType, int> Sdl::getInputs(void) const
{
    return std::map<Arcade::Displays::KeyType, int>();
}

void Sdl::setGameName(std::string name)
{
    _gameName = name;
}

void Sdl::setMapSize(Arcade::Displays::Vector2i vector)
{
}

void Sdl::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
}

void Sdl::displayGame(void)
{
}

void Sdl::setAnimationTime(float time)
{
}

float Sdl::getDeltaT(void)
{
    return 0;
}

void Sdl::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
}
