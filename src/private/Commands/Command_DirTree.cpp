#include "Command_DirTree.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include <iostream>
using std::string, std::vector;
void Command_DirTree::exec(EditorState &state)
{
    string word = getLongStrParam(raw_para, 1);
    std::cout << "word: " << word << std::endl;
    state.load_files[state.current_focus_file]->listDirTree(word);
}

Command_DirTree::Command_DirTree(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kList)
{
    add2HistoryStack = false;
    canUndo = false;
}