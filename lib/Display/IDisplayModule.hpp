/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

namespace Arcade::Displays {

    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;

            virtual void drawMap() = 0;
            virtual void drawScore() = 0;
        private:
    };

}

#endif /* !IDISPLAYMODULE_HPP_ */
