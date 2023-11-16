#include "Command_Undo.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include "Command_Redo.h"
using std::wstring, std::vector;

void Command_Undo::exec(EditorState &state)
{
    if (state.command_history_empty())
    {
        errorDown(L"no history command");
        return;
    }
    auto last_cmd = state.command_history_back();
    if (!last_cmd->getSucc())
    {
        errorDown(L"last command failed.");
        return;
    }
    if (!last_cmd->getCanUndo())
    {
        errorDown(L"last command can't undo.");
        return;
    }
    store_command = last_cmd;
    last_cmd->undo(state);
}

Command_Undo::Command_Undo(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kUndo)
{
    add2HistoryStack = true;
    canUndo = false;
}

void Command_Undo::undo(EditorState &state)
{
    store_command->exec_wrapper(state);
}