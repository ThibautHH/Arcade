/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl
*/

#include "Sdl.hpp"

Sdl::Sdl()
: _window(nullptr), _renderer(nullptr), _font(nullptr), _textcolor({255, 255, 255}), _texttexture(nullptr), _textsurface(nullptr)
{
}

void Sdl::init(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
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
    _texts.clear();
    SDL_RenderClear(_renderer);
}

std::map<Arcade::Displays::KeyType, int> Sdl::getInputs(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::QUIT, 1}};
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_q)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::QUIT, 1}};
            if (event.key.keysym.sym == SDLK_UP)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::VER, 1}};
            if (event.key.keysym.sym == SDLK_DOWN)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::VER, -1}};
            if (event.key.keysym.sym == SDLK_LEFT)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::HOR, -1}};
            if (event.key.keysym.sym == SDLK_RIGHT)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::HOR, 1}};
            if (event.key.keysym.sym == SDLK_w)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::ACTION1, 1}};
            if (event.key.keysym.sym == SDLK_x)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::ACTION2, 1}};
            if (event.key.keysym.sym == SDLK_c)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::ACTION3, 1}};
            if (event.key.keysym.sym == SDLK_v)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::ACTION4, 1}};
            if (event.key.keysym.sym == SDLK_ESCAPE)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::ESC, 1}};
            if (event.key.keysym.sym == SDLK_r)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::RESTART, 1}};
            if (event.key.keysym.sym == SDLK_n)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::NEXT_LIB, 1}};
            if (event.key.keysym.sym == SDLK_p)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::PREV_LIB, 1}};
            if (event.key.keysym.sym == SDLK_m)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::NEXT_GAME, 1}};
            if (event.key.keysym.sym == SDLK_l)
                return std::map<Arcade::Displays::KeyType, int>{{Arcade::Displays::KeyType::PREV_GAME, 1}};
        }
    }
    return _inputs;
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
    SDL_Surface *_surface;
    SDL_Texture *_texture;
    SDL_Rect _rect;

    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] != nullptr) {
                if (_textures.find(_map[i][j]->getPath()) == _textures.end()) {
                    _texture = _textures[_map[i][j]->getPath()];
                    _rect = {j * 32, i * 32, 32, 32};
                    _surface = IMG_Load(_map[i][j]->getPath().c_str());
                    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
                    SDL_RenderCopy(_renderer, _texture, NULL, &_rect);
                } else {
                    _rect = {j * 32, i * 32, 32, 32};
                    _surface = IMG_Load(_map[i][j]->getPath().c_str());
                    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
                    _textures[_map[i][j]->getPath()] = _texture;
                    SDL_RenderCopy(_renderer, _texture, NULL, &_rect);
                }
            }
        }
    }
    for (int i = 0; i < _texts.size(); i++) {
        _font = TTF_OpenFont("assets/arial.ttf", 24);
        switch(std::get<2>(_texts[i])) {
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
        _textsurface = TTF_RenderText_Solid(_font, std::get<1>(_texts[i]).c_str(), _textcolor);
        _texttexture = SDL_CreateTextureFromSurface(_renderer, _textsurface);
        _rect = {std::get<0>(_texts[i]).x * 24, std::get<0>(_texts[i]).y * 24, _textsurface->w, _textsurface->h};
        SDL_RenderCopy(_renderer, _texttexture, NULL, &_rect);
    }
    SDL_RenderPresent(_renderer);
}

void Sdl::setAnimationTime(float time)
{
    (void)time;
}

float Sdl::getDeltaT(void)
{
    return 0;
}

void Sdl::setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color)
{
    _texts.push_back(std::make_tuple(pos, text, color));
}

extern "C" Arcade::Displays::IDisplayModule *displayEntryPoint(void)
{
    return new Sdl();
}

extern "C" void deletePoint(Arcade::Displays::IDisplayModule *entry)
{
    delete entry;
}
