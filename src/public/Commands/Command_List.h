#pragma once
#include "Command.h"

class Command_List : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_List(std::vector<std::string> para);
};