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

        void close(void) override;
        void init(void) override;
        void clear(void) override;
        std::map<KeyType, bool> getInputs(void) const override;
        void setGameName(std::string name) override;
        void resetBoxes(void) override;
        void setBox(Arcade::Displays::Box box) override;
        void setMapSize(int x, int y) override;
        void clear(void) override;
        void displayTile(int x, int y, Arcade::Displays::ISprite *sprite) override;
        bool clickedOnBoxElement(std::string name) override;
        void displayGame(void) override;
        void displayMenu(void) override;

};

#endif /* !Ncurses_HPP_ */
