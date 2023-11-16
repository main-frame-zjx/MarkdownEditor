#pragma once
#include "Command.h"

class Command_DirTree : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_DirTree(std::string raw_para, std::vector<std::string> para);
};