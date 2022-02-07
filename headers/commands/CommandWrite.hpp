#pragma once
#include "./../Command.hpp"
#include "./Database.hpp"
#include "../Enums.hpp"

using namespace std;

class CommandWrite : public Command
{
    Client &client;
    Database &db;

public:
    CommandWrite(Client &client_ref, Database &deb_ref) : client{client_ref}, db{deb_ref}
    {
    }
    void call() override
    {
        db.add_to_db(client);
    }
};