/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IDisplay
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include "ISprite.hpp"
#include <map>
#include <iostream>
#include <vector>
#include <memory>

/**
 * @namespace Arcade::Displays
 *
 * @brief Contains all the display modules
 */
namespace Arcade::Displays {

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

    class IDisplayModule {
        public:
            /**
             * @brief Destroy the IDisplayModule object
             * @return void
             */
            virtual ~IDisplayModule() = default;

            /**
             * @brief Init the display
             * @return void
             */
            virtual void init(void) = 0;
            /**
             * @brief close, responsible to close the display, free all
             * @return void
             */
            virtual void close(void) = 0;

            /**
             * @brief Get the Inputs object
             * @return std::map<KeyType, int>
             */
            virtual std::map<Arcade::Displays::KeyType, int> getInputs(void) = 0;

            /**
             * @brief Set the Size of the map
             * @param x horizontal size
             * @param y vertical size
             * @return void
             */
            virtual void setMapSize(Vector2i vector) = 0;

            /**
             * @brief Clear the display
             * @return void
             */
            virtual void clear(void) = 0;

            /**
             * @brief update a tile
             * @param x horizontal position
             * @param y vertical position
             * @param sprite
             * @return void
             */
            virtual void updateTile(Vector2i vector, ISprite *sprite) = 0;

            /**
             * @brief Update the display of the game after drawing the map with displayTile
             * @return void
             */
            virtual void displayGame(void) = 0;

            virtual void setAnimationTime(float time) = 0;

            virtual float getDeltaT(void) = 0;

            virtual void setText(std::string text, Arcade::Displays::Vector2i pos, Arcade::Displays::Color color) = 0;
    };
}

#endif /* !IDISPLAY_HPP_ */
