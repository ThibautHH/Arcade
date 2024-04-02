/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGame
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include "ISprite.hpp"
#include <map>
#include <iostream>
#include <vector>
#include <memory>

namespace Arcade::Games {

    enum class KeyType {
        HOR,
        VER,
        ACTION1,
        ACTION2,
        ACTION3,
        ACTION4,
        QUIT,
        ESC,
        NEXT_LIB,
        PREV_LIB,
        NEXT_GAME,
        PREV_GAME,
        RESTART
    };

    class IText {
        virtual ~IText() = default;

        virtual void setText(std::string text) = 0;
        virtual std::string getText(void) = 0;

        virtual void setPos(Vector2i pos) = 0;
        virtual Vector2i getPos(void) = 0;

        virtual void setColor(Color color) = 0;
        virtual Color getColor(void) = 0;
    };

    class IGameModule {
        public:
            /**
             * @brief Destroy the IGameModule object
             * @return void
             */
            virtual ~IGameModule() = default;

            /**
             * @brief init the game
             * @return void
             */
            virtual void init(std::string args, size_t nb_args) = 0;
            /**
             * @brief Close the game
             * @return void
             */
            virtual void close(void) = 0;
            /**
             * @brief update the game with inputs
             * @param inputs map of inputs
             * @return void
             */
            virtual bool update(std::map<Arcade::Games::KeyType, int> inputs, float deltaT) = 0;

            virtual std::string getGameName(void) = 0;

            virtual Vector2i getMapSize(void) = 0;

            /**
            * @brief Get the map of the game
            * @return std::vector<std::string>
            */
            virtual std::vector<std::vector<Arcade::Games::ISprite>> getMap(void) = 0;

            /**
             * @brief Get the score of the game
             * @return std::string
             */
            virtual std::string getScore(void) = 0;

            virtual float getAnimationTime(void) = 0;

            virtual std::vector<IText *> getTexts(void) = 0;
        protected:
        private:
    };
}

#endif /* !IGAMEMODULE_HPP_ */
