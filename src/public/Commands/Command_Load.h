#pragma once
#include "Command.h"

class Command_Load : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Load(std::string raw_para, std::vector<std::string> para);
};