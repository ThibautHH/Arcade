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
: _window(sf::VideoMode(1920, 1080), "Arcade")
{
    _window.setFramerateLimit(60);
}

void Sfml::init(void)
{
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
                if (_textures.find(_map[i][j]->getPath()) == _textures.end()) {
                    _texture = _textures[_map[i][j]->getPath()];
                    _sprite.setTexture(_texture);
                    _sprite.setPosition(j * 32, i * 32);
                    _window.draw(_sprite);
                } else {
                    _texture.loadFromFile(_map[i][j]->getPath());
                    _textures[_map[i][j]->getPath()] = _texture;
                    _sprite.setTexture(_texture);
                    _sprite.setPosition(j * 32, i * 32);
                    _window.draw(_sprite);
                }
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

extern "C" Arcade::Displays::IDisplayModule *entryPoint(void)
{
    return new Sfml();
}

extern "C" void deletePoint(Arcade::Displays::IDisplayModule *entry)
{
    delete entry;
}
