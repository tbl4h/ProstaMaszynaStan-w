#pragma once
#include "./../Command.hpp"
#include "./../Enums.hpp"
class CommandListMenu : public Command
{
    

public:
    CommandListMenu() 
    {
    }
    void call() override
    {
        string chooseInfo{"Co zamierzasz zrobić:\nStworzyć urzytkownika 1\nZapisać użytkownika: 2\nOdczytać użytkowników: 3\nWyjść z programu: 4\n"};
    }
};