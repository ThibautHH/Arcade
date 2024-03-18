/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IGame
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <iostream>
#include "../Display/IDisplayModule.hpp"
#include <vector>

/**
 * @namespace Arcade::Games
 * @brief Contains all the games
 */
namespace Arcade::Games {


    /**
     * @class IGameModule
     * @brief Interface for the game modules
     */
    class IGameModule {
        public:
            /**
             * @brief Construct a new IGameModule object
             *
             */
            IGameModule();

            /**
             * @brief Destroy the IGameModule object
            */
            ~IGameModule();


            /**
            * @brief update the game with inputs
            * @param inputs map of inputs
            * @return void
            */
            virtual void update(std::map<KeyType, bool> inputs) = 0;


            /**
            * @brief Get the map of the game
            * @return std::vector<std::string>
            */
            virtual std::vector<std::vector<Arcade::Displays::ISprite>> getMap(void) = 0;

            /**
            * @brief Get the size of the map
            * @return void
            */
            virtual void getMapSize(void) = 0;


            /**
             * @brief Get the score of the game
             * @return unsigned int
             */
            virtual unsigned int getScore(void) = 0;


            /**
             * @brief Get the header of the game
             * @return std::vector<Displays::HeaderElement>
             */
            virtual std::vector<Displays::HeaderElement> getHeader(void) = 0;
        protected:
        private:
    };
}

#endif /* !IGAMEMODULE_HPP_ */
