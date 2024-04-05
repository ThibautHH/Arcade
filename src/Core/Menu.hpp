/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#ifndef ARCADE_CORE_MENU_HPP_
    #define ARCADE_CORE_MENU_HPP_

    #include <cstddef>
#include <optional>
    #include <string>

    #include "../../lib/Games/IGameModule.hpp"

namespace Arcade::Core {
    class Menu : public Games::IGameModule {
        public:
            Menu(std::string &name);

            void init(std::string args, size_t nb_args) final;
            void close(void) final;
            bool update(std::map<Games::KeyType, int> inputs, float deltaT) final;

            Games::Vector2i getMapSize(void) final;

            std::vector<std::vector<Games::ISprite *>> getMap(void) final;

            std::string getScore(void) final;
            float getAnimationTime(void) final;
            std::vector<std::tuple<std::string, Games::Vector2i, Games::Color>> getTexts(void) final;

            std::optional<std::string> getNewGame(void) const noexcept;
            std::optional<std::string> getNewDisplay(void) const noexcept;

        private:
            std::string &_name;
            std::vector<std::string> _games;
            std::vector<std::string> _displays;
            std::vector<std::string>::const_iterator _selectedElement;
            std::optional<std::string> _newModule;
            bool _isGameSelected = true;
            bool _isEditingName = false;
            char _currentChar = 'A';

            std::size_t getHeight(void) const noexcept;
            void updateModule(const std::map<Games::KeyType, int> &inputs);
            void updateName(const std::map<Games::KeyType, int> &inputs);
            void setModuleTexts(std::vector<std::tuple<std::string, Games::Vector2i, Games::Color>> &texts) const;
            void setNameTexts(std::vector<std::tuple<std::string, Games::Vector2i, Games::Color>> &texts) const;
    };
}

#endif /* !ARCADE_CORE_MENU_HPP_ */
