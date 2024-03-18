/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses
*/

#include "Ncurses.hpp"
#include "../IDisplayModule.hpp"

Ncurses::Ncurses()
{
}

std::map<KeyType, bool> Ncurses::getInputs(void) const
{
    return std::map<KeyType, bool>();
}

void Ncurses::clear(void)
{
}

void Ncurses::setHeader(std::string name, std::string value, Arcade::Displays::ISprite* sprite)
{
}

void Ncurses::displayHeader(void)
{
}

void Ncurses::setMapSize(int x, int y)
{
}

void Ncurses::displayTile(int x, int y, Arcade::Displays::ISprite* sprite)
{
}

void Ncurses::setBox(Arcade::Displays::Box box)
{
}

void Ncurses::displayBox(void)
{
}

bool Ncurses::clickedOnBoxElement(std::string name)
{
    return false;
}

void Ncurses::displayMenu(void)
{
}

extern "C"
{
    Arcade::Displays::IDisplayModule *createModule()
    {
        return new Ncurses();
    }
}
