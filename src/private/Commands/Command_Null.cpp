#include "Command_Null.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include <iostream>
using std::string, std::vector;
void Command_Null::exec(EditorState &state)
{
    std::cout << "error command!" << std::endl;
}

Command_Null::Command_Null(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kNull)
{
    add2HistoryStack = false;
    canUndo = false;
}