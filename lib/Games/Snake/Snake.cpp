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
    _map.resize(_mapSize.y);
    for (int i = 0; i < _mapSize.y; i++)
        _map[i].resize(_mapSize.x);

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            _map[i][j] = new SnakeSprite("", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::DEFAULT, {i, j}, {1, 1});
        }
    }
}

void Snake::init(std::string args, size_t nb_args)
{
    _map[8][10] = new SnakeSprite(_apple, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::RED, {8, 10}, {1, 1});
    _map[8][8] = new SnakeSprite(_head_right, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 8}, {1, 1});
    _map[8][7] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 7}, {1, 1});
    _map[8][6] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 6}, {1, 1});
    _map[8][5] = new SnakeSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 5}, {1, 1});
}

void Snake::close(void)
{
    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            delete _map[i][j];
        }
    }
}

void Snake::generateApple(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    int x = rand() % _mapSize.x;
    int y = rand() % _mapSize.y;

    if (map[y][x]->getPath() == "") {
        map[y][x] = new SnakeSprite(_apple, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::RED, {y, x}, {1, 1});
    } else
        generateApple(map);
}

void Snake::AddSnakeLength(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction)
{
    Arcade::Games::Vector2i tailPos;
    Arcade::Games::Vector2i bodyPos;

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            if (map[i][j]->getPath() == _tail) {
                tailPos = {i, j};
                bodyPos = {i - direction.y, j - direction.x};
                if (map[tailPos.y][tailPos.x]->getPath() == _tail) {
                    map[tailPos.y][tailPos.x] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, tailPos, {1, 1});
                    map[bodyPos.y][bodyPos.x] = new SnakeSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, bodyPos, {1, 1});
                } else {
                    map[tailPos.y][tailPos.x] = new SnakeSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, tailPos, {1, 1});
                }
                return;
            }
        }
    }
}

void Snake::moveSnake(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction)
{
    Arcade::Games::Vector2i headPos;
    Arcade::Games::Vector2i nextPos;

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            if (map[i][j]->getPath() == _head_right) {
                headPos = {i, j};
                nextPos = {i + direction.y, j + direction.x};
                if (map[nextPos.y][nextPos.x]->getPath() == _apple) {
                    map[nextPos.y][nextPos.x] = new SnakeSprite(_head_right, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, nextPos, {1, 1});
                                   map[headPos.y][headPos.x] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, headPos, {1, 1});
     map[headPos.y][headPos.x] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, headPos, {1, 1});
                    AddSnakeLength(map, direction);
                    _score++;
                    generateApple(map);
                } else if (map[nextPos.y][nextPos.x]->getPath() == _body) {
                    _score = 0;
                    // reset game / game over
                } else {
                    map[nextPos.y][nextPos.x] = new SnakeSprite(_head_right, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, nextPos, {1, 1});
                    map[headPos.y][headPos.x] = new SnakeSprite("", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, headPos, {1, 1});
                }
                return;
            }
        }
    }
}

void Snake::checkWallCollision(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            if (map[i][j]->getPath() == _head_right) {
                if (i < 0 || i >= _mapSize.y || j < 0 || j >= _mapSize.x) {
                    _score = 0;
                    // reset game / game over
                }
            }
        }
    }
}

void Snake::checkApple(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    int check = 0;

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            if (map[i][j]->getPath() == _apple)
                check++;
            if (map[i][j]->getPath() == _head_right) {
                if (map[i][j]->getPath() == _apple) {
                    _score++;
                    generateApple(map);
                }
            }
        }
    }
    if (check == 0) {
        // reset game / game over
    }
}

bool Snake::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    (void) deltaT;

    if (inputs[Arcade::Games::KeyType::VER] == 1)
        moveSnake(_map, {0, -1});
    if (inputs[Arcade::Games::KeyType::VER] == -1)
        moveSnake(_map, {0, 1});
    if (inputs[Arcade::Games::KeyType::HOR] == 1)
        moveSnake(_map, {1, 0});
    if (inputs[Arcade::Games::KeyType::HOR] == -1)
        moveSnake(_map, {-1, 0});
    checkWallCollision(_map);
    checkApple(_map);
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
