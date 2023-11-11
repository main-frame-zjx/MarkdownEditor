#pragma once
#include "Command.h"

class Command_Switch : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Switch(std::string raw_para, std::vector<std::string> para);
};