#include "Command_AppendTail.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::wstring, std::vector;

void Command_AppendTail::exec(EditorState &state)
{
    int insert_line = -1;
    wstring word = getLongStrParam(raw_para, 1);
    if (word.empty())
    {
        errorDown(L"param error!");
        return;
    }
    state.load_files[state.current_focus_file]->insertWord(insert_line, word);
}

Command_AppendTail::Command_AppendTail(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kAppendTail)
{
    add2HistoryStack = true;
    canUndo = true;
}

void Command_AppendTail::undo(EditorState &state)
{
    state.load_files[state.current_focus_file]->deleteLine(-1);
}