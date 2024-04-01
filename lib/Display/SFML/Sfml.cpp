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
: _gameName(nullptr), _score(0)
{
}

void Sfml::init(void)
{
    _window.create(sf::VideoMode(800, 600), "Arcade");
    _window.setFramerateLimit(60);
}

void Sfml::close(void)
{
    _window.close();
}

void Sfml::clear(void)
{
    _window.clear(sf::Color::Black);
}

std::map<Arcade::Displays::KeyType, int> Sfml::getInputs(void)
{
    return _inputs;
}

void Sfml::setGameName(std::string name)
{
    _gameName = name;
}

void Sfml::setMapSize(Arcade::Displays::Vector2i vector)
{
    _map.resize(vector.y);
    for (int i = 0; i < vector.y; i++) {
        _map[i].resize(vector.x);
    }
}

void Sfml::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
    _map[vector.y][vector.x] = sprite;
}

void Sfml::displayGame(void)
{
    sf::Texture _texture;
    sf::Sprite _sprite;

    for (long unsigned int i = 0; i < _map.size(); i++) {
        for (long unsigned int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] != nullptr) {
                _texture.loadFromFile(_map[i][j]->getPath());
                _sprite.setTexture(_texture);
                _sprite.setPosition(j * 32, i * 32);
                _window.draw(_sprite);
            }
        }
    }
    _window.draw(_text);
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
    switch(color) {
        case Arcade::Displays::Color::WHITE:
            _text.setFillColor(sf::Color::White);
            break;
        case Arcade::Displays::Color::RED:
            _text.setFillColor(sf::Color::Red);
            break;
        case Arcade::Displays::Color::GREEN:
            _text.setFillColor(sf::Color::Green);
            break;
        case Arcade::Displays::Color::BLUE:
            _text.setFillColor(sf::Color::Blue);
            break;
        case Arcade::Displays::Color::YELLOW:
            _text.setFillColor(sf::Color::Yellow);
            break;
        case Arcade::Displays::Color::MAGENTA:
            _text.setFillColor(sf::Color::Magenta);
            break;
        case Arcade::Displays::Color::CYAN:
            _text.setFillColor(sf::Color::Cyan);
            break;
        case Arcade::Displays::Color::BLACK:
            _text.setFillColor(sf::Color::Black);
            break;
        default:
            _text.setFillColor(sf::Color::White);
            break;
    }
    _font.loadFromFile("../../../assets/arial.ttf");
    _text.setFont(_font);
    _text.setString(text);
    _text.setCharacterSize(24);
    _text.setPosition(pos.x, pos.y);
}

extern "C" Arcade::Displays::IDisplayModule *entryPoint()
{
    return new Sfml();
}

extern "C" void deletePoint(Arcade::Displays::IDisplayModule *entry)
{
    delete entry;
}
