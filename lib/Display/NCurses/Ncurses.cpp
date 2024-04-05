/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include "../IDisplayModule.hpp"
#include <ncurses.h>
#include <cstring>


Ncurses::Ncurses()
{
}

void Ncurses::init(void)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);
    curs_set(FALSE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);

    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>();
    _mapSize = Arcade::Displays::Vector2i(0, 0);
}

void Ncurses::close(void)
{
    endwin();
}

void Ncurses::clear(void)
{
    _texts.clear();
    erase();
}

std::map<Arcade::Displays::KeyType, int> Ncurses::getInputs(void)
{
    int key = getch();
    std::map<Arcade::Displays::KeyType, int> inputs;

    inputs[Arcade::Displays::KeyType::VER] = 0;
    inputs[Arcade::Displays::KeyType::HOR] = 0;
    inputs[Arcade::Displays::KeyType::PREV_LIB] = 0;
    inputs[Arcade::Displays::KeyType::NEXT_LIB] = 0;
    inputs[Arcade::Displays::KeyType::PREV_GAME] = 0;
    inputs[Arcade::Displays::KeyType::NEXT_GAME] = 0;
    inputs[Arcade::Displays::KeyType::ACTION1] = 0;
    inputs[Arcade::Displays::KeyType::ACTION2] = 0;
    inputs[Arcade::Displays::KeyType::ACTION3] = 0;
    inputs[Arcade::Displays::KeyType::ACTION4] = 0;
    inputs[Arcade::Displays::KeyType::QUIT] = 0;
    inputs[Arcade::Displays::KeyType::ESC] = 0;
    inputs[Arcade::Displays::KeyType::RESTART] = 0;

    switch (key) {
    case KEY_UP:
        inputs[Arcade::Displays::KeyType::VER] = 1;
        break;
    case KEY_DOWN:
        inputs[Arcade::Displays::KeyType::VER] = -1;
        break;
    case KEY_LEFT:
        inputs[Arcade::Displays::KeyType::HOR] = -1;
        break;
    case KEY_RIGHT:
        inputs[Arcade::Displays::KeyType::HOR] = 1;
        break;
    case 'o':
        inputs[Arcade::Displays::KeyType::PREV_LIB] = 1;
        break;
    case 'p':
        inputs[Arcade::Displays::KeyType::NEXT_LIB] = 1;
        break;
    case 'l':
        inputs[Arcade::Displays::KeyType::PREV_GAME] = 1;
        break;
    case 'm':
        inputs[Arcade::Displays::KeyType::NEXT_GAME] = 1;
        break;
    case 'w':
        inputs[Arcade::Displays::KeyType::ACTION1] = 1;
        break;
    case 'x':
        inputs[Arcade::Displays::KeyType::ACTION2] = 1;
        break;
    case 'c':
        inputs[Arcade::Displays::KeyType::ACTION3] = 1;
        break;
    case 'v':
        inputs[Arcade::Displays::KeyType::ACTION4] = 1;
        break;
    case 'q':
        inputs[Arcade::Displays::KeyType::QUIT] = 1;
        break;
    case 27:
        inputs[Arcade::Displays::KeyType::ESC] = 1;
        break;
    case 'r':
        inputs[Arcade::Displays::KeyType::RESTART] = 1;
        break;
    default:
        break;
    }
    return inputs;
}

void Ncurses::setMapSize(Arcade::Displays::Vector2i vector)
{
    _mapSize = vector;
    _map = std::vector<std::vector<Arcade::Displays::ISprite *>>(
        vector.y,
        std::vector<Arcade::Displays::ISprite *>(
            vector.x,
            nullptr
        )
    );
}

void Ncurses::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
    _map[vector.y][vector.x] = sprite;
}

void Ncurses::displayGame(void)
{
    if (LINES < _mapSize.y || COLS < _mapSize.x) {
        attron(COLOR_PAIR(1));
        mvprintw(0, 0, "Window too small to display game");
        mvprintw(1, 0, "Please resize the window");
        attroff(COLOR_PAIR(1));
        refresh();
        return;
    }
    for (int y = 0; y < _mapSize.y; y++) {
        for (int x = 0; x < _mapSize.x; x++) {
            if (_map[y][x] == nullptr)
                continue;
            switch (_map[y][x]->getColor())
            {
            case Arcade::Displays::Color::RED:
                attron(COLOR_PAIR(1));
                break;
            case Arcade::Displays::Color::GREEN:
                attron(COLOR_PAIR(2));
                break;
            case Arcade::Displays::Color::YELLOW:
                attron(COLOR_PAIR(3));
                break;
            case Arcade::Displays::Color::BLUE:
                attron(COLOR_PAIR(4));
                break;
            case Arcade::Displays::Color::MAGENTA:
                attron(COLOR_PAIR(5));
                break;
            case Arcade::Displays::Color::CYAN:
                attron(COLOR_PAIR(6));
                break;
            case Arcade::Displays::Color::WHITE:
                attron(COLOR_PAIR(7));
                break;
            default:
                break;
            }
            switch (_map[y][x]->getShape())
            {
            case Arcade::Displays::Shape::RECTANGLE:
                mvprintw(y + HEADER_HEIGHT, x, "#");
            break;
            case Arcade::Displays::Shape::CIRCLE:
                mvprintw(y + HEADER_HEIGHT, x, "O");
            break;
            case Arcade::Displays::Shape::TRIANGLE:
                mvprintw(y + HEADER_HEIGHT, x, "^");
            break;
            default:
                break;
            }
        }
    }
    attron(COLOR_PAIR(7));
    for (auto text : _texts) {
        Arcade::Displays::Vector2i pos = std::get<0>(text);
        std::string str = std::get<1>(text);
        Arcade::Displays::Color color = std::get<2>(text);
        switch (color)
        {
        case Arcade::Displays::Color::RED:
            attron(COLOR_PAIR(1));
            break;
        case Arcade::Displays::Color::GREEN:
            attron(COLOR_PAIR(2));
            break;
        case Arcade::Displays::Color::YELLOW:
            attron(COLOR_PAIR(3));
            break;
        case Arcade::Displays::Color::BLUE:
            attron(COLOR_PAIR(4));
            break;
        case Arcade::Displays::Color::MAGENTA:
            attron(COLOR_PAIR(5));
            break;
        case Arcade::Displays::Color::CYAN:
            attron(COLOR_PAIR(6));
            break;
        case Arcade::Displays::Color::WHITE:
            attron(COLOR_PAIR(7));
            break;
        default:
            break;
        }
        mvprintw(pos.y, pos.x, str.c_str());
    }
    refresh();
}

void Ncurses::setAnimationTime(float time)
{
    (void)time;
}

float Ncurses::getDeltaT(void)
{
    clock_t now = clock();
    float dt = (float)(now - _time) / CLOCKS_PER_SEC;

    _time = now;
    return dt;
}

void Ncurses::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
    _texts.push_back(std::make_tuple(pos, text, color));
}

extern "C" Arcade::Displays::IDisplayModule *displayEntryPoint()
{
    return new Ncurses();
}

extern "C" void deletePoint(Arcade::Displays::IDisplayModule *entry)
{
    delete entry;
}
