#include "Command_AppendHead.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::wstring, std::vector;

void Command_AppendHead::exec(EditorState &state)
{
    int insert_line = 1;
    wstring word = getLongStrParam(raw_para, 1);
    if (word.empty())
    {
        errorDown(L"param error!");
        return;
    }
    state.load_files[state.current_focus_file]->insertWord(insert_line, word);
}

Command_AppendHead::Command_AppendHead(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kAppendHead)
{
    add2HistoryStack = true;
    canUndo = true;
}

void Command_AppendHead::undo(EditorState &state)
{
    state.load_files[state.current_focus_file]->deleteLine(1);
}