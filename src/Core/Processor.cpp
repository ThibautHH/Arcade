/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Processor
*/

#include <algorithm>

#include "Processor.hpp"

using namespace Arcade::Core;

Processor::Processor(const char *path)
    : _displayModuleLibrary(path), _gameModuleLibrary(),
    _displayModule(_displayModuleLibrary.createModule()),
    _gameModule(nullptr)
{
}

std::map<Arcade::Games::KeyType, int> Processor::translateInputs(std::map<Displays::KeyType, int> inputs)
{
    return std::map<Arcade::Games::KeyType, int>{
        {Games::KeyType::HOR, inputs[Displays::KeyType::HOR]},
        {Games::KeyType::VER, inputs[Displays::KeyType::VER]},
        {Games::KeyType::ACTION1, inputs[Displays::KeyType::ACTION1]},
        {Games::KeyType::ACTION2, inputs[Displays::KeyType::ACTION2]},
        {Games::KeyType::ACTION3, inputs[Displays::KeyType::ACTION3]},
        {Games::KeyType::ACTION4, inputs[Displays::KeyType::ACTION4]},
        {Games::KeyType::ESC, inputs[Displays::KeyType::ESC]}
    };
}

Arcade::Displays::Vector2i Processor::translateVector(Games::Vector2i v)
{
    return Displays::Vector2i(v.x, v.y);
}

std::map<Arcade::Games::Color, Arcade::Displays::Color> Processor::DisplayColors = {
    {Games::Color::BLACK, Displays::Color::BLACK},
    {Games::Color::RED, Displays::Color::RED},
    {Games::Color::GREEN, Displays::Color::GREEN},
    {Games::Color::YELLOW, Displays::Color::YELLOW},
    {Games::Color::BLUE, Displays::Color::BLUE},
    {Games::Color::MAGENTA, Displays::Color::MAGENTA},
    {Games::Color::CYAN, Displays::Color::CYAN},
    {Games::Color::WHITE, Displays::Color::WHITE},
    {Games::Color::DEFAULT, Displays::Color::DEFAULT}
};

std::map<Arcade::Games::Shape, Arcade::Displays::Shape> Processor::DisplayShapes = {
    {Games::Shape::CIRCLE, Displays::Shape::CIRCLE},
    {Games::Shape::RECTANGLE, Displays::Shape::RECTANGLE},
    {Games::Shape::TRIANGLE, Displays::Shape::TRIANGLE}
};

Arcade::Displays::Sprite Processor::translateSprite(Games::ISprite &s)
{
    Displays::Sprite sprite;

    sprite.setPath(s.getPath());
    sprite.setRotation(s.getRotation());
    sprite.setDirection(translateVector(s.getDirection()));
    sprite.setColor(DisplayColors[s.getColor()]);
    sprite.setShape(DisplayShapes[s.getShape()]);
    return sprite;
}

void Processor::run()
{
    std::string name = "Player";

    this->_displayModule->init();
    while (true) {
        auto inputs = this->_displayModule->getInputs();
        if (inputs[Displays::KeyType::QUIT])
            break;
        if (this->_gameModule) {
            this->_gameModule->update(translateInputs(inputs), this->_displayModule->getDeltaT());
            this->_displayModule->clear();
            this->_displayModule->setAnimationTime(this->_gameModule->getAnimationTime());
            this->_displayModule->setMapSize(translateVector(this->_gameModule->getMapSize()));
            auto texts = this->_gameModule->getTexts();
            std::for_each(texts.begin(), texts.end(), [this](const auto  &t){
                this->_displayModule->setText(std::get<0>(t), translateVector(std::get<1>(t)), DisplayColors[std::get<2>(t)]);
            });
            auto sprites = this->_gameModule->getMap();
            std::size_t i = 0, j = 0;
            std::for_each(sprites.cbegin(), sprites.cend(), [this, &i, &j](const auto &v){
                std::for_each(v.cbegin(), v.cend(), [this, &i, &j](const auto &s){
                    auto displaySprite = translateSprite(*s);
                    this->_displayModule->updateTile(Displays::Vector2i(j, i), &displaySprite);
                    j++;
                });
                i++;
            });
            this->_displayModule->displayGame();
        }
    }
    this->_displayModule->close();
}
