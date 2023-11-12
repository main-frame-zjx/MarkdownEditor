#include "Command_Close.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include <iostream>
using std::string, std::vector;
void Command_Close::exec(EditorState &state)
{
    int close_index = getIntParam(para, 1) - 1;
    if (close_index < 0)
    {
        errorDown("index should > 0");
        return;
    }
    if (close_index >= state.load_files.size())
    {
        errorDown("index should less than " + std::to_string(state.load_files.size()));
        return;
    }
    if (state.load_files[close_index]->isDirty())
    {
        std::cout << "save changed file before closing? (y/n)" << std::endl;
        string line;
        std::getline(std::cin, line);
        if (line == "y")
            state.load_files[close_index]->save();
    }
    if (state.current_focus_file == close_index)
    {
        if (state.current_focus_file > 0)
            state.current_focus_file--;
        else
            state.current_focus_file++;
    }
    auto file = state.load_files[close_index];
    state.load_files.erase(state.load_files.begin() + close_index);
    delete file;
}

Command_Close::Command_Close(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kClose)
{
    add2HistoryStack = false;
    canUndo = false;
}