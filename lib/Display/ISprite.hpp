/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ISprite
*/

#ifndef ISPRITE_HPP_
    #define ISPRITE_HPP_

#include <string>

namespace Arcade::Displays {

    class ISprite {
        public:
            virtual ~ISprite() = default;

            virtual std::string getAssetPath() const = 0;
    };

    class WallSprite : public ISprite {
        public:
            std::string getAssetPath() const override {
                return "path/to/wall/sprite";
            }
    };
}

#endif /* !ISPRITE_HPP_ */
