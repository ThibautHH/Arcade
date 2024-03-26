/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <stdio.h>
#include <iostream>
#include "../IGameModule.hpp"

class Snake : public Arcade::Games::IGameModule {
    public:
        Snake();
        ~Snake() = default;

        void init(void) override;
        void close(void) override;
        void update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT) override;
        std::string getGameName(void) override;
        Arcade::Games::Vector2i getMapSize(void) override;
        std::vector<std::vector<Arcade::Games::ISprite>> getMap(void) override;
        unsigned int getScore(void) override;
        float getAnimationTime(void);
        std::vector<Arcade::Games::IText *> getTexts(void);
    private:
        size_t _score;
        std::vector<std::vector<Arcade::Games::ISprite>> _map;
        Arcade::Games::Vector2i _mapSize;
        float _animationTime;
};

#endif /* !SNAKE_HPP_ */
