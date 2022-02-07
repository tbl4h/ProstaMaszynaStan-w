#include <string>
#include <iostream>
#include "Enums.hpp"
#include <map>
#include <functional>
#include "Command.hpp"
#include "./commands/CommandCreate.hpp"
#include "./commands/CommandWrite.hpp"
#include "./commands/CommandRead.hpp"
#include "./commands/CommandListMenu.hpp"
#include "./commands/CommandExit.hpp"
using namespace std;
class Menu
{
    string chooseInfo{"Co zamierzasz zrobić:\nStworzyć urzytkownika 1\nZapisać użytkownika: 2\nOdczytać użytkowników: 3\nWyjść z programu: 4\n"};
    int choice = 0;
    Client current_client;
    Database db;
    MainState current_state = MainState::ListMenu;
    CommandListMenu clm{choice, current_state};
    CommandCreate cc{current_client, current_state};
    CommandRead cr{current_client,db,current_state};
    CommandWrite cw{current_client, db, current_state};
    CommandExit ce{current_state};
    map<MainState, vector<pair<MainTrigger, reference_wrapper<Command>>>> rules;
    void init_rules()
    {
        rules[MainState::ListMenu] = {
            {MainTrigger::ToMenu, clm},
            {MainTrigger::ToCreate, cc},
            {MainTrigger::ToRead, cr},
            {MainTrigger::ToWrite, cw},
            {MainTrigger::ToExit, ce}};
        rules[MainState::Create] = {
            {MainTrigger::ToMenu, clm}};
        rules[MainState::Read] = {
            {MainTrigger::ToMenu, clm}};
        rules[MainState::Write] = {
            {MainTrigger::ToMenu, clm}
        };
    }

public:
    Menu() {}
    void make_choice()
    {
        rules[MainState::ListMenu][0].second.get().call();
        while (true)
        {            
            cin >> choice;
            if (cin.fail())
                continue;
            if (cin.bad())
                throw runtime_error("Poważny błąd zapisu do danej.");

        }
    }
    int ret_choice() const { return choice; }
};

/* To do think about rules initialization
 */