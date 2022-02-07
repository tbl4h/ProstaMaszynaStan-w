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
    MainState &return_state;

public:
    CommandRead(Client &client_ref, Database &db_ref, MainState &main_state) : client{client_ref}, database{db_ref}, return_state{main_state}
    {
    }
    void call() override
    {
        CommandCreate(client, return_state);
        client = database.return_current_client(client);
        if (client.get_name() == "Empty")
            cout << "Nie ma takiego klienta w bazie danych.";
        return_state = MainState::Read;
    }
};