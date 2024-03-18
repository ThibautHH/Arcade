/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <stdio.h>
#include <iostream>
#include "../IGameModule.hpp"

class Nibbler : public Arcade::Games::IGameModule {
    public:
        Nibbler();
        ~Nibbler() = default;

        std::vector<std::vector<Arcade::Displays::ISprite>> getMap(void);
        void getMapSize(void);
        void setMap(void);
        void setScore(size_t score);

    protected:
    private:
        size_t _score;
};

#endif /* !NIBBLER_HPP_ */
