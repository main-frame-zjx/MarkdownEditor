#include "Command_List.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::string, std::vector;
void Command_List::exec(EditorState &state)
{
    state.load_files[state.current_focus_file]->list();
}

Command_List::Command_List(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kList)
{
    add2HistoryStack = false;
    canUndo = false;
}