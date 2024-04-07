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

Menu::Menu(std::string &name)
    : _name(name)
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

std::size_t Menu::getHeight(void) const noexcept
{
    if (this->_isEditingName)
        return 6;
    return std::max(this->_games.size(), this->_displays.size()) + 6;
}

Arcade::Games::Vector2i Menu::getMapSize(void)
{
    const std::size_t longestGame = getLongestString(this->_games),
        longestDisplay = getLongestString(this->_displays),
        width = longestGame + longestDisplay + 8;

    return {static_cast<int>(width) + 2, static_cast<int>(this->getHeight())};
}

void Menu::updateModule(const std::map<Games::KeyType, int> &inputs)
{
    if (inputs.at(Games::KeyType::HOR) > 0 && this->_isGameSelected && !this->_displays.empty()) {
        this->_isGameSelected = false;
        long offset = this->_selectedElement - this->_games.cbegin();
        if (offset >= static_cast<signed>(this->_displays.size()))
            this->_selectedElement = --this->_displays.cend();
        else
            this->_selectedElement = this->_displays.cbegin() + offset;
    } else if (inputs.at(Games::KeyType::HOR) < 0 && !this->_isGameSelected && !this->_games.empty()) {
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
        return;
    if ((inputs.at(Games::KeyType::VER) < 0 && ++this->_selectedElement == selected.cend())
        || (inputs.at(Games::KeyType::VER) > 0 && this->_selectedElement != selected.cbegin()))
        this->_selectedElement--;
    if (inputs.at(Games::KeyType::ACTION1) != 0)
        this->_newModule = *this->_selectedElement;
    else
        this->_newModule = std::nullopt;
}

void Menu::updateName(const std::map<Games::KeyType, int> &inputs)
{
    if (inputs.at(Games::KeyType::ACTION2) != 0) {
        if (this->_currentChar <= 'Z')
            this->_currentChar += 32;
        else
            this->_currentChar -= 32;
    }
    if (inputs.at(Games::KeyType::VER) < 0 && this->_currentChar != 'Z' && this->_currentChar != 'z')
        this->_currentChar++;
    else if (inputs.at(Games::KeyType::VER) > 0 && this->_currentChar != 'A' && this->_currentChar != 'a')
        this->_currentChar--;
    if (inputs.at(Games::KeyType::HOR) < 0 && !this->_name.empty())
        this->_name.pop_back();
    if (inputs.at(Games::KeyType::HOR) > 0)
        this->_name.push_back(this->_currentChar);
}

bool Menu::update(std::map<Games::KeyType, int> inputs, float)
{
    static unsigned short tick = 0;
    if (tick++ == 20) {
        tick = 0;
        this->_isCharDisplayed = !this->_isCharDisplayed;
    }
    if (inputs.at(Games::KeyType::ACTION4) != 0)
        this->_isEditingName = !this->_isEditingName;
    if (this->_isEditingName)
        this->updateName(inputs);
    else
        this->updateModule(inputs);
    return true;
}

std::optional<std::string> Menu::getNewGame(void) const noexcept
{
    if (this->_isGameSelected)
        return this->_newModule;
    return std::nullopt;
}

std::optional<std::string> Menu::getNewDisplay(void) const noexcept
{
    if (!this->_isGameSelected)
        return this->_newModule;
    return std::nullopt;
}

const std::vector<std::string> &Menu::getDisplays(void) const noexcept
{
    return this->_displays;
}

using Text = std::tuple<std::string, Arcade::Games::Vector2i, Arcade::Games::Color>;

void Menu::setModuleTexts(std::vector<Text> &texts) const
{
    static const Text gameTitle = {"Games:", {1, 3}, Arcade::Games::Color::DEFAULT};
    const int displaysOffset = static_cast<int>(getLongestString(this->_games)) + 5;
    const Text displayTitle = {"Displays:", {displaysOffset, 3}, Arcade::Games::Color::DEFAULT};

    texts.push_back(gameTitle);
    texts.push_back(displayTitle);
    std::vector<std::string>::const_iterator it = this->_games.cbegin();
    const std::vector<std::string>::const_iterator gamesBegin = this->_games.cbegin(), displaysBegin = this->_displays.cbegin();
    std::for_each(it, this->_games.cend(), [&texts, &it, gamesBegin](const std::string &game){
        texts.push_back({game, {3, static_cast<int>(it++ - gamesBegin) + 4}, Arcade::Games::Color::DEFAULT});
    });
    it = this->_displays.cbegin();
    std::for_each(it, this->_displays.cend(), [&texts, &it, displaysBegin, displaysOffset](const std::string &display){
        texts.push_back({display, {displaysOffset + 2, static_cast<int>(it++ - displaysBegin) + 4}, Arcade::Games::Color::DEFAULT});
    });
    texts.push_back({"->", {
            this->_isGameSelected ? 1 : displaysOffset,
            static_cast<int>(this->_isGameSelected
                ? this->_selectedElement - gamesBegin
                : this->_selectedElement - displaysBegin) + 4
        }, Arcade::Games::Color::DEFAULT});
    texts.push_back({"Press ACTION1 to select",
        {3, static_cast<int>(this->getHeight()) - 1},
        Arcade::Games::Color::DEFAULT});
}

void Menu::setNameTexts(std::vector<Text> &texts) const
{
    static const char caseTooltip[] = "Press ACTION2 to change case",
        validateTooltip[] = "Press ACTION1 to validate";
    texts.push_back({caseTooltip,
        {3, 3},
        Arcade::Games::Color::DEFAULT});
    texts.push_back({"Press ACTION4 to validate",
        {3, 5},
        Arcade::Games::Color::DEFAULT});
    texts.push_back({"\tPress HOR to delete or insert letter",
        {sizeof(caseTooltip) + 3, 3},
        Arcade::Games::Color::DEFAULT});
    texts.push_back({"\t\tPress VER to change letter",
        {sizeof(validateTooltip) + 3, 5},
        Arcade::Games::Color::DEFAULT});
}

std::vector<Text> Menu::getTexts(void)
{
    std::vector<Text> texts{};
    std::string nameText = "Name: " + this->_name;
    if (this->_isEditingName) {
        nameText.push_back(this->_isCharDisplayed ? this->_currentChar : '_');
        this->setNameTexts(texts);
    } else {
        nameText += "\t(Press ACTION4 to edit)";
        this->setModuleTexts(texts);
    }
    texts.push_back({nameText, {3, 1}, Arcade::Games::Color::DEFAULT});
    return texts;
}
