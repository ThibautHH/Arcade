/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_

#include <vector>
#include "Display/ITile.hpp"


namespace Arcade {

    class Data {
        public:
            Data();
            ~Data();

            std::vector<std::vector<Arcade::Displays::ITile>> getMap() const;
            void setMap(std::vector<std::vector<Arcade::Displays::ITile>> newMap);
            size_t getScore() const;
            void setScore(size_t newScore);
        protected:
        private:
            std::vector<std::vector<Arcade::Displays::ITile>> map;
            size_t score;
    };

}


#endif /* !DATA_HPP_ */
