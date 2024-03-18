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
#include "../ISprite.hpp"

class Ncurses : public Arcade::Displays::IDisplayModule {
    public:
        Ncurses();
        ~Ncurses() = default;

        std::map<KeyType, bool> getInputs(void) const final;
        void clear(void) final;
        void setHeader(std::string name, std::string value, Arcade::Displays::ISprite* sprite) final;
        void displayHeader(void) final;
        void setMapSize(int x, int y) final;
        void displayTile(int x, int y, Arcade::Displays::ISprite* sprite) final;
        void setBox(Arcade::Displays::Box box) final;
        void displayBox(void) final;
        bool clickedOnBoxElement(std::string name) final;
        void displayMenu(void) final;
};

#endif /* !Ncurses_HPP_ */
