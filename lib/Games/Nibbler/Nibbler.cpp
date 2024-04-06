/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
: _mapSize({19, 27}), _score(0), _animationTime(0)
{
    _gameover = false;
    _mapIndex = 0;
    _maps.push_back(_map1);
    _maps.push_back(_map2);
    _maps.push_back(_map3);
    _map.reserve(_mapSize.y);
    for (int i = 0; i < _mapSize.y; i++) {
        _map.emplace(_map.begin() + i);
        _map[i].reserve(_mapSize.x);
        for (int j = 0; j < _mapSize.x; j++) {
            _map[i].emplace(_map[i].begin() + j, nullptr);
        }
    }
    load_map();
}

void Nibbler::init(std::string args, size_t nb_args)
{
    (void) args;
    (void) nb_args;

    _texts.push_back(std::make_tuple("Score: ", Arcade::Games::Vector2i{0, 0}, Arcade::Games::Color::WHITE));
    _texts.push_back(std::make_tuple(getScore(), Arcade::Games::Vector2i{7, 0}, Arcade::Games::Color::WHITE));

    _applePos = {8, 10};
    _stop = false;
}

void Nibbler::close(void)
{
    for (int i = 0; i < _mapSize.y; i++)
        for (int j = 0; j < _mapSize.x; j++)
            if (_map[i][j] != nullptr)
                delete _map[i][j];
}

void Nibbler::clearMap(void)
{
    for (int i = 0; i < _mapSize.y; i++)
        for (int j = 0; j < _mapSize.x; j++)
            if (_map[i][j] != nullptr) {
                delete _map[i][j];
                _map[i][j] = nullptr;
            }
}

bool Nibbler::thereIsWall(Arcade::Games::Vector2i pos)
{
    for (int i = 0; i < _walls.size(); i++) {
        if (_walls[i].x == pos.x && _walls[i].y == pos.y)
            return true;
    }
    return false;
}

void Nibbler::handle_mvt(std::map<Arcade::Games::KeyType, int> inputs)
{
    if (inputs[Arcade::Games::KeyType::VER] == 1 && _snake.getDirection() != Arcade::Games::Direction::DOWN && thereIsWall({ _snake.getHeadPos().x, _snake.getHeadPos().y - 1 }) == false)
        _snake.setDirection(Arcade::Games::Direction::UP);
    if (inputs[Arcade::Games::KeyType::VER] == -1 && _snake.getDirection() != Arcade::Games::Direction::UP && thereIsWall({ _snake.getHeadPos().x, _snake.getHeadPos().y + 1 }) == false)
        _snake.setDirection(Arcade::Games::Direction::DOWN);
    if (inputs[Arcade::Games::KeyType::HOR] == 1 && _snake.getDirection() != Arcade::Games::Direction::LEFT && thereIsWall({ _snake.getHeadPos().x + 1, _snake.getHeadPos().y }) == false)
        _snake.setDirection(Arcade::Games::Direction::RIGHT);
    if (inputs[Arcade::Games::KeyType::HOR] == -1 && _snake.getDirection() != Arcade::Games::Direction::RIGHT && thereIsWall({ _snake.getHeadPos().x - 1, _snake.getHeadPos().y }) == false)
        _snake.setDirection(Arcade::Games::Direction::LEFT);

    if (inputs[Arcade::Games::KeyType::VER] == 1 ||
        inputs[Arcade::Games::KeyType::VER] == -1 ||
        inputs[Arcade::Games::KeyType::HOR] == 1 ||
        inputs[Arcade::Games::KeyType::HOR] == -1)
        _stop = false;
}

void Nibbler::load_map(void)
{
    std::ifstream file;
    std::string line;
    std::vector<std::string> map;
    int i = 0;

    file.open(_maps[_mapIndex]);
    if (!file.is_open())
        return;
    while (std::getline(file, line)) {
        map.push_back(line);
    }
    file.close();
    for (int i = 0; i < _mapSize.y; i++) {
        for (int j = 0; j < _mapSize.x; j++) {
            switch (map[i][j])
            {
                case '#':
                    _walls.push_back({j, i});
                    break;
                case ' ':
                    _map[i][j] = nullptr;
                    break;
                case 'A':
                    _apples.push_back({j, i});
                    break;
            }
        }
    }
}

