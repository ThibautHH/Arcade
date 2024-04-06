/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"


Snake::Snake()
: _mapSize({18, 16}), _score(0), _animationTime(0)
{
    _win = false;
    _gameover = false;
    _map.reserve(_mapSize.y);
    for (int i = 0; i < _mapSize.y; i++) {
        _map.emplace(_map.begin() + i);
        _map[i].reserve(_mapSize.x);
        for (int j = 0; j < _mapSize.x; j++) {
            _map[i].emplace(_map[i].begin() + j, nullptr);
        }
    }
}

void Snake::init(std::string args, size_t nb_args)
{
    (void) args;
    (void) nb_args;

    _texts.push_back(std::make_tuple("Score: ", Arcade::Games::Vector2i{0, 0}, Arcade::Games::Color::WHITE));
    _texts.push_back(std::make_tuple(getScore(), Arcade::Games::Vector2i{7, 0}, Arcade::Games::Color::WHITE));

    _applePos = {8, 10};
    _timedApplePos = {8, 5};
}

void Snake::close(void)
{
    for (int i = 0; i < _mapSize.y; i++)
        for (int j = 0; j < _mapSize.x; j++)
            if (_map[i][j] != nullptr)
                delete _map[i][j];
}

void Snake::clearMap(void)
{
    for (int i = 0; i < _mapSize.y; i++)
        for (int j = 0; j < _mapSize.x; j++)
            if (_map[i][j] != nullptr) {
                delete _map[i][j];
                _map[i][j] = nullptr;
            }
}

void Snake::handle_mvt(std::map<Arcade::Games::KeyType, int> inputs)
{
    if (inputs[Arcade::Games::KeyType::VER] == 1 && _snake.getDirection() != Arcade::Games::Direction::DOWN)
        _snake.setDirection(Arcade::Games::Direction::UP);
    if (inputs[Arcade::Games::KeyType::VER] == -1 && _snake.getDirection() != Arcade::Games::Direction::UP)
        _snake.setDirection(Arcade::Games::Direction::DOWN);
    if (inputs[Arcade::Games::KeyType::HOR] == 1 && _snake.getDirection() != Arcade::Games::Direction::LEFT)
        _snake.setDirection(Arcade::Games::Direction::RIGHT);
    if (inputs[Arcade::Games::KeyType::HOR] == -1 && _snake.getDirection() != Arcade::Games::Direction::RIGHT)
        _snake.setDirection(Arcade::Games::Direction::LEFT);
}

void Snake::generateApple(bool force)
{
    int x = rand() % _mapSize.x;
    int y = rand() % _mapSize.y;

    for (int i = 0; i < _mapSize.y; i++)
        for (int j = 0; j < _mapSize.x; j++) {
            if (_map[i][j] == nullptr)
                continue;
            if (_map[i][j]->getColor() == Arcade::Games::Color::RED && force == false)
                return;
        }
    if (_map[y][x] == nullptr)
        _applePos = {x, y};
    else
        generateApple();
}

void Snake::generateTimedApple(float deltaT)
{
    int x = rand() % _mapSize.x;
    int y = rand() % _mapSize.y;

    for (int i = 0; i < _mapSize.y; i++)
        for (int j = 0; j < _mapSize.x; j++) {
            if (_map[i][j] == nullptr)
                continue;
            if (_map[i][j]->getColor() == Arcade::Games::Color::YELLOW) {
                _appleTimer += deltaT * 100;
                if (_appleTimer >= 50) {
                    _appleTimer = 0;
                    _map[i][j] = nullptr;
                    generateTimedApple(deltaT);
                }
                return;
            }
        }
    if (_map[y][x] == nullptr)
        _timedApplePos = {x, y};
    else
        generateTimedApple(deltaT);
}

std::string Snake::getHeadDirection(void)
{
    switch (_snake.getDirection()) {
        case Arcade::Games::Direction::UP:
            return _head_up;
        case Arcade::Games::Direction::DOWN:
            return _head_down;
        case Arcade::Games::Direction::LEFT:
            return _head_left;
        case Arcade::Games::Direction::RIGHT:
            return _head_right;
        default:
            return _head_up;
    }
}

bool Snake::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    if (_gameover) {
        _texts[1] = std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>("Game Over", {7, 1}, Arcade::Games::Color::WHITE);
        return false;
    }
    clearMap();
    handle_mvt(inputs);
    _snake.updateSnake(_map, deltaT);
    if (_snake.getHeadPos().x < 0 || _snake.getHeadPos().x >= _mapSize.x || _snake.getHeadPos().y < 0 || _snake.getHeadPos().y >= _mapSize.y) {
        _gameover = true;
        return false;
    }
    GET_HEAD_TILE(_map, _snake) = new SnakeSprite(getHeadDirection(), Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::MAGENTA, _snake.getHeadPos(), {1, 1});
    for (int i = 0; i < _snake.getBodyPos().size(); i++)
        _map[_snake.getBodyPos()[i].y][_snake.getBodyPos()[i].x] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, _snake.getBodyPos()[i], {1, 1});
    _map[_applePos.y][_applePos.x] = NEW_APPLE_SPRITE(_apple, Arcade::Games::Color::RED, _applePos);
    _map[_timedApplePos.y][_timedApplePos.x] = NEW_APPLE_SPRITE(_apple, Arcade::Games::Color::YELLOW, _timedApplePos);
    if (GET_HEAD_TILE(_map, _snake) != nullptr && GET_HEAD_COLOR(_map, _snake) == Arcade::Games::Color::RED) {
        _score++;
        _snake.addBodyPart();
        generateApple(true);
    }
    if (GET_HEAD_TILE(_map, _snake) != nullptr && GET_HEAD_COLOR(_map, _snake) == Arcade::Games::Color::YELLOW) {
        _score += 5;
        _snake.addBodyPart();
        _map[_timedApplePos.y][_timedApplePos.x] = nullptr;
        _appleTimer = 0;
    }
    if (GET_HEAD_TILE(_map, _snake) != nullptr && GET_HEAD_COLOR(_map, _snake) == Arcade::Games::Color::GREEN) {
        _gameover = true;
        return false;
    }
    generateApple();
    generateTimedApple(deltaT);
    _texts[1] = std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>(getScore(), {7, 0}, Arcade::Games::Color::WHITE);
    return true;
}

Arcade::Games::Vector2i Snake::getMapSize(void)
{
    return _mapSize;
}

std::vector<std::vector<Arcade::Games::ISprite *>> Snake::getMap(void)
{
    return _map;
}

std::string Snake::getScore(void)
{
    return std::to_string(_score);
}

float Snake::getAnimationTime(void)
{
    return _animationTime;
}

std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> Snake::getTexts(void)
{
    return _texts;
}

extern "C" Arcade::Games::IGameModule *gameEntryPoint(void)
{
    return new Snake();
}

extern "C" void deletePoint(Arcade::Games::IGameModule *entry)
{
    delete entry;
}
