/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl
*/

#include "Sdl.hpp"

Sdl::Sdl()
: _window(nullptr), _renderer(nullptr), _font(nullptr), _textcolor({255, 255, 255}), _texttexture(nullptr), _textsurface(nullptr), _score(0)
{
}

void Sdl::init(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    _score = 0;
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cerr << "Error: " << IMG_GetError() << std::endl;
        return;
    }
    if (TTF_Init() == -1) {
        std::cerr << "Error: " << TTF_GetError() << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
}

void Sdl::close(void)
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_FreeSurface(_textsurface);
    SDL_DestroyTexture(_texttexture);
    TTF_CloseFont(_font);
    SDL_Quit();
    IMG_Quit();
}

void Sdl::clear(void)
{
    SDL_RenderClear(_renderer);
}

std::map<Arcade::Displays::KeyType, int> Sdl::getInputs(void)
{
    return _inputs;
}

void Sdl::setGameName(std::string name)
{
    _gameName = name;
}

void Sdl::setMapSize(Arcade::Displays::Vector2i vector)
{
    _map.resize(vector.y);
    for (int i = 0; i < vector.y; i++) {
        _map[i].resize(vector.x);
    }
}

void Sdl::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
    _map[vector.y][vector.x] = sprite;
}

void Sdl::displayGame(void)
{
    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] != nullptr) {
                SDL_Rect rect = {j * 32, i * 32, 32, 32};
                SDL_Surface *surface = IMG_Load(_map[i][j]->getPath().c_str());
                SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
                SDL_RenderCopy(_renderer, texture, NULL, &rect);
            }
        }
    }
    SDL_RenderPresent(_renderer);
}

void Sdl::setAnimationTime(float time)
{
}

float Sdl::getDeltaT(void)
{
    return 0;
}

void Sdl::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
    _font = TTF_OpenFont("assets/arial.ttf", 24);
    switch(color) {
        case Arcade::Displays::Color::WHITE:
            _textcolor = {255, 255, 255};
            break;
        case Arcade::Displays::Color::RED:
            _textcolor = {255, 0, 0};
            break;
        case Arcade::Displays::Color::GREEN:
            _textcolor = {0, 255, 0};
            break;
        case Arcade::Displays::Color::BLUE:
            _textcolor = {0, 0, 255};
            break;
        case Arcade::Displays::Color::YELLOW:
            _textcolor = {255, 255, 0};
            break;
        case Arcade::Displays::Color::BLACK:
            _textcolor = {0, 0, 0};
            break;
        case Arcade::Displays::Color::CYAN:
            _textcolor = {0, 255, 255};
            break;
        case Arcade::Displays::Color::MAGENTA:
            _textcolor = {255, 0, 255};
            break;
        default:
            _textcolor = {255, 255, 255};
            break;
    }
    _textsurface = TTF_RenderText_Solid(_font, text.c_str(), _textcolor);
    _texttexture = SDL_CreateTextureFromSurface(_renderer, _textsurface);
    SDL_Rect rect = {pos.x, pos.y, _textsurface->w, _textsurface->h};
    SDL_RenderCopy(_renderer, _texttexture, NULL, &rect);
}

extern "C" Arcade::Displays::IDisplayModule *entryPoint(void)
{
    return new Sdl();
}

extern "C" void deletePoint(Arcade::Displays::IDisplayModule *entry)
{
    delete entry;
}
