/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Termination
*/

#ifndef ARCADE_TERMINATION_HPP_
    #define ARCADE_TERMINATION_HPP_

    #include <exception>

namespace Arcade {
    /**
     * @brief Class responsible for handling termination of the program
     */
    class Termination {
        private:
            static const std::terminate_handler DefaultTerminateHandler;
            static void terminate();
    };
}

#endif /* !ARCADE_TERMINATION_HPP_ */
