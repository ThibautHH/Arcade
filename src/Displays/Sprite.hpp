/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite
*/

#ifndef ARCADE_DISPLAYS_SPRITE_HPP_
    #define ARCADE_DISPLAYS_SPRITE_HPP_

    #include "../../lib/Display/ISprite.hpp"

namespace Arcade::Displays {
    class Sprite : public ISprite {
        public:
            void setPath(std::string path) final { _path = path; }
            std::string getPath() final { return _path; }

            void setRotation(int rotation) final { _rotation = rotation; }
            int getRotation(void) final { return _rotation; }

            void setDirection(Vector2i direction) final { _direction = direction; }
            Vector2i getDirection(void) final { return _direction; }

            void setColor(Color color) final { _color = color; }
            Color getColor(void) final { return _color; }

            void setShape(Shape shape) final { _shape = shape; }
            Shape getShape(void) final { return _shape; }

        private:
            std::string _path, _ascii;
            int _rotation;
            Vector2i _direction = {0, 0};
            Color _color;
            Shape _shape;
    };
}

#endif /* !ARCADE_DISPLAYS_SPRITE_HPP_ */
