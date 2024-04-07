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
    std::map<Arcade::Displays::KeyType, int> inputs;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            inputs[Arcade::Displays::KeyType::QUIT] = 1;
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    inputs[Arcade::Displays::KeyType::VER] = 1;
                    break;
                case SDLK_DOWN:
                    inputs[Arcade::Displays::KeyType::VER] = -1;
                    break;
                case SDLK_LEFT:
                    inputs[Arcade::Displays::KeyType::HOR] = -1;
                    break;
                case SDLK_RIGHT:
                    inputs[Arcade::Displays::KeyType::HOR] = 1;
                    break;
                case SDLK_o:
                    inputs[Arcade::Displays::KeyType::PREV_LIB] = 1;
                    break;
                case SDLK_p:
                    inputs[Arcade::Displays::KeyType::NEXT_LIB] = 1;
                    break;
                case SDLK_l:
                    inputs[Arcade::Displays::KeyType::PREV_GAME] = 1;
                    break;
                case SDLK_m:
                    inputs[Arcade::Displays::KeyType::NEXT_GAME] = 1;
                    break;
                case SDLK_w:
                    inputs[Arcade::Displays::KeyType::ACTION1] = 1;
                    break;
                case SDLK_x:
                    inputs[Arcade::Displays::KeyType::ACTION2] = 1;
                    break;
                case SDLK_c:
                    inputs[Arcade::Displays::KeyType::ACTION3] = 1;
                    break;
                case SDLK_v:
                    inputs[Arcade::Displays::KeyType::ACTION4] = 1;
                    break;
                case SDLK_q:
                    inputs[Arcade::Displays::KeyType::QUIT] = 1;
                    break;
                case SDLK_ESCAPE:
                    inputs[Arcade::Displays::KeyType::ESC] = 1;
                    break;
                case SDLK_r:
                    inputs[Arcade::Displays::KeyType::RESTART] = 1;
                    break;
                default:
                    break;
            }
        }
    }
    return inputs;
}

void Sdl::setMapSize(Arcade::Displays::Vector2i vector)
{
    if (_mapSize.x == vector.x && _mapSize.y == vector.y)
        return;
    _mapSize = vector;

    _map.reserve(_mapSize.y);
    for (int i = 0; i < _mapSize.y; i++) {
        _map.emplace(_map.begin() + i);
        _map[i].reserve(_mapSize.x);
        for (int j = 0; j < _mapSize.x; j++) {
            _map[i].emplace(_map[i].begin() + j, nullptr);
        }
    }
}

void Sdl::updateTile(Arcade::Displays::Vector2i vector, Arcade::Displays::ISprite *sprite)
{
    if (vector.x < 0 || vector.y < 0 || vector.x >= _mapSize.x || vector.y >= _mapSize.y)
        return;
    _map.at(vector.y).at(vector.x) = sprite;
}

void Sdl::displayGame(void)
{
    SDL_Surface *_surface;
    SDL_Texture *_texture;
    SDL_Rect _rect;
    Arcade::Displays::Color _color;

    for (int i = 0; i < _map.size(); i++) {
        for (int j = 0; j < _map[i].size(); j++) {
            if (_map[i][j] == nullptr)
                continue;
            _rect = {j * 32, i * 32 + HEADER_HEIGHT * 32, 32, 32};
            _color = _map[i][j]->getColor();
            switch (_color) {
                case Arcade::Displays::Color::WHITE:
                    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
                    break;
                case Arcade::Displays::Color::RED:
                    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
                    break;
                case Arcade::Displays::Color::GREEN:
                    SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 255);
                    break;
                case Arcade::Displays::Color::BLUE:
                    SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);
                    break;
                case Arcade::Displays::Color::YELLOW:
                    SDL_SetRenderDrawColor(_renderer, 255, 255, 0, 255);
                    break;
                case Arcade::Displays::Color::BLACK:
                    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
                    break;
                case Arcade::Displays::Color::CYAN:
                    SDL_SetRenderDrawColor(_renderer, 0, 255, 255, 255);
                    break;
                case Arcade::Displays::Color::MAGENTA:
                    SDL_SetRenderDrawColor(_renderer, 255, 0, 255, 255);
                    break;
                default:
                    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
                    break;
                }
            SDL_RenderDrawRect(_renderer, &_rect);
            SDL_RenderFillRect(_renderer, &_rect);
            SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
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
    clock_t now = clock();
    float delta = (float)(now - _time) / (CLOCKS_PER_SEC * 3);

    _time = now;
    return delta;
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
