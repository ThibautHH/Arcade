/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <stdio.h>
#include <iostream>
#include "../IDisplayModule.hpp"

class Sfml : public Arcade::Displays::IDisplayModule{
    public:
        Sfml();
        ~Sfml() = default;

    protected:
    private:
};

#endif /* !SFML_HPP_ */
