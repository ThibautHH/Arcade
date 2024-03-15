/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
    #define IGAMEMODULE_HPP_

#include <string>
#include "IInput.hpp"
#include <memory>
#include <vector>
#include <map>
#include "../Display/ITile.hpp"
#include "../Display/ISprite.hpp"

namespace Arcade::Games {

    /***
     * @brief Interface for game modules
    */
    class IGameModule {
        public:
            virtual ~IGameModule() = default;

            virtual void loadMap() = 0;
            virtual size_t getScore() = 0;
            virtual void setScore(size_t score) = 0;
            virtual void tick(Arcade::Games::IInput&) = 0;

            /**
             * @brief Get the Map object
             * 
             * @return std::vector<std::vector<std::unique_ptr<Arcade::Displays::ITile>>>& 
             */
            virtual std::vector<std::vector<std::unique_ptr<Arcade::Displays::ITile>>> &getMap() = 0;

            /**
             * @brief Get the Header Data object
             * 
             * @return std::map<std::string, std::pair<std::weak_ptr<Arcade::Displays::ISprite>, std::string>>& 
             */
            virtual std::map<std::string, std::pair<std::weak_ptr<Arcade::Displays::ISprite>, std::string>> &getHeaderData() = 0;
        private:
    };

}

#endif /* !IGAMEMODULE_HPP_ */