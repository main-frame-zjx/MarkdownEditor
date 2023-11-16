#include "Command_Delete.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include "iostream"
using std::wstring, std::vector;

void Command_Delete::exec(EditorState &state)
{
    int delete_line = tryGetIntParam(para, 1);
    if (delete_line > 0)
    {
        this->delete_line = delete_line;
        try
        {
            state.load_files[state.current_focus_file]->deleteLine(delete_line, &this->delete_word);
        }
        catch (wstring msg)
        {
            errorDown(msg);
        }
        return;
    }
    wstring word = getLongStrParam(raw_para, 1);
    if (!word.empty())
    {
        // printf("here\n");
        this->delete_word = word;
        try
        {
            state.load_files[state.current_focus_file]->deleteWord(word, &this->delete_line, &this->delete_word);
            // printf("finish\n");
        }
        catch (wstring msg)
        {
            printf("catch\n");
            errorDown(msg);
        }

        return;
    }
    errorDown(L"delete command's param error!");
}

Command_Delete::Command_Delete(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kDelete)
{
    add2HistoryStack = true;
    canUndo = true;
}

void Command_Delete::undo(EditorState &state)
{
    state.load_files[state.current_focus_file]->insertWord(this->delete_line, this->delete_word);
}