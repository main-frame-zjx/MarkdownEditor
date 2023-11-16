#include "Command_Null.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include <iostream>
using std::wstring, std::vector;
void Command_Null::exec(EditorState &state)
{
    std::wcout << L"error command!" << std::endl;
}

Command_Null::Command_Null(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kNull)
{
    add2HistoryStack = false;
    canUndo = false;
}