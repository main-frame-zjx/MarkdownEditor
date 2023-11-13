#pragma once
#include "Command.h"

class Command_History : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_History(std::string raw_para, std::vector<std::string> para);
};