#include "Command_Switch.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::wstring, std::vector;
void Command_Switch::exec(EditorState &state)
{
    int switch_index = getIntParam(para, 1) - 1;
    if (switch_index < 0)
    {
        errorDown(L"index should >0");
        return;
    }
    if (switch_index >= state.load_files.size())
    {
        errorDown(L"index should less than " + std::to_wstring(state.load_files.size()));
        return;
    }

    state.current_focus_file = switch_index;
}

Command_Switch::Command_Switch(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kSwitch)
{
    add2HistoryStack = true;
    canUndo = false;
}