#pragma once
#include "Command.h"

class Command_AppendTail : public Command
{
public:
    virtual void exec(EditorState &state) override;
    virtual void undo(EditorState &state) override;
    Command_AppendTail(std::vector<std::string> para);
};