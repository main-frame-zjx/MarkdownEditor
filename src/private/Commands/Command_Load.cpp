#include "Command_Load.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::string, std::vector;
void Command_Load::exec(EditorState &state)
{
    std::string file_name = getStrParam(para, 1);
    if (file_name.empty())
        return;
    auto markDownFilePtr = new MarkDownFile(file_name);
    state.load_files.push_back(markDownFilePtr);
    state.current_focus_file = state.load_files.size() - 1;
}

Command_Load::Command_Load(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kLoad)
{
    add2HistoryStack = true;
}