/**
 * Command interface for actors to handle.
 *
 * */
#ifndef VIOLET_COMMAND_HPP
#define VIOLET_COMMAND_HPP
#include "Actor.hpp"

class ICommand {
    public:
        virtual void execute(Actor* actor) = 0;
};

#endif // #ifndef VIOLET_CONTROL_HPP
