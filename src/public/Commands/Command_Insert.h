#pragma once
#include "Command.h"

class Command_Insert : public Command
{
public:
    virtual void exec(EditorState &state) override;
    virtual void undo(EditorState &state) override;
    Command_Insert(std::vector<std::string> para);
};