#include "Command_Exit.h"

void Command_Exit::exec(EditorState &state)
{
    exit(1);
}

Command_Exit::Command_Exit(std::string raw_para, std::vector<std::string> para) : Command(raw_para, para, CommandType::kExit)
{
    add2HistoryStack = false;
}