#pragma once
#include "Command.h"

class Command_Close : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Close(std::string raw_para, std::vector<std::string> para);
};