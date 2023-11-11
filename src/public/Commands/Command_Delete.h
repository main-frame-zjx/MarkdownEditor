#pragma once
#include "Command.h"

class Command_Delete : public Command
{
private:
    std::string delete_word;
    int delete_line;

public:
    virtual void exec(EditorState &state) override;
    virtual void undo(EditorState &state) override;
    Command_Delete(std::string raw_para, std::vector<std::string> para);
};