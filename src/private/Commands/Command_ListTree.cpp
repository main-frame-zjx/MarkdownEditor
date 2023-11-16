#include "Command_ListTree.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::wstring, std::vector;
void Command_ListTree::exec(EditorState &state)
{
    state.load_files[state.current_focus_file]->listTree();
}

Command_ListTree::Command_ListTree(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kList)
{
    add2HistoryStack = false;
    canUndo = false;
}