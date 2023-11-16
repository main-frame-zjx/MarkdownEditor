#pragma once
#include "Command.h"

class Command_Stats : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Stats(std::string raw_para, std::vector<std::string> para);
};