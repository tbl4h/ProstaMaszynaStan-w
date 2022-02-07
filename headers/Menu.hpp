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
#include "./commands/CommandFactory.hpp"

using namespace std;
class Menu
{
    string chooseInfo{"Co zamierzasz zrobić:\nStworzyć urzytkownika 1\nZapisać użytkownika: 2\nOdczytać użytkowników: 3\nWyjść z programu: 4\n"};
    int choice = 0;
    Client current_client;
    Database db;
    MainState current_state = MainState::ListMenu;
    MainState exit_state = MainState::Exit;
    CommandFactory command_factory{current_client,db,current_state}; 
    map<MainState, vector<pair<MainTrigger, MainState>>> rules;
    void init_rules()
    {
        rules[MainState::ListMenu] = {
            {MainTrigger::ToMenu, MainState::ListMenu},
            {MainTrigger::ToCreate, MainState::Create},
            {MainTrigger::ToRead, MainState::Read},
            {MainTrigger::ToWrite, MainState::Write},
            {MainTrigger::ToExit, MainState::Exit},
            {MainTrigger::ToListDatabase, MainState::ListDatabase}};
        rules[MainState::Create] = {
            {MainTrigger::ToMenu, MainState::ListMenu}};
        rules[MainState::Read] = {
            {MainTrigger::ToMenu, MainState::ListMenu}};
        rules[MainState::Write] = {
            {MainTrigger::ToMenu, MainState::ListMenu}};
        rules[MainState::ListDatabase] = {
            {MainTrigger::ToMenu, MainState::ListMenu}};
    }

public:
    Menu() {}
    void make_choice()
    {
        init_rules();
        while (true)
        {
            cout << "Telefon jest obecnie w stanie " << current_state << endl;
        select_trigger:
            cout << "Wybierz wyzwalacz:"
                 << "\n";

            int i = 0;
            for (auto item : rules[current_state])
            {
                cout << i++ << ". " << item.first << "\n";
            }

            int input;
            cin >> input;
            if(cin.bad())
                cin.clear();
            if (input < 0 || (input + 1) > rules[current_state].size())
            {
                cout << "Niepoprawna opcja. Spr¢buj jeszcze raz."
                     << "\n";
                goto select_trigger;
            }

            current_state = rules[current_state][input].second;
            command_factory.build(current_state);
            if (current_state == exit_state)
                break;
        }
    }
    int ret_choice() const { return choice; }
};

/* To do think about rules initialization
 */