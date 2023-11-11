#include "Command_Switch.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::string, std::vector;
void Command_Switch::exec(EditorState &state)
{
    int switch_index = getIntParam(para, 1) - 1;
    if (switch_index < 0)
        return;
    state.current_focus_file = switch_index;
}

Command_Switch::Command_Switch(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kSwitch)
{
    add2HistoryStack = true;
}