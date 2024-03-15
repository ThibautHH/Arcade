/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include <stdio.h>
#include <iostream>
#include "../IDisplayModule.hpp"

class Sdl : public Arcade::Displays::IDisplayModule{
    public:
        Sdl();
        ~Sdl() = default;

    protected:
    private:
};

#endif /* !SDL_HPP_ */