bool Nibbler::isSnakeBody(Arcade::Games::Vector2i pos)
{
    for (int i = 0; i < _snake.getBodyPos().size(); i++) {
        if (_snake.getBodyPos()[i].x == pos.x && _snake.getBodyPos()[i].y == pos.y)
            return true;
    }
    return false;
}

void Nibbler::handle_collision_wall(void)
{
    _directions.clear();
    for (int i = 0; i < _walls.size(); i++) {
        if (_snake.getDirection() == Arcade::Games::Direction::RIGHT) {
            if (_snake.getHeadPos().x + 1 != _walls[i].x || _snake.getHeadPos().y != _walls[i].y)
                continue;
            if (_snake.getHeadPos().y < _mapSize.y && isSnakeBody({ _snake.getHeadPos().x, _snake.getHeadPos().y - 1 }) == false && thereIsWall({ _snake.getHeadPos().x, _snake.getHeadPos().y - 1 }) == false)
                _directions.push_back(Arcade::Games::Direction::UP);
            if (_snake.getHeadPos().y > 0 && isSnakeBody({ _snake.getHeadPos().x, _snake.getHeadPos().y + 1 }) == false && thereIsWall({ _snake.getHeadPos().x, _snake.getHeadPos().y + 1 }) == false)
                _directions.push_back(Arcade::Games::Direction::DOWN);
            if (_snake.getHeadPos().x > 0 && isSnakeBody({ _snake.getHeadPos().x - 1, _snake.getHeadPos().y }) == false && thereIsWall({ _snake.getHeadPos().x - 1, _snake.getHeadPos().y }) == false)
                _directions.push_back(Arcade::Games::Direction::LEFT);
        }
        if (_snake.getDirection() == Arcade::Games::Direction::DOWN) {
            if (_snake.getHeadPos().y + 1 != _walls[i].y || _snake.getHeadPos().x != _walls[i].x)
                continue;
            if (_snake.getHeadPos().x < _mapSize.x && isSnakeBody({ _snake.getHeadPos().x + 1, _snake.getHeadPos().y }) == false && thereIsWall({ _snake.getHeadPos().x + 1, _snake.getHeadPos().y }) == false)
                _directions.push_back(Arcade::Games::Direction::RIGHT);
            if (_snake.getHeadPos().x > 0 && isSnakeBody({ _snake.getHeadPos().x - 1, _snake.getHeadPos().y }) == false && thereIsWall({ _snake.getHeadPos().x - 1, _snake.getHeadPos().y }) == false)
                _directions.push_back(Arcade::Games::Direction::LEFT);
            if (_snake.getHeadPos().y > 0 && isSnakeBody({ _snake.getHeadPos().x, _snake.getHeadPos().y - 1 }) == false && thereIsWall({ _snake.getHeadPos().x, _snake.getHeadPos().y - 1 }) == false)
                _directions.push_back(Arcade::Games::Direction::UP);
        }
        if (_snake.getDirection() == Arcade::Games::Direction::LEFT) {
            if (_snake.getHeadPos().x - 1 != _walls[i].x || _snake.getHeadPos().y != _walls[i].y)
                continue;
            if (_snake.getHeadPos().y < _mapSize.y && isSnakeBody({ _snake.getHeadPos().x, _snake.getHeadPos().y - 1 }) == false && thereIsWall({ _snake.getHeadPos().x, _snake.getHeadPos().y - 1 }) == false)
                _directions.push_back(Arcade::Games::Direction::DOWN);
            if (_snake.getHeadPos().y > 0 && isSnakeBody({ _snake.getHeadPos().x, _snake.getHeadPos().y + 1 }) == false && thereIsWall({ _snake.getHeadPos().x, _snake.getHeadPos().y + 1 }) == false)
                _directions.push_back(Arcade::Games::Direction::UP);
            if (_snake.getHeadPos().x < _mapSize.x && isSnakeBody({ _snake.getHeadPos().x + 1, _snake.getHeadPos().y }) == false && thereIsWall({ _snake.getHeadPos().x + 1, _snake.getHeadPos().y }) == false)
                _directions.push_back(Arcade::Games::Direction::RIGHT);
        }
        if (_snake.getDirection() == Arcade::Games::Direction::UP) {
            if (_snake.getHeadPos().y - 1 != _walls[i].y || _snake.getHeadPos().x != _walls[i].x)
                continue;
            if (_snake.getHeadPos().x < _mapSize.x && isSnakeBody({ _snake.getHeadPos().x + 1, _snake.getHeadPos().y }) == false && thereIsWall({ _snake.getHeadPos().x + 1, _snake.getHeadPos().y }) == false)
                _directions.push_back(Arcade::Games::Direction::LEFT);
            if (_snake.getHeadPos().x > 0 && isSnakeBody({ _snake.getHeadPos().x - 1, _snake.getHeadPos().y }) == false && thereIsWall({ _snake.getHeadPos().x - 1, _snake.getHeadPos().y }) == false)
                _directions.push_back(Arcade::Games::Direction::RIGHT);
            if (_snake.getHeadPos().y < _mapSize.y && isSnakeBody({ _snake.getHeadPos().x, _snake.getHeadPos().y + 1 }) == false && thereIsWall({ _snake.getHeadPos().x, _snake.getHeadPos().y + 1 }) == false)
                _directions.push_back(Arcade::Games::Direction::DOWN);
        }
    }
    if (_directions.size() == 1) {
        _snake.setDirection(_directions[0]);
        return;
    }
    if (_directions.size() > 1) {
        _stop = true;
        return;
    }
}

