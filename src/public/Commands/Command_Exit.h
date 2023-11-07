#pragma once
#include "Command.h"

class Command_Exit: public Command{
public:
    virtual void exec() override;
    Command_Exit();
};