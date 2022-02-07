#pragma once
#include "../Command.hpp"
#include "../Enums.hpp"
class CommandExit : public Command 
{
    
    public:
    CommandExit(){
    }
    void call() override {
        exit(0);
    }
};