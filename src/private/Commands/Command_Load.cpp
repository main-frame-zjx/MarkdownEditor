#include "Command_Load.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::wstring, std::vector;
void Command_Load::exec(EditorState &state)
{
    std::wstring file_name = getStrParam(para, 1);
    for (auto file : state.load_files)
    {
        if (file->getURL() == file_name)
        {
            errorDown(file_name + L" is already open.");
            return;
        }
    }
    if (file_name.empty())
        return;
    auto markDownFilePtr = new MarkDownFile(file_name);
    state.load_files.push_back(markDownFilePtr);
    state.current_focus_file = state.load_files.size() - 1;
}

Command_Load::Command_Load(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kLoad)
{
    add2HistoryStack = true;
    canUndo = false;
}