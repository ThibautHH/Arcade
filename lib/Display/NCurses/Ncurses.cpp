/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include "../IDisplayModule.hpp"
#include <ncurses.h>

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
}

void Ncurses::close(void)
{
    endwin();
}

void Ncurses::clear(void)
{
    erase();
}

std::map<Arcade::Displays::KeyType, int> Ncurses::getInputs(void)
{
    int key = getch();
    std::map<Arcade::Displays::KeyType, int> inputs;

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
    _map.resize(vector.y);
    for (int i = 0; i < vector.y; i++) {
        _map[i].resize(vector.x);
    }
}

void Ncurses::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
    _map[vector.y][vector.x] = sprite;
}

void Ncurses::displayGame(void)
{
    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] != nullptr) {
                attron(COLOR_PAIR(_map[i][j]->getColor()));
                mvprintw(i, j, _map[i][j]->getAscii().c_str());
                attroff(COLOR_PAIR(_map[i][j]->getColor()));
            }
        }
    }
    mvprintw(0, 0, _gameName.c_str());
    refresh();
}

void Ncurses::setAnimationTime(float time)
{
    (void)time;
}

float Ncurses::getDeltaT(void)
{
    return 0;
}

void Ncurses::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
    int color_pair = 0;

    switch (color) {
    case Arcade::Displays::Color::RED:
        color_pair = 1;
        break;
    case Arcade::Displays::Color::GREEN:
        color_pair = 2;
        break;
    case Arcade::Displays::Color::YELLOW:
        color_pair = 3;
        break;
    case Arcade::Displays::Color::BLUE:
        color_pair = 4;
        break;
    case Arcade::Displays::Color::MAGENTA:
        color_pair = 5;
        break;
    case Arcade::Displays::Color::CYAN:
        color_pair = 6;
        break;
    case Arcade::Displays::Color::WHITE:
        color_pair = 7;
        break;
    default:
        break;
    }
    attron(COLOR_PAIR(color_pair));
    mvprintw(pos.y, pos.x, text.c_str());
    attroff(COLOR_PAIR(color_pair));
}

extern "C" Arcade::Displays::IDisplayModule *entryPoint()
{
    return new Ncurses();
}

extern "C" void deletePoint(Arcade::Displays::IDisplayModule *entry)
{
    delete entry;
}
