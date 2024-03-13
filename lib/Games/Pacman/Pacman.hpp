/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <stdio.h>
#include <iostream>
#include "../IGameModule.hpp"

class Pacman : public Arcade::Games::IGameModule {
    public:
        Pacman();
        ~Pacman() = default;

        void loadMap() override;
        size_t getScore() override;
        void setScore(size_t score) override;
        Arcade::Data tick() override;

    protected:
    private:
        size_t _score;
};

#endif /* !PACMAN_HPP_ */
