#pragma once
#include "./../Command.hpp"
#include "./Database.hpp"
#include "../Enums.hpp"

using namespace std;

class CommandWrite : public Command
{
    Client &client;
    Database &db;
    MainState &return_state;

public:
    CommandWrite(Client &client_ref, Database &deb_ref, MainState &main_state) : client{client_ref}, db{deb_ref}, return_state{main_state}
    {
    }
    void call() override
    {
        db.add_to_db(client);
        return_state = MainState::Write;
    }
};