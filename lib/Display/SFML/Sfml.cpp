/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

Sfml::Sfml()
{
}

void Sfml::init(void)
{
}

void Sfml::close(void)
{
}

void Sfml::clear(void)
{
}

std::map<Arcade::Displays::KeyType, int> Sfml::getInputs(void) const
{
    return std::map<Arcade::Displays::KeyType, int>();
}

void Sfml::setGameName(std::string name)
{
    _gameName = name;
}

void Sfml::setMapSize(Arcade::Displays::Vector2i vector)
{
}

void Sfml::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
}

void Sfml::displayGame(void)
{
}

void Sfml::displayMenu(void)
{
}

void Sfml::setAnimationTime(float time)
{
}

float Sfml::getDeltaT(void)
{
    return 0;
}

void Sfml::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
}
