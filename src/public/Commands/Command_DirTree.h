#pragma once
#include "Command.h"

class Command_DirTree : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_DirTree(std::wstring raw_para, std::vector<std::wstring> para);
};