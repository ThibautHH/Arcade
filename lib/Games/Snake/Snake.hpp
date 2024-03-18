/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <stdio.h>
#include <iostream>
#include "../IGameModule.hpp"

class Snake : public Arcade::Games::IGameModule {
    public:
        Snake();
        ~Snake() = default;

        std::vector<std::vector<Arcade::Displays::ISprite>> getMap(void);
        void getMapSize(void);
        void setMap(void);
        void setScore(size_t score);

    protected:
    private:
        size_t _score;
};

#endif /* !SNAKE_HPP_ */
