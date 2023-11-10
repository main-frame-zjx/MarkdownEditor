#pragma once
#include "Command.h"

class Command_Load : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Load();
};