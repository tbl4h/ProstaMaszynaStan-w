#include "./CommandExit.hpp"
#include "./CommandCreate.hpp"
#include "./CommandListMenu.hpp"
#include "./CommandRead.hpp"
#include "./CommandWrite.hpp"
#include "./CommandListDatabase.hpp"

class CommandFactory {
    Client& command_client;
    Database& command_database;
    MainState& command_state;
    public:
    CommandFactory(Client& client_ref,Database& database_ref, MainState& state_ref):
    command_client{client_ref}, command_database{database_ref},command_state{state_ref}{}
    void change_state(MainState& state_ref){
        command_state = state_ref;
    }
    void build(MainState& state_ref){
        switch(state_ref){
            case MainState::Create:{
                CommandCreate tmp{command_client};
                tmp.call();
                break;
            }
            case MainState::ListMenu:{
                CommandListMenu tmp;
                tmp.call();
                break;
            }
            case MainState::Read:{
                CommandRead tmp{command_client,command_database};
                tmp.call();
                break;
            }
            case MainState::Write:{
                CommandWrite tmp{command_client,command_database};
                tmp.call();
                break;
            }
            case MainState::ListDatabase:{
                CommandListDatabase tmp{command_database};
                tmp.call();
                break;
            }
            case MainState::Exit:{
                CommandExit tmp;
                tmp.call();
                break;
            }
        }
    }
};