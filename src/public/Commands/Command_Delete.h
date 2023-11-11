#pragma once
#include "Command.h"

class Command_Delete : public Command
{
public:
    virtual void exec(EditorState &state) override;
    virtual void undo(EditorState &state) override;
    Command_Delete(std::string raw_para, std::vector<std::string> para);
};