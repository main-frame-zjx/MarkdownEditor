#pragma once
#include "Command.h"

class Command_Exit : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Exit(std::vector<std::string> para);
};