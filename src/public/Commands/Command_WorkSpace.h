#pragma once
#include "Command.h"

class Command_WorkSpace : public Command
{
public:
    virtual void exec(EditorState &state) override;
    Command_WorkSpace(std::wstring raw_para, std::vector<std::wstring> para);
};