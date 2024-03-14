/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Main
*/

#include "Core/Processor.hpp"

using namespace Arcade;

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Core::Processor arcade(av[1]);
    arcade.run();
    return 0;
}
