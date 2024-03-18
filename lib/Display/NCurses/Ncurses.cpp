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

extern "C"
{
    Arcade::Displays::IDisplayModule *createModule()
    {
        return new Ncurses();
    }
}
