#include "Command_Undo.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include "Command_Redo.h"
using std::string, std::vector;

void Command_Undo::exec(EditorState &state)
{
    if (state.command_history_empty())
    {
        errorDown("no history command");
        return;
    }
    auto last_cmd = state.command_history_back();
    if (!last_cmd->getSucc())
    {
        errorDown("last command failed.");
        return;
    }
    if (!last_cmd->getCanUndo())
    {
        errorDown("last command can't undo.");
        return;
    }
    store_command = last_cmd;
    last_cmd->undo(state);
}

Command_Undo::Command_Undo(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kUndo)
{
    add2HistoryStack = true;
    canUndo = false;
}

void Command_Undo::undo(EditorState &state)
{
    store_command->exec_wrapper(state);
}