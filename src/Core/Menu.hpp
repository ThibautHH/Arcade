/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#ifndef ARCADE_CORE_MENU_HPP_
    #define ARCADE_CORE_MENU_HPP_

    #include <optional>
    #include <string>

    #include "../../lib/Games/IGameModule.hpp"

namespace Arcade::Core {
    class Menu : public Games::IGameModule {
        public:
            Menu();

            void init(std::string args, size_t nb_args) final;
            void close(void) final;
            bool update(std::map<Games::KeyType, int> inputs, float deltaT) final;

            Games::Vector2i getMapSize(void) final;

            std::vector<std::vector<Games::ISprite *>> getMap(void) final;

            std::string getScore(void) final;
            float getAnimationTime(void) final;
            std::vector<std::tuple<std::string, Games::Vector2i, Games::Color>> getTexts(void) final;

            std::optional<std::string> getNewGame(void);
            std::optional<std::string> getNewDisplay(void);

        private:
            std::vector<std::string> _games;
            std::vector<std::string> _displays;
            std::vector<std::string>::const_iterator _selectedElement;
            std::optional<std::string> _newModule;
            bool _isGameSelected = true;
    };
}

#endif /* !ARCADE_CORE_MENU_HPP_ */
