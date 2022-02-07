#pragma once
#include "../Command.hpp"
#include "./CommandCreate.hpp"
#include "../Client.hpp"
#include "../Database.hpp"
#include "../Enums.hpp"

class CommandRead : public Command
{
    Client &client;
    Database &database;

public:
    CommandRead(Client &client_ref, Database &db_ref) : client{client_ref}, database{db_ref}
    {
    }
    void call() override
    {
        CommandCreate tmp{client};
        tmp.call();
        client = database.return_current_client(client);
        if (client.get_name() == "Empty")
            cout << "Nie ma takiego klienta w bazie danych.";
    }
};