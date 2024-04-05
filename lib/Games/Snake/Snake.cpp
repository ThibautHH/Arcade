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
    _map.resize(_mapSize.y);
    for (int i = 0; i < _mapSize.y; i++)
        _map[i].resize(_mapSize.x);
}

void Snake::init(std::string args, size_t nb_args)
{
    (void) args;
    (void) nb_args;

    _map[8][10] = new SnakeSprite(_apple, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::RED, {8, 10}, {1, 1});
    _map[8][8] = new SnakeSprite(_head_right, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 8}, {1, 1});
    _map[8][7] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 7}, {1, 1});
    _map[8][6] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 6}, {1, 1});
    _map[8][5] = new SnakeSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {8, 5}, {1, 1});

    _texts.push_back(std::make_tuple("Score: ", Arcade::Games::Vector2i{0, 0}, Arcade::Games::Color::WHITE));
    _texts.push_back(std::make_tuple(getScore(), Arcade::Games::Vector2i{0, 7}, Arcade::Games::Color::WHITE));
}

void Snake::close(void)
{
    for (int i = 0; i < _mapSize.y; i++)
        for (int j = 0; j < _mapSize.x; j++)
            if (_map[i][j] != nullptr)
                delete _map[i][j];
}

void Snake::generateApple(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    int x = rand() % _mapSize.x;
    int y = rand() % _mapSize.y;

    if (map[y][x] == nullptr) {
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
                map[tailPos.y][tailPos.x] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, tailPos, {1, 1});
                map[bodyPos.y][bodyPos.x] = new SnakeSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, bodyPos, {1, 1});
                return;
            }
        }
    }
}

void Snake::moveBody(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction)
{
    for (int k = 0; k < _mapSize.y; k++) {
            for (int l = 0; l < _mapSize.x; l++) {
                if (map[k][l]->getPath() == _body) {
                    Arcade::Games::Vector2i temp2 = {k, l};
                    map[direction.y][direction.x] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, direction, {1, 1});
                    direction = temp2;
                }
            }
        }

        for (int k = 0; k < _mapSize.y; k++) {
            for (int l = 0; l < _mapSize.x; l++) {
                if (map[k][l]->getPath() == _tail) {
                    Arcade::Games::Vector2i temp2 = {k, l};
                    map[direction.y][direction.x] = new SnakeSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, direction, {1, 1});
                    direction = temp2;
                }
            }
        }
        map[direction.y][direction.x] = nullptr;
}

void Snake::moveSnake(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction)
{
    Arcade::Games::Vector2i prevPos;
    Arcade::Games::Vector2i currentPos;
    Arcade::Games::Vector2i temp;

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            if (map[i][j]->getPath() == _head_right ||
                map[i][j]->getPath() == _head_left ||
                map[i][j]->getPath() == _head_up ||
                map[i][j]->getPath() == _head_down) {

                prevPos = {i, j};
                currentPos = {i + direction.y, j + direction.x};

                if (currentPos.y < 0 || currentPos.y >= _mapSize.y || currentPos.x < 0 || currentPos.x >= _mapSize.x) {
                    _score = 0;
                    exit(0);
                    return;
                }

                if (map[currentPos.y][currentPos.x]->getPath() == _apple) {
                    _score++;
                    AddSnakeLength(map, direction);
                    generateApple(map);
                }

                if (direction.x == 1 && direction.y == 0)
                    map[currentPos.y][currentPos.x] = new SnakeSprite(_head_right, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, currentPos, {1, 1});
                else if (direction.x == -1 && direction.y == 0)
                    map[currentPos.y][currentPos.x] = new SnakeSprite(_head_left, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, currentPos, {1, 1});
                else if (direction.x == 0 && direction.y == 1)
                    map[currentPos.y][currentPos.x] = new SnakeSprite(_head_down, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, currentPos, {1, 1});
                else if (direction.x == 0 && direction.y == -1)
                    map[currentPos.y][currentPos.x] = new SnakeSprite(_head_up, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, currentPos, {1, 1});
                map[prevPos.y][prevPos.x] = new SnakeSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, prevPos, {1, 1});

                temp = prevPos;
                moveBody(map, temp);
                return;
            }
        }
    }
}

void Snake::checkApple(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    int check = 0;

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            if (map[i][j] == nullptr)
                continue;
            if (map[i][j]->getPath() == _apple)
                check++;
            if (map[i][j]->getPath() == _head_right ||
            map[i][j]->getPath() == _head_left ||
            map[i][j]->getPath() == _head_up ||
            map[i][j]->getPath() == _head_down) {
                if (map[i][j]->getPath() == _apple) {
                    _score++;
                    generateApple(map);
                }
            }
        }
    }
    if (check == 0) {
        _win = true;
    }
}

bool Snake::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    (void) deltaT;

    if (_win) {
        _texts.clear();
        _texts.push_back(std::make_tuple("You Win", Arcade::Games::Vector2i{8, 8}, Arcade::Games::Color::WHITE));
        _map.clear();
        return false;
    }
    if (_gameover) {
        _texts.clear();
        _texts.push_back(std::make_tuple("Game Over", Arcade::Games::Vector2i{8, 8}, Arcade::Games::Color::WHITE));
        _map.clear();
        return false;
    }
    if (inputs[Arcade::Games::KeyType::VER] == 1)
        moveSnake(_map, {0, 1});
    if (inputs[Arcade::Games::KeyType::VER] == -1)
        moveSnake(_map, {0, -1});
    if (inputs[Arcade::Games::KeyType::HOR] == 1)
        moveSnake(_map, {1, 0});
    if (inputs[Arcade::Games::KeyType::HOR] == -1)
        moveSnake(_map, {-1, 0});
    checkApple(_map);
    _texts[1] = std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>(getScore(), {0, 7}, Arcade::Games::Color::WHITE);
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
