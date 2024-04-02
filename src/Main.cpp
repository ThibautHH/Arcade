/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Main
*/

#include "Core/Processor.hpp"
#include "Core/Core.hpp"
#include "Core/DLLoader.hpp"
#include <iostream>
#include <filesystem>

using namespace Arcade;

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Arcade::Core::Processor processor(av[1]);
    processor.run();
    return 0;
}
