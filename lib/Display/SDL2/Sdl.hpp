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

        void init(void) override;
        void close(void) override;
        std::map<Arcade::Displays::KeyType, int> getInputs(void) const;
        void setGameName(std::string name) override;
        void setMapSize(Arcade::Displays::Vector2i vector) override;
        void clear(void) override;
        void updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite) override;
        void displayGame(void) override;
        void setAnimationTime(float time) override;
        float getDeltaT(void) override;
        void setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color) override;
    private:
        std::string _gameName;
};

#endif /* !SDL_HPP_ */
