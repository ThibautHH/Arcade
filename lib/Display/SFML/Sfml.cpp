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

std::map<Arcade::Displays::KeyType, int> Sfml::getInputs(void)
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::QUIT, 1}};
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::VER, -1}};
                    case sf::Keyboard::Down:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::VER, 1}};
                    case sf::Keyboard::Left:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::HOR, -1}};
                    case sf::Keyboard::Right:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::HOR, 1}};
                    case sf::Keyboard::Space:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::ACTION1, 1}};
                    case sf::Keyboard::Return:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::ACTION2, 1}};
                    case sf::Keyboard::Escape:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::ESC, 1}};
                    case sf::Keyboard::R:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::RESTART, 1}};
                    case sf::Keyboard::N:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::NEXT_LIB, 1}};
                    case sf::Keyboard::P:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::PREV_LIB, 1}};
                    case sf::Keyboard::M:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::NEXT_GAME, 1}};
                    case sf::Keyboard::L:
                        return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::PREV_GAME, 1}};
                    default:
                        break;
            }
            default:
                break;
        }
    }
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

    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
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
    if (color == Arcade::Displays::Color::WHITE)
        _text.setFillColor(sf::Color::White);
    else if (color == Arcade::Displays::Color::RED)
        _text.setFillColor(sf::Color::Red);
    else if (color == Arcade::Displays::Color::GREEN)
        _text.setFillColor(sf::Color::Green);
    else if (color == Arcade::Displays::Color::BLUE)
        _text.setFillColor(sf::Color::Blue);
    else if (color == Arcade::Displays::Color::YELLOW)
        _text.setFillColor(sf::Color::Yellow);
    else if (color == Arcade::Displays::Color::MAGENTA)
        _text.setFillColor(sf::Color::Magenta);
    else if (color == Arcade::Displays::Color::CYAN)
        _text.setFillColor(sf::Color::Cyan);
    else if (color == Arcade::Displays::Color::BLACK)
        _text.setFillColor(sf::Color::Black);
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
