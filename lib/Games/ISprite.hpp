/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ISprite
*/

#ifndef ISPRITE_GAMES_HPP_
#define ISPRITE_GAMES_HPP_

#include <iostream>

/**
 * @namespace Arcade::Games
 * @brief Contains all the display modules
 */
namespace Arcade::Games {

    enum class Color {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
        DEFAULT
    };

    enum class Shape {
        RECTANGLE,
        CIRCLE,
        TRIANGLE,
    };
    class Vector2i {
        public:
            Vector2i(int a, int b) : x(a), y(b) {};
            ~Vector2i() = default;

            int x;
            int y;
    };
    /**
     * @brief Interface for the sprite
     *
     */
    class ISprite {
        public:
            /**
             * @brief Construct a new ISprite object
             *
             */
            ISprite() = default;

            /**
             * @brief Destroy the ISprite object
             */
            virtual ~ISprite() = default;

            /**
             * @brief Set the path of the sprite
             * @param path
             * @return void
             */
            virtual void setPath(std::string path) = 0;

            /**
             * @brief Get the path of the sprite
             * @return std::string
             */
            virtual std::string getPath() = 0;

            /**
             * @brief Set the rotation of the sprite
             * @param rotation int corresponding to the rotation of the sprite
             * @return void
             */
            virtual void setRotation(int rotation) = 0;
            /**
             * @brief Get the rotation of the sprite
             * @return int corresponding to the rotation of the sprite
             */
            virtual int getRotation(void) = 0;

            virtual void setDirection(Vector2i direction) = 0;
            virtual Vector2i getDirection(void) = 0;

            virtual void setColor(Color color) = 0;
            virtual Color getColor(void) = 0;

            virtual void setShape(Shape shape) = 0;
            virtual Shape getShape(void) = 0;
        protected:
        private:
    };
}

#endif /* !ISPRITE_GAMES_HPP_ */
