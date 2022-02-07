#pragma once
#include <vector>
#include "Client.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

class Database
{
    using v_db = vector<Client>;

    v_db inDatabase; //{Client("test",30)};
public:
    Database(){};
    void list_elements()
    {
        for (const auto obj : inDatabase)
        {
            cout << obj << endl;
        }
    }
    bool find_in_db(Client &obj)
    {
        auto res = find_if(begin(inDatabase), end(inDatabase),
                           [obj](Client tmp)
                           {
                               if (obj.get_name() == tmp.get_name() && obj.get_age() == tmp.get_age())
                                   return true;
                               else
                                   return false;
                           });
        if (res == inDatabase.end())
            return false;
        else
            return true;
    }
    Client return_current_client(Client &obj)
    {
        auto res = find_if(begin(inDatabase), end(inDatabase),
                           [obj](Client tmp)
                           {
                               if (obj.get_name() == tmp.get_name() && obj.get_age() == tmp.get_age())
                                   return true;
                               else
                                   return false;
                           });
        if (res != inDatabase.end())
        {
            Client tmp(res->get_name(), res->get_age());
            return tmp;
        }
        else
        {
            Client empty("empty", 0);
            return empty;
        }
    }
    void add_to_db(Client &obj)
    {
        bool is_in_db = find_in_db(obj);
        if (!is_in_db)
            inDatabase.push_back(obj);
        else
            cout << "Obiekt jest już w bazie danych." << endl;
    }
    void remove_from_db(Client &obj)
    {
        auto res = find_if(begin(inDatabase), end(inDatabase),
                           [obj](Client tmp)
                           {
                               if (obj.get_name() == tmp.get_name() && obj.get_age() == tmp.get_age())
                                   return true;
                               else
                                   return false;
                           });
        if (res != inDatabase.end())
            {
                v_db tmp(inDatabase.size());
                for(auto o : inDatabase)
                {
                    if(obj.get_name() == o.get_name() &&
                        obj.get_age() == o.get_age())
                        continue;
                    else
                        tmp.push_back(o);
                }
                inDatabase.clear();
                for(const auto o : tmp )
                    inDatabase.push_back(o);
            }
        else {
            cout << "Nie ma takiego obiektu." << endl;
        }
    }
};

/*To do add file manipulation options */