#include <string>
#include <iostream>
#include "Enums.hpp"
#include <map>
#include <functional>
#include "Command.hpp"
using namespace std;
class Menu
{
    string chooseInfo{"Co zamierzasz zrobić:\nStworzyć urzytkownika 1\nZapisać użytkownika: 2\nOdczytać użytkowników: 3\nWyjść z programu: 4\n"};
    int choice = 0;
    map<Command, vector<pair<MainTrigger, std::reference_wrapper<Command>>>> rules;
    void init_rules(){
        
    }
public:
    Menu() { cout << "Jesteś w menu głównym." << endl; }
    void make_choice()
    {
        while (true)
        {
            cout << chooseInfo << endl;
            cin >> choice;
            if (cin.fail())
                continue;
            if (cin.bad())
                throw runtime_error("Poważny błąd zapisu do danej.");
            if (cin.good())
                break;
        }
    }
    int ret_choice()const {return choice;}
};

/* To do think about rules initialization
*/