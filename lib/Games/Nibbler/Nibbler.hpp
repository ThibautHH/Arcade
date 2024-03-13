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

        void loadMap() override;
        size_t getScore() override;
        void setScore(size_t score) override;
        Arcade::Data tick() override;

    protected:
    private:
        size_t _score;
};

#endif /* !NIBBLER_HPP_ */
