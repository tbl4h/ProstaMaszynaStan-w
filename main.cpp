#include "headers/Client.hpp"
#include "headers/Menu.hpp"
#include "headers/Database.hpp"
int main () {
    Menu menu;
    Client c1("mic",30);
    Database db;
    db.add_to_db(c1);
    db.list_elements();

}