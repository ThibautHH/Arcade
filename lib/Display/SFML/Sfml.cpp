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
    _window.create(sf::VideoMode(800, 600), "Arcade");
    _window.setFramerateLimit(60);
    _score = 0;
}

void Sfml::close(void)
{
    _window.close();
}

void Sfml::clear(void)
{
    _window.clear(sf::Color::Black);
}

std::map<Arcade::Displays::KeyType, int> Sfml::getInputs(void) const
{
    return _inputs;
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
    _texture.loadFromFile(sprite->getPath());
    _sprite.setTexture(_texture);
    _sprite.setPosition(vector.x, vector.y);
}

void Sfml::displayGame(void)
{
    _window.draw(_sprite);
    _window.display();
}

void Sfml::setAnimationTime(float time)
{
    (void) time;
}

float Sfml::getDeltaT(void)
{
    return 0;
}

void Sfml::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
}

extern "C" Arcade::Displays::IDisplayModule *entryPoint()
{
    return new Sfml();
}

extern "C" void deletePoint(Arcade::Displays::IDisplayModule *entry)
{
    delete entry;
}
