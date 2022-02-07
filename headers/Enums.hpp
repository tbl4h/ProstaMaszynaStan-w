#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum class MainState {
    ListMenu,
    Create,
    Write,
    Read,
    ListDatabase,
    Exit,
};
inline ostream& operator<<(ostream& os,const MainState& obj)
{
    switch(obj)
    {
        case MainState::ListMenu:
            os << "List menu.";
            break;
        case MainState::Create: 
            os << "Creating Client.";
            break;
        case MainState::Exit:
            os << "Exit program.";
            break;
        case MainState::Read:
            os << "Read from db.";
            break;
        case MainState::Write:
            os << "Write to db.";
            break;
        case MainState::ListDatabase:
            os << "List database: ";
            break;
    }
    return os;
}
enum class MainTrigger {
    ToMenu,
    ToCreate,
    ToWrite,
    ToRead,
    ToListDatabase,
    ToExit
};
inline ostream& operator<<(ostream& os, const MainTrigger& obj){
    switch(obj){
        case MainTrigger::ToMenu:{
            os << "To menu." << endl;
            break;
        }
        case MainTrigger::ToCreate:{
            os << "To create." << endl;
            break;
        }
        case MainTrigger::ToWrite:{
            os << "To write." << endl;
            break;
        }
        case MainTrigger::ToRead:{
            os << "To read." << endl;
            break;
        }
        case MainTrigger::ToExit:{
            os << "To exit." << endl;
            break;
        }
        case MainTrigger::ToListDatabase:
            os << "To list data." <<endl;
            break;
    }
    return os;
}