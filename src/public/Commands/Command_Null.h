#pragma once
#include "Command.h"

class Command_Null : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_Null(std::wstring raw_para, std::vector<std::wstring> para);
};