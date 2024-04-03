/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
: _mapSize({18, 16}), _score(0), _animationTime(0)
{
    _map.resize(_mapSize.y);
    for (int i = 0; i < _mapSize.y; i++)
        _map[i].resize(_mapSize.x);

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            _map[i][j] = new NibblerSprite("", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::DEFAULT, {i, j}, {1, 1});
        }
    }
}

void Nibbler::init(std::string args, size_t nb_args)
{
    _map[1][8] = new NibblerSprite(_head_right, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {1, 8}, {1, 1});
    _map[1][7] = new NibblerSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {1, 7}, {1, 1});
    _map[1][6] = new NibblerSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {1, 6}, {1, 1});
    _map[1][5] = new NibblerSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, {1, 5}, {1, 1});

    for (int i = 0; i < 10; i++) {
        generateApple(_map);
    }
    _texts.push_back(std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>("Score: ", {0, 0}, Arcade::Games::Color::WHITE));
    _texts.push_back(std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>("0", {0, 7}, Arcade::Games::Color::WHITE));
}

void Nibbler::close(void)
{
    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            delete _map[i][j];
        }
    }
}

void Nibbler::generateApple(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    int x = rand() % _mapSize.x;
    int y = rand() % _mapSize.y;

    if (map[y][x]->getPath() == "") {
        map[y][x] = new NibblerSprite(_apple, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::RED, {y, x}, {1, 1});
    } else
        generateApple(map);
}

void Nibbler::AddNibblerLength(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction)
{
    Arcade::Games::Vector2i tailPos;
    Arcade::Games::Vector2i bodyPos;

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            if (map[i][j]->getPath() == _tail) {
                tailPos = {i, j};
                bodyPos = {i - direction.y, j - direction.x};
                map[tailPos.y][tailPos.x] = new NibblerSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, tailPos, {1, 1});
                map[bodyPos.y][bodyPos.x] = new NibblerSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, bodyPos, {1, 1});
                return;
            }
        }
    }
}

void Nibbler::moveBody(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction)
{
    for (int k = 0; k < _mapSize.y; k++) {
            for (int l = 0; l < _mapSize.x; l++) {
                if (map[k][l]->getPath() == _body) {
                    Arcade::Games::Vector2i temp2 = {k, l};
                    map[direction.y][direction.x] = new NibblerSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, direction, {1, 1});
                    direction = temp2;
                }
            }
        }

        for (int k = 0; k < _mapSize.y; k++) {
            for (int l = 0; l < _mapSize.x; l++) {
                if (map[k][l]->getPath() == _tail) {
                    Arcade::Games::Vector2i temp2 = {k, l};
                    map[direction.y][direction.x] = new NibblerSprite(_tail, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, direction, {1, 1});
                    direction = temp2;
                }
            }
        }
        map[direction.y][direction.x] = new NibblerSprite("", Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, direction, {1, 1});
}

void Nibbler::moveNibbler(std::vector<std::vector<Arcade::Games::ISprite *>> map, Arcade::Games::Vector2i direction)
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

                if (map[currentPos.y][currentPos.x]->getPath() == _apple) {
                    _score++;
                    AddNibblerLength(map, direction);
                    generateApple(map);
                }

                if (map[currentPos.y][currentPos.x]->getPath() == _wall) {
                    if (direction.x == 1 && direction.y == 0) {
                        if (map[prevPos.y - 1][prevPos.x]->getPath() == "") {
                            currentPos = {prevPos.y - 1, prevPos.x};
                        } else if (map[prevPos.y + 1][prevPos.x]->getPath() == "") {
                            currentPos = {prevPos.y + 1, prevPos.x};
                        }
                    } else if (direction.x == -1 && direction.y == 0) {
                        if (map[prevPos.y - 1][prevPos.x]->getPath() == "") {
                            currentPos = {prevPos.y - 1, prevPos.x};
                        } else if (map[prevPos.y + 1][prevPos.x]->getPath() == "") {
                            currentPos = {prevPos.y + 1, prevPos.x};
                        }
                    } else if (direction.x == 0 && direction.y == 1) {
                        if (map[prevPos.y][prevPos.x - 1]->getPath() == "") {
                            currentPos = {prevPos.y, prevPos.x - 1};
                        } else if (map[prevPos.y][prevPos.x + 1]->getPath() == "") {
                            currentPos = {prevPos.y, prevPos.x + 1};
                        }
                    } else if (direction.x == 0 && direction.y == -1) {
                        if (map[prevPos.y][prevPos.x - 1]->getPath() == "") {
                            currentPos = {prevPos.y, prevPos.x - 1};
                        } else if (map[prevPos.y][prevPos.x + 1]->getPath() == "") {
                            currentPos = {prevPos.y, prevPos.x + 1};
                        }
                    }
                }
                if (direction.x == 1 && direction.y == 0)
                    map[currentPos.y][currentPos.x] = new NibblerSprite(_head_right, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, currentPos, {1, 1});
                else if (direction.x == -1 && direction.y == 0)
                    map[currentPos.y][currentPos.x] = new NibblerSprite(_head_left, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, currentPos, {1, 1});
                else if (direction.x == 0 && direction.y == 1)
                    map[currentPos.y][currentPos.x] = new NibblerSprite(_head_down, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, currentPos, {1, 1});
                else if (direction.x == 0 && direction.y == -1)
                    map[currentPos.y][currentPos.x] = new NibblerSprite(_head_up, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, currentPos, {1, 1});
                map[prevPos.y][prevPos.x] = new NibblerSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, prevPos, {1, 1});

                temp = prevPos;
                moveBody(map, temp);
                return;
            }
        }
    }
}

void Nibbler::checkApple(std::vector<std::vector<Arcade::Games::ISprite *>> map)
{
    int check = 0;

    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            if (map[i][j]->getPath() == _apple)
                check++;
            if (map[i][j]->getPath() == _head_right ||
            map[i][j]->getPath() == _head_left ||
            map[i][j]->getPath() == _head_up ||
            map[i][j]->getPath() == _head_down) {
                if (map[i][j]->getPath() == _apple) {
                    _score++;
                }
            }
        }
    }
    if (check == 0) {
        // Go to next map
    }
}

bool Nibbler::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    (void) deltaT;

    if (inputs[Arcade::Games::KeyType::VER] == 1)
        moveNibbler(_map, {0, -1});
    if (inputs[Arcade::Games::KeyType::VER] == -1)
        moveNibbler(_map, {0, 1});
    if (inputs[Arcade::Games::KeyType::HOR] == 1)
        moveNibbler(_map, {1, 0});
    if (inputs[Arcade::Games::KeyType::HOR] == -1)
        moveNibbler(_map, {-1, 0});
    checkApple(_map);
    _texts[1] = std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>(getScore(), {0, 7}, Arcade::Games::Color::WHITE);
    return true;
}

Arcade::Games::Vector2i Nibbler::getMapSize(void)
{
    return _mapSize;
}

std::vector<std::vector<Arcade::Games::ISprite *>> Nibbler::getMap(void)
{
    return _map;
}

std::string Nibbler::getScore(void)
{
    return std::to_string(_score);
}

float Nibbler::getAnimationTime(void)
{
    return _animationTime;
}

std::vector<std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>> Nibbler::getTexts(void)
{
    return _texts;
}

extern "C" Arcade::Games::IGameModule *gameEntryPoint(void)
{
    return new Nibbler();
}

extern "C" void deletePoint(Arcade::Games::IGameModule *entry)
{
    delete entry;
}