bool Nibbler::update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT)
{
    if (_gameover) {
        _texts[1] = std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>("Game Over", {7, 0}, Arcade::Games::Color::WHITE);
        return false;
    }
    clearMap();
    if (_apples.size() == 0) {
        _walls.clear();
        _mapIndex++;
        load_map();
        if (_mapIndex == 2)
            _mapIndex = 0;
        _snake = Arcade::Games::Nibblermvt();
        return false;
    }
    handle_mvt(inputs);
    handle_collision_wall();
    if (_stop == false)
        _snake.updateSnake(_map, deltaT);
    if (_snake.getHeadPos().x < 0 || _snake.getHeadPos().x >= _mapSize.x || _snake.getHeadPos().y < 0 || _snake.getHeadPos().y >= _mapSize.y) {
        _gameover = true;
        return false;
    }
    for (int i = 0; i < _walls.size(); i++)
        _map[_walls[i].y][_walls[i].x] = new NibblerSprite(_wall, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::WHITE, _walls[i], {1, 1});
    _map[_snake.getHeadPos().y][_snake.getHeadPos().x] = new NibblerSprite(_head_right, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::MAGENTA, _snake.getHeadPos(), {1, 1});
    for (int i = 0; i < _snake.getBodyPos().size(); i++)
        _map[_snake.getBodyPos()[i].y][_snake.getBodyPos()[i].x] = new NibblerSprite(_body, Arcade::Games::Shape::RECTANGLE, Arcade::Games::Color::GREEN, _snake.getBodyPos()[i], {1, 1});

    for (int i = 0; i < _apples.size(); i++)
        _map[_apples[i].y][_apples[i].x] = new NibblerSprite(_apple, Arcade::Games::Shape::CIRCLE, Arcade::Games::Color::RED, _apples[i], {1, 1});


    if (_map[_snake.getHeadPos().y][_snake.getHeadPos().x] != nullptr && _map[_snake.getHeadPos().y][_snake.getHeadPos().x]->getColor() == Arcade::Games::Color::RED) {
        _score++;
        _snake.addBodyPart();
        for (int i = 0; i < _apples.size(); i++) {
            if (_apples[i].x == _snake.getHeadPos().x && _apples[i].y == _snake.getHeadPos().y) {
                _apples.erase(_apples.begin() + i);
                break;
            }
        }
    }
    if (_map[_snake.getHeadPos().y][_snake.getHeadPos().x] != nullptr && _map[_snake.getHeadPos().y][_snake.getHeadPos().x]->getColor() == Arcade::Games::Color::GREEN) {
        _gameover = true;
        return false;
    }
    _texts[1] = std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>(getScore(), {7, 0}, Arcade::Games::Color::WHITE);
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
