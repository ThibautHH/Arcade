/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include <unistd.h>

static std::map<Arcade::Displays::Color,sf::Color> colors = {
    {Arcade::Displays::Color::BLACK, sf::Color::White},
    {Arcade::Displays::Color::WHITE, sf::Color::White},
    {Arcade::Displays::Color::RED, sf::Color::Red},
    {Arcade::Displays::Color::GREEN, sf::Color::Green},
    {Arcade::Displays::Color::BLUE, sf::Color::Blue},
    {Arcade::Displays::Color::YELLOW, sf::Color::Yellow},
    {Arcade::Displays::Color::MAGENTA, sf::Color::Magenta},
    {Arcade::Displays::Color::CYAN, sf::Color::Cyan},
    {Arcade::Displays::Color::DEFAULT, sf::Color::White}
};

static const std::size_t font_size = 24;

void Sfml::init(void)
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Titlebar | sf::Style::Close);
    _window.setFramerateLimit(60);

    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>();
    _mapSize = Arcade::Displays::Vector2i(0, 0);

    if (!_font.loadFromFile("assets/arial.ttf"))
        throw std::runtime_error("Could not load font");
    _text.setFont(_font);
    _text.setCharacterSize(font_size);
    _text.setFillColor(sf::Color::White);
    _text.setString("Hello World");
}

void Sfml::close(void)
{
    _window.close();
}

void Sfml::clear(void)
{
    _texts.clear();
    _window.clear();
}

std::map<Arcade::Displays::KeyType, int> Sfml::getInputs(void)
{
    std::map<Arcade::Displays::KeyType, int> inputs;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        inputs[Arcade::Displays::KeyType::VER] = 1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        inputs[Arcade::Displays::KeyType::VER] = -1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        inputs[Arcade::Displays::KeyType::HOR] = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        inputs[Arcade::Displays::KeyType::HOR] = 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        inputs[Arcade::Displays::KeyType::PREV_LIB] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        inputs[Arcade::Displays::KeyType::NEXT_LIB] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        inputs[Arcade::Displays::KeyType::PREV_GAME] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        inputs[Arcade::Displays::KeyType::NEXT_GAME] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        inputs[Arcade::Displays::KeyType::ACTION1] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        inputs[Arcade::Displays::KeyType::ACTION2] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        inputs[Arcade::Displays::KeyType::ACTION3] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        inputs[Arcade::Displays::KeyType::ACTION4] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        inputs[Arcade::Displays::KeyType::QUIT] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        inputs[Arcade::Displays::KeyType::ESC] = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        inputs[Arcade::Displays::KeyType::RESTART] = 1;

    return inputs;
}

void Sfml::setMapSize(Arcade::Displays::Vector2i vector)
{
    if (_mapSize.x == vector.x && _mapSize.y == vector.y)
        return;
    _mapSize = vector;

    _map.reserve(_mapSize.y);
    for (int i = 0; i < _mapSize.y; i++) {
        _map.emplace(_map.begin() + i);
        _map[i].reserve(_mapSize.x);
        for (int j = 0; j < _mapSize.x; j++) {
            _map[i].emplace(_map[i].begin() + j, nullptr);
        }
    }
}

void Sfml::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
    if (vector.x < 0 || vector.y < 0 || vector.x >= _mapSize.x || vector.y >= _mapSize.y)
        return;
    _map.at(vector.y).at(vector.x) = sprite;
}

void Sfml::displayGame(void)
{
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::RectangleShape _rect;
    sf::CircleShape _circle;
    sf::ConvexShape _triangle;

    _rect.setSize(sf::Vector2f(32, 32));
    _circle.setRadius(16);
    _triangle.setPointCount(3);

    for (long unsigned int i = 0; i < _map.size(); i++) {
        for (long unsigned int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == nullptr)
                continue;
            if (_map[i][j]->getShape() == Arcade::Displays::Shape::RECTANGLE) {
                _rect.setPosition(j * 32, i * 32);
                _rect.setFillColor(colors[_map[i][j]->getColor()]);
                _window.draw(_rect);
            }
            if (_map[i][j]->getShape() == Arcade::Displays::Shape::CIRCLE) {
                _circle.setPosition(j * 32, i * 32);
                _circle.setFillColor(colors[_map[i][j]->getColor()]);
                _window.draw(_circle);
            }
            if (_map[i][j]->getShape() == Arcade::Displays::Shape::TRIANGLE) {
                _triangle.setPoint(0, sf::Vector2f(j * 32, i * 32));
                _triangle.setPoint(1, sf::Vector2f(j * 32 + 32, i * 32));
                _triangle.setPoint(2, sf::Vector2f(j * 32 + 16, i * 32 + 32));
                _triangle.setFillColor(colors[_map[i][j]->getColor()]);
                _window.draw(_triangle);
            }
        }
    }
    for (auto text : _texts) {
        _text.setString(std::get<1>(text));
        _text.setCharacterSize(font_size);
        _text.setPosition(std::get<0>(text).x * font_size, std::get<0>(text).y * font_size);
        _text.setFillColor(colors[std::get<2>(text)]);
        _window.draw(_text);
    }
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
    _texts.push_back(std::make_tuple(pos, text, color));
}

extern "C" Arcade::Displays::IDisplayModule *displayEntryPoint(void)
{
    return new Sfml();
}

extern "C" void deletePoint(Arcade::Displays::IDisplayModule *entry)
{
    delete entry;
}
