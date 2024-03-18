/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Processor
*/

#include "Processor.hpp"
#include <iostream>
#include <filesystem>

using namespace Arcade::Core;

//constexpr std::string_view DISPLAYS_PATH[] = {
//    "./lib/Display/NCurses/ncurses.so",
//    "./lib/Display/SFML/sfml.so",
//    "./lib/Display/SDL2/sdl.so"
//};
//
//constexpr std::string_view GAMES_PATH[] = {
//    "./lib/Games/Nibbler/nibbler.so",
//    "./lib/Games/Snake/snake.so",
//};
//
Processor::Processor(const char *path)
    : _moduleLibrary(path)
{
}

void Processor::run()
{
    //for (auto &entry : std::filesystem::directory_iterator("./lib")) {
    //    for (auto &display : DISPLAYS_PATH) {
    //        if (entry.path() == display) {
    //            std::cout << "Display: " << entry.path() << std::endl;
    //        }
    //    }
    //    for (auto &game : GAMES_PATH) {
    //        if (entry.path() == game) {
    //            std::cout << "Game: " << entry.path() << std::endl;
    //        }
    //    }
    //}
}
