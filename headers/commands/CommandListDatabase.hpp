#pragma once
#include "./../Command.hpp"
#include "Database.hpp"

class CommandListDatabase : public Command {
    Database& database;
    public:
    CommandListDatabase(Database& db_ref):database{db_ref} {}
    void call() override {
        database.list_elements();
    }
};