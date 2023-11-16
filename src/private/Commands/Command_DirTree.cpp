#include "Command_DirTree.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include <iostream>
#include <string>
using std::wstring, std::vector;
void Command_DirTree::exec(EditorState &state)
{
    wstring word = getLongStrParam(raw_para, 1);
    state.load_files[state.current_focus_file]->listDirTree(word);
}

Command_DirTree::Command_DirTree(std::wstring raw_para, std::vector<std::wstring> para) : Command(raw_para, para, CommandType::kList)
{
    add2HistoryStack = false;
    canUndo = false;
}