#pragma once
#include "Command.h"

class Command_Insert : public Command
{
public:
    virtual void exec(EditorState &state) override;
    virtual void undo(EditorState &state) override;
    Command_Insert(std::wstring raw_para, std::vector<std::wstring> para);
};