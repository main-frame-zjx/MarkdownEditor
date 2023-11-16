#pragma once
#include "Command.h"

class Command_Stats : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Stats(std::wstring raw_para, std::vector<std::wstring> para);
};