#pragma once
#include "Command.h"

class Command_Null : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Null(std::string raw_para, std::vector<std::string> para);
};