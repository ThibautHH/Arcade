/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Processor
*/

#include <algorithm>
#include <chrono>
#include <memory>
#include <optional>
#include <thread>

#include "../Displays/Sprite.hpp"
#include "Menu.hpp"

#include "Processor.hpp"

using namespace std::chrono_literals;

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

std::unique_ptr<Arcade::Displays::ISprite> Processor::translateSprite(Games::ISprite *s)
{
    if (!s)
        return nullptr;

    std::unique_ptr<Arcade::Displays::ISprite> sprite = std::make_unique<Arcade::Displays::Sprite>();

    sprite->setPath(s->getPath());
    sprite->setRotation(s->getRotation());
    sprite->setDirection(translateVector(s->getDirection()));
    sprite->setColor(DisplayColors[s->getColor()]);
    sprite->setShape(DisplayShapes[s->getShape()]);
    return sprite;
}

void Processor::displayGame(Games::IGameModule &game, const std::map<Games::KeyType, int> &inputs)
{
    game.update(inputs, this->_displayModule->getDeltaT());
    this->_displayModule->clear();
    this->_displayModule->setAnimationTime(game.getAnimationTime());
    Games::Vector2i mapSize= game.getMapSize();
    this->_displayModule->setMapSize(translateVector(mapSize));
    auto texts = game.getTexts();
    std::for_each(texts.begin(), texts.end(), [this](const auto  &t){
        this->_displayModule->setText(std::get<0>(t), translateVector(std::get<1>(t)), DisplayColors[std::get<2>(t)]);
    });
    auto sprites = game.getMap();
    std::size_t i = 0, j = 0;
    std::vector<std::unique_ptr<Displays::ISprite>> displaySprites(mapSize.y * mapSize.x);
    std::for_each(sprites.cbegin(), sprites.cend(), [this, &i, &j, &displaySprites](const auto &v){
        std::for_each(v.cbegin(), v.cend(), [&](Games::ISprite * const s){
            auto displaySprite = translateSprite(s);
            this->_displayModule->updateTile(Displays::Vector2i(j, i), displaySprite.get());
            if (displaySprite)
                displaySprites.push_back(std::move(displaySprite));
            j++;
        });
        i++;
        j = 0;
    });
    this->_displayModule->displayGame();
}

void Processor::switchDisplayModule(const std::string &path)
{
    this->_displayModule->close();
    this->_displayModule.reset();
    this->_displayModuleLibrary.reload(path.c_str());
    this->_displayModule = this->_displayModuleLibrary.createModule();
    this->_displayModule->init();
}

void Processor::switchGameModule(const std::string &path)
{
    if (this->_gameModule)
        this->_gameModule->close();
    this->_gameModule.reset();
    this->_gameModuleLibrary.reload(path.c_str());
    this->_gameModule = this->_gameModuleLibrary.createModule();
    this->_gameModule->init(path, 1);
}

void Processor::changeDisplayModule(bool previous)
{
    const auto &displays = this->_menu.getDisplays();
    if (displays.size() == 0)
        return;
    if (this->_currentDisplayIndex == 0 && previous)
        this->_currentDisplayIndex = displays.size() - 1;
    else if (this->_currentDisplayIndex == displays.size() - 1 && !previous)
        this->_currentDisplayIndex = 0;
    else
        this->_currentDisplayIndex += (previous ? -1 : 1);
    this->switchDisplayModule(displays[this->_currentDisplayIndex]);
}

void Processor::changeGameModule(bool previous)
{
    const auto &games = this->_menu.getGames();
    if (games.size() == 0)
        return;
    if (this->_currentGameIndex == 0 && previous)
        this->_currentGameIndex = games.size() - 1;
    else if (this->_currentGameIndex == games.size() - 1 && !previous)
        this->_currentGameIndex = 0;
    else
        this->_currentGameIndex += (previous ? -1 : 1);
    this->switchGameModule(games[this->_currentGameIndex]);
}

void Processor::displayMenu(const std::map<Arcade::Games::KeyType, int> &inputs)
{
    displayGame(this->_menu, inputs);
    std::optional<std::string> newGame = this->_menu.getNewGame(),
        newDisplay = this->_menu.getNewDisplay();
    if (newGame)
        this->switchGameModule(*newGame);
    else if (newDisplay)
        this->switchDisplayModule(*newDisplay);
}

void Processor::run()
{
    this->_displayModule->init();
    for (auto nextTick = std::chrono::steady_clock::now(); true; nextTick += 20ms) {
        auto inputs = this->_displayModule->getInputs();
        if (inputs[Displays::KeyType::QUIT])
            break;
        if (inputs[Displays::KeyType::ESC]) {
            if (this->_gameModule)
                this->_gameModule->close();
            this->_gameModule.reset();
        } else if (inputs[Displays::KeyType::RESTART] && this->_gameModuleLibrary.isLoaded()) {
            if (this->_gameModule)
                this->_gameModule->close();
            this->_gameModule = this->_gameModuleLibrary.createModule();
            this->_gameModule->init(std::string(), 1);
        }
        if (inputs[Displays::KeyType::NEXT_LIB])
            this->changeDisplayModule();
        else if (inputs[Displays::KeyType::PREV_LIB])
            this->changeDisplayModule(true);
        if (inputs[Displays::KeyType::NEXT_GAME])
            this->changeGameModule();
        else if (inputs[Displays::KeyType::PREV_GAME])
            this->changeGameModule(true);
        if (this->_gameModule) {
            displayGame(*this->_gameModule, translateInputs(inputs));
        } else {
            displayMenu(translateInputs(inputs));
        }
        std::this_thread::sleep_until(nextTick);
    }
    this->_displayModule->close();
}
