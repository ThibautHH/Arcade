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
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_shape.h>
#include <map>
#include <vector>
#include <string>
#include <unistd.h>
#include "../IDisplayModule.hpp"

#define HEADER_HEIGHT 1
class Sdl : public Arcade::Displays::IDisplayModule{
    public:
        Sdl();
        ~Sdl() = default;

        void init(void) override;
        void close(void) override;
        std::map<Arcade::Displays::KeyType, int> getInputs(void);
        void setMapSize(Arcade::Displays::Vector2i vector) override;
        void clear(void) override;
        void updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite) override;
        void displayGame(void) override;
        void setAnimationTime(float time) override;
        float getDeltaT(void) override;
        void setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color) override;
    private:
        std::map<Arcade::Displays::KeyType, int> _inputs;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        TTF_Font *_font;
        SDL_Color _textcolor;
        SDL_Texture *_texttexture;
        SDL_Surface *_textsurface;
        std::vector<std::vector<Arcade::Displays::ISprite *>> _map;
        Arcade::Displays::Vector2i _mapSize;
        std::map<std::string, SDL_Texture *> _textures;
        std::vector<std::tuple<Arcade::Displays::Vector2i, std::string, Arcade::Displays::Color>> _texts;
        clock_t _time;
};

#endif /* !SDL_HPP_ */
