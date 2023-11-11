#include "Command_Insert.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::string, std::vector;

void Command_Insert::exec(EditorState &state)
{
    int insert_line = getIntParam(para, 1);
    if (insert_line < 0)
        return;

    state.current_focus_file = insert_line;
}

Command_Insert::Command_Insert(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kInsert)
{
    add2HistoryStack = true;
}

void Command_Insert::undo(EditorState &state)
{
}