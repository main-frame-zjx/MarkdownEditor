#include "CommandFactory.h"

Command* CommandFactory::GetCommand(){
    return new Command_Exit();
}