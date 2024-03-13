/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses
*/

#ifndef Ncurses_HPP_
#define Ncurses_HPP_

#include <stdio.h>
#include <iostream>
#include "../IDisplayModule.hpp"

class Ncurses : public Arcade::Displays::IDisplayModule {
    public:
        Ncurses();
        ~Ncurses() = default;

        void drawMap(Arcade::Data data) override;
        void drawScore(Arcade::Data data) override;
};


#endif /* !Ncurses_HPP_ */
