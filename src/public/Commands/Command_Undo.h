#pragma once
#include "Command.h"

class Command_Undo : public Command
{
private:
    Command *store_command;

public:
    virtual void exec(EditorState &state) override;
    virtual void undo(EditorState &state) override;
    Command_Undo(std::string raw_para, std::vector<std::string> para);
};