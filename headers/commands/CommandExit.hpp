#pragma once
#include "../Command.hpp"
#include "../Enums.hpp"
class CommandExit : public Command 
{
    MainState& return_state;
    public:
    CommandExit(MainState& main_state):return_state{main_state}{
    }
    void call() override {
        exit(0);
    }
};