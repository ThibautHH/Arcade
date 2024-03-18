/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IDisplay
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_
#include <map>
#include "ISprite.hpp"
#include <iostream>
#include <vector>
#include <memory>

/**
 * @brief Enum of the different key types
 *
 */
enum class KeyType {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    ESCAPE,
    SPACE,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};

/**
 * @namespace Arcade::Displays
 *
 * @brief Contains all the display modules
 */
namespace Arcade::Displays {

    /**
     * @brief Class of the BoxElement
     *
     */
    class BoxElement {
        public:
            /**
             * @brief Construct a new Box Element object
             *
             * @param name
             * @param value
             * @param selected
             */
            BoxElement(std::string name, std::string value, bool selected)
            {
            }

            /**
             * @brief Destroy the Box Element object
             *
             */
            ~BoxElement()
            {
            }


            /**
             * @brief Name of the BoxElement
             *
             */
            std::string name;

            /**
             * @brief Value of the BoxElement
             *
             */
            std::string value;

            /**
             * @brief If the BoxElement is selected
             *
             */
            bool selected;
    };

    /**
     * @brief Class of the Box
     *
     */
    class Box {
        public:
            /**
             * @brief Construct a new Box object
             *
             * @param name
             * @param value
             * @param selected
             */
            Box(std::string name, std::string value, bool selected)
            {
            }

            /**
             * @brief Destroy the Box object
             *
             */
            ~Box()
            {
            }

            /**
             * @brief Name of the Box
             *
             */
            std::string value;

            /**
             * @brief Value of the Box
             *
             */
            std::vector<BoxElement> elements;
    };

    /**
     * @brief Class of the HeaderElement
     *
     */
    class HeaderElement {
        public:
            /**
             * @brief Construct a new Header Element object
             *
             * @param name
             * @param value
             * @param selected
             */
            HeaderElement(std::string name, std::string value, bool selected)
            {
                this->name = name;
                this->value = value;
                this->sprite = nullptr;
            }

            /**
             * @brief Destroy the Header Element object
             *
             */
            ~HeaderElement()
            {
            }

            /**
             * @brief Name of the HeaderElement
             *
             */
            std::string name;

            /**
             * @brief Value of the HeaderElement
             *
             */
            std::string value;

            /**
             * @brief If the HeaderElement is selected
             *
             */
            std::shared_ptr<ISprite> sprite;
    };

    /**
     * @brief Interface for the display modules
     */
    class IDisplayModule {
        public:

            /**
             * @brief Construct a new IDisplayModule object
             *
             */
            IDisplayModule() = default;

            /**
            * @brief Get the Inputs object
            * @return std::map<KeyType, bool>
            */
            virtual std::map<KeyType, bool> getInputs() const = 0;

            /**
             * @brief Clear the display
             * @param inputs
             * @return void
             */
            virtual void clear() = 0;

            /**
             * @brief Set Header of the display
             * @param name
             * @param sprite
             * @param value
             * @return void
             */
            virtual void setHeader(std::string name, std::string value, ISprite* sprite) = 0;

            /**
             * @brief Display the header
             * @return void
             */
            virtual void displayHeader(void) = 0;

            /**
             * @brief Set the Size of the map
             * @param x
             * @param y
             * @return void
             */
            virtual void setMapSize(int x, int y) = 0;

            /**
             * @brief Display a tile
             * @param x
             * @param y
             * @param sprite
             * @return void
             */
            virtual void displayTile(int x, int y, ISprite* sprite) = 0;

            virtual void setBox(Box box) = 0;
            virtual void displayBox(void) = 0;

            virtual bool clickedOnBoxElement(std::string name) = 0;

            /**
             * @brief Display the menu
             * @return void
             */
            virtual void displayMenu(void) = 0;

        protected:
        private:
    };
}


#endif /* !IDISPLAYMODULE_HPP_ */
