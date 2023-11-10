#pragma once
#include "Command.h"

class Command_Save : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Save(std::vector<std::string> para);
};