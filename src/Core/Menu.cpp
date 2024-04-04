/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#include <algorithm>
#include <cstddef>
#include <filesystem>
#include <functional>
#include <string>
#include <vector>

#include "ModuleLibrary.hpp"

#include "Menu.hpp"

namespace fs = std::filesystem;

using namespace Arcade::Core;

Menu::Menu()
{
    this->init(std::string(), 0);
}

void Menu::init(std::string, std::size_t)
{
    std::error_code e;
    fs::directory_iterator lib_dir("lib");
    for (const auto &entry : lib_dir) {
        if (std::string_view(entry.path().stem().c_str()).starts_with("arcade_")
            && entry.path().extension() == ".so") {
            if (GameLibrary::canLoad(entry.path().c_str())) {
                this->_games.push_back(entry.path().string());
            } else if (DisplayLibrary::canLoad(entry.path().c_str())) {
                this->_displays.push_back(entry.path().string());
            }
        }
    }
    if (this->_games.empty()) {
        this->_isGameSelected = false;
        this->_selectedElement = this->_displays.cbegin();
    } else
        this->_selectedElement = this->_games.cbegin();
}

void Menu::close(void)
{
}

std::string Menu::getScore(void)
{
    return "";
}

float Menu::getAnimationTime(void)
{
    return 0;
}

std::vector<std::vector<Arcade::Games::ISprite *>> Menu::getMap(void)
{
    return {};
}

static inline std::size_t getLongestString(const std::vector<std::string> &vec)
{
    static const std::function<bool(const std::string &, const std::string &)> cmp =
        [](const std::string &a, const std::string &b) { return a.size() < b.size(); };
    return std::max_element(vec.begin(), vec.end(), cmp)->size();
}

Arcade::Games::Vector2i Menu::getMapSize(void)
{
    const std::size_t longestGame = getLongestString(this->_games), longestDisplay = getLongestString(this->_displays),
        height = std::max(this->_games.size(), this->_displays.size()) + 1,
        width = longestGame + longestDisplay + 8;

    return {static_cast<int>(width) + 2, static_cast<int>(height) + 2};
}

bool Menu::update(std::map<Games::KeyType, int> inputs, float)
{
    if (inputs[Games::KeyType::HOR] > 0 && this->_isGameSelected && !this->_displays.empty()) {
        this->_isGameSelected = false;
        long offset = this->_selectedElement - this->_games.cbegin();
        if (offset >= static_cast<signed>(this->_displays.size()))
            this->_selectedElement = --this->_displays.cend();
        else
            this->_selectedElement = this->_displays.cbegin() + offset;
    } else if (inputs[Games::KeyType::HOR] < 0 && !this->_isGameSelected && !this->_games.empty()) {
        this->_isGameSelected = true;
        long offset = this->_selectedElement - this->_displays.cbegin();
        if (offset >= static_cast<signed>(this->_games.size()))
            this->_selectedElement = --this->_games.cend();
        else {
            this->_selectedElement = this->_games.cbegin() + offset;
        }
    }
    const std::vector<std::string> &selected = this->_isGameSelected ? this->_games : this->_displays;
    if (this->_selectedElement == selected.cend())
        return true;
    if ((inputs[Games::KeyType::VER] < 0 && ++this->_selectedElement == selected.cend())
        || (inputs[Games::KeyType::VER] > 0 && this->_selectedElement != selected.cbegin()))
        this->_selectedElement--;
    if (inputs[Games::KeyType::ACTION1] != 0)
        this->_newModule = *this->_selectedElement;
    else
        this->_newModule = std::nullopt;
    return true;
}

std::optional<std::string> Menu::getNewGame(void)
{
    if (this->_isGameSelected)
        return this->_newModule;
    return std::nullopt;
}

std::optional<std::string> Menu::getNewDisplay(void)
{
    if (!this->_isGameSelected)
        return this->_newModule;
    return std::nullopt;
}

using Text = std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>;

std::vector<Text> Menu::getTexts(void)
{
    static const Text gameTitle = {"Games:", {1, 1}, Arcade::Games::Color::DEFAULT};
    const int displaysOffset = static_cast<int>(getLongestString(this->_games)) + 5;
    const Text displayTitle = {"Displays:", {displaysOffset, 1}, Arcade::Games::Color::DEFAULT};

    std::vector<Text> texts = {gameTitle, displayTitle};
    std::vector<std::string>::const_iterator it = this->_games.cbegin();
    const std::vector<std::string>::const_iterator gamesBegin = this->_games.cbegin(), displaysBegin = this->_displays.cbegin();
    std::for_each(it, this->_games.cend(), [&texts, &it, gamesBegin](const std::string &game){
        texts.push_back({game, {3, static_cast<int>(it++ - gamesBegin) + 2}, Arcade::Games::Color::DEFAULT});
    });
    it = this->_displays.cbegin();
    std::for_each(it, this->_displays.cend(), [&texts, &it, displaysBegin, displaysOffset](const std::string &display){
        texts.push_back({display, {displaysOffset + 2, static_cast<int>(it++ - displaysBegin) + 2}, Arcade::Games::Color::DEFAULT});
    });
    texts.push_back({"->", {
            this->_isGameSelected ? 1 : displaysOffset,
            static_cast<int>(this->_isGameSelected ? this->_selectedElement - gamesBegin : this->_selectedElement - displaysBegin) + 2
        }, Arcade::Games::Color::DEFAULT});
    return texts;
}
