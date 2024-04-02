/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <stdio.h>
#include <iostream>
#include "../IGameModule.hpp"

class Nibbler : public Arcade::Games::IGameModule {
    public:
        Nibbler();
        ~Nibbler() = default;

        void init(std::string args, size_t nb_args) override;
        void close(void) override;
        bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT) override;
        std::string getGameName(void) override;
        Arcade::Games::Vector2i getMapSize(void) override;
        // std::vector<std::vector<Arcade::Games::ISprite>> getMap(void) override;
        std::string getScore(void) override;
        float getAnimationTime(void);
        std::vector<Arcade::Games::IText *> getTexts(void);
    private:
        size_t _score;
        // std::vector<std::vector<Arcade::Games::ISprite>> _map;
        Arcade::Games::Vector2i _mapSize;
        float _animationTime;
};

#endif /* !NIBBLER_HPP_ */
