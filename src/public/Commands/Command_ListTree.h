#pragma once
#include "Command.h"

class Command_ListTree : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_ListTree(std::string raw_para, std::vector<std::string> para);
};