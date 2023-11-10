#include "Command_Load.h"
#include "EditorState.h"
#include "MarkDownFile.h"

void Command_Load::exec(EditorState &state)
{
    auto markDownFilePtr = new MarkDownFile(para[1]);
    state.load_files.push_back(markDownFilePtr);
    state.current_focus_file = state.load_files.size() - 1;
}

Command_Load::Command_Load(std::vector<std::string> para) : Command(para)
{
    add2HistoryStack = true;
}