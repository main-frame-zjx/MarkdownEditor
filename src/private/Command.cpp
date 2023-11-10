#include "Command.h"

void Command::undo(EditorState &state)
{
    return;
}

Command::Command(std::vector<std::string> para) : para(para)
{
}
