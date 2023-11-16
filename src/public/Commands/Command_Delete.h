#pragma once
#include "Command.h"

class Command_Delete : public Command
{
private:
    std::wstring delete_word;
    int delete_line;

public:
    virtual void exec(EditorState &state) override;
    virtual void undo(EditorState &state) override;
    Command_Delete(std::wstring raw_para, std::vector<std::wstring> para);
};