#include <vector>
#include "Client.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

class Database {
    using v_db =  vector<Client>  ;
    
    v_db inDatabase ;//{Client("test",30)};
    public:
    Database() {};
    void list_elements(){
        for(const auto obj : inDatabase){
            cout << obj << endl;
        }
    }
    void add_to_db(Client& obj) 
    {
        auto res = find_if(begin(inDatabase),end(inDatabase),
        [obj](Client tmp){
            if(obj.get_name() == tmp.get_name() && obj.get_age() == tmp.get_age())
                return true;
            else
                return false;
        });
        if(res == inDatabase.end())
            inDatabase.push_back(obj);
    }

};


/*To do add file manipulation options */ 