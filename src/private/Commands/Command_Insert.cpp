#include "Command_Insert.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include <iostream>
using std::string, std::vector;

void Command_Insert::exec(EditorState &state)
{
    int insert_line = tryGetIntParam(para, 1);
    string word = getLongStrParam(raw_para, 2);
    if (insert_line < 0)
    {
        insert_line = -1;
        word = getLongStrParam(raw_para, 1);
    }
    // std::cout << word << std::endl;
    if (word.empty())
        return;
    state.load_files[state.current_focus_file]->insertWord(insert_line, word);
}

Command_Insert::Command_Insert(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kInsert)
{
    add2HistoryStack = true;
    canUndo = true;
}

void Command_Insert::undo(EditorState &state)
{
    int insert_line = getIntParam(para, 1);
    state.load_files[state.current_focus_file]->deleteLine(insert_line);
}