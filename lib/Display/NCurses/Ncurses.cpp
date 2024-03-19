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

void Ncurses::init(void)
{
}

void Ncurses::clear(void)
{
}

void Ncurses::close(void)
{
}

std::map<KeyType, bool> Ncurses::getInputs(void) const
{
    return std::map<KeyType, bool>();
}

void Ncurses::setGameName(std::string name)
{
}

void Ncurses::resetBoxes(void)
{
}

void Ncurses::setBox(Arcade::Displays::Box box)
{
}

void Ncurses::setMapSize(int x, int y)
{
}

void Ncurses::clear(void)
{
}

void Ncurses::displayTile(int x, int y, Arcade::Displays::ISprite *sprite)
{
}

bool Ncurses::clickedOnBoxElement(std::string name)
{
    return false;
}

void Ncurses::displayGame(void)
{
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
