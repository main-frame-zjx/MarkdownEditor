#include "Command_ListTree.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::string, std::vector;
void Command_ListTree::exec(EditorState &state)
{
    state.load_files[state.current_focus_file]->listTree();
}

Command_ListTree::Command_ListTree(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kListTree)
{
    add2HistoryStack = false;
    canUndo = false;
}