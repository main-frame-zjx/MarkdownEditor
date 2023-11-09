#pragma once
#include "Command.h"
#include "Command_Exit.h"

class CommandFactory{
public:
    static Command* GetCommand();
};