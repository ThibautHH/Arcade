/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** ISprite
*/

#ifndef ISPRITE_HPP_
#define ISPRITE_HPP_

#include <iostream>


/**
 * @namespace Arcade::Displays
 * @brief Contains all the display modules
 */
namespace Arcade::Displays {

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
            * @brief Set the ascii of the sprite
            * @param ascii
            * @return void
            * @note ascii is a std::string because it can be multiple characters (if its 4 characters, it will be a 2x2 sprite for example)
            */
            virtual void setAscii(std::string ascii) = 0;

            /**
             * @brief Get the ascii of the sprite
             * @return std::string
             */
            virtual std::string getAscii() = 0;


            /**
             * @brief Set the path of the sprite
             * @param path
             * @return void
             */
            virtual void setPath(char path) = 0;

            /**
             * @brief Get the path of the sprite
             * @return std::string
             */
            virtual std::string getPath() = 0;
        protected:
        private:
    };
}

#endif /* !ISPRITE_HPP_ */
