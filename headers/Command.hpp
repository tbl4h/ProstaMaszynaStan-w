#include <Enums.hpp>


struct Command
{
    MainState current;
    
    virtual void call();
    virtual void undo();
};