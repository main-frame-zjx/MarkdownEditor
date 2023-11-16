#pragma once
#include "Command.h"

class Command_ListTree : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_ListTree(std::wstring raw_para, std::vector<std::wstring> para);
};