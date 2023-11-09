#include "CommandFactory.h"
#include "Command.h"
#include "Command_Exit.h"

Command *CommandFactory::GetCommand(std::vector<std::string> para)
{
    if (para[0] == std::string("load"))
    {
    }
    return new Command_Exit();
}