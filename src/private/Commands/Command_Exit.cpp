#include "Command_Exit.h"

void Command_Exit::exec(EditorState &state)
{
    exit(1);
}

Command_Exit::Command_Exit(std::vector<std::string> para) : Command(para)
{
    add2HistoryStack = false;
}