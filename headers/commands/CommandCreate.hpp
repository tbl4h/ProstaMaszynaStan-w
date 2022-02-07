#pragma once
#include "./../Command.hpp"
#include "../Enums.hpp"

using namespace std;

class CommandCreate : public Command
{
    Client &client;
    MainState &return_state;

public:
    CommandCreate(Client &ref, MainState &main_state) : client{ref}, return_state{main_state}
    {
    }
    void call() override
    {
        string name;
        int age = 0;
        cout << "Podaj imię: " << endl;
        cin >> name;
        client.set_name(name.c_str());
        while (true)
        {
            cout << "Podaj wiek: " << endl;
            cin >> age;
            if (cin.good())
                break;
            if (cin.bad())
                throw runtime_error("Nie można wczytać wiku.\n");
            cin.clear();
        }
        client.set_age(age);
        return_state = MainState::Create;
    }
};