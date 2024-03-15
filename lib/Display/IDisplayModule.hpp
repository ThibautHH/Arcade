/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

#include <vector>
#include <memory>
#include <map>
#include "ITile.hpp"
#include "ISprite.hpp"
namespace Arcade::Displays {

    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;

            virtual void displayMap(std::vector<std::vector<std::unique_ptr<Arcade::Displays::ITile>>> &map) = 0;
            virtual void displayHeader(std::map<std::string, std::pair<std::weak_ptr<Arcade::Displays::ISprite>, std::string>> &headerData) = 0;
        private:
    };

}

#endif /* !IDISPLAYMODULE_HPP_ */
