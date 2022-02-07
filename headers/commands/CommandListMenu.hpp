#pragma once
#include "./../Command.hpp"
#include "./../Enums.hpp"
class CommandListMenu : public Command
{
    int &choice;
    MainState &ret_state;

public:
    CommandListMenu(int &choice_ref, MainState &main_state) : choice{choice_ref}, ret_state{main_state}
    {
    }
    void call() override
    {
        string chooseInfo{"Co zamierzasz zrobić:\nStworzyć urzytkownika 1\nZapisać użytkownika: 2\nOdczytać użytkowników: 3\nWyjść z programu: 4\n"};
        ret_state == MainState::ListMenu;
    }
};