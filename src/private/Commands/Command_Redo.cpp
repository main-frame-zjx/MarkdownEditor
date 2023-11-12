#include "Command_Redo.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::string, std::vector;

void Command_Redo::exec(EditorState &state)
{
    if (state.command_history.empty())
    {
        errorDown("no history command");
        return;
    }
    auto last_cmd = state.command_history.back();
    if (!(last_cmd->getType() == CommandType::kUndo))
    {
        errorDown("you can only use 'redo' after 'undo'.");
        return;
    }
    last_cmd->undo(state);
}

Command_Redo::Command_Redo(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kRedo)
{
    add2HistoryStack = true;
    canUndo = false;
}

void Command_Redo::undo(EditorState &state)
{
    int insert_line = getIntParam(para, 1);
    state.load_files[state.current_focus_file]->deleteLine(insert_line);
}