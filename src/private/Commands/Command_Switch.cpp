#include "Command_Switch.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::string, std::vector;
void Command_Switch::exec(EditorState &state)
{
    int switch_index = getIntParam(para, 1) - 1;
    if (switch_index < 0)
    {
        errorDown("index should >0");
        return;
    }
    if (switch_index >= state.load_files.size())
    {
        errorDown("index should less than " + std::to_string(state.load_files.size()));
        return;
    }

    state.current_focus_file = switch_index;
}

Command_Switch::Command_Switch(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kSwitch)
{
    add2HistoryStack = true;
    canUndo = false;
}