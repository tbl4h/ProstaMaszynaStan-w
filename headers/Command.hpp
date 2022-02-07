#pragma once
#include <Enums.hpp>

struct Command
{
    MainState current;
    
    virtual void call() = 0;
    // virtual void undo();
};