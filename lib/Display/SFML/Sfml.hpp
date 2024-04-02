/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../IDisplayModule.hpp"

class Sfml : public Arcade::Displays::IDisplayModule{
    public:
        Sfml();
        ~Sfml() = default;

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
        sf::RenderWindow _window;
        std::map<Arcade::Displays::KeyType, int> _inputs;
        sf::Text _text;
        sf::Font _font;
        std::string _gameName;
        unsigned int _score;
        std::vector<std::vector<Arcade::Displays::ISprite *>> _map;
        std::map<std::string, sf::Texture> _textures;
};

#endif /* !SFML_HPP_ */
