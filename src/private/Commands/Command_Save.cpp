#include "Command_Save.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::string, std::vector;
void Command_Save::exec(EditorState &state)
{
    for (auto file : state.load_files)
    {
        file->save();
    }
}

Command_Save::Command_Save(string raw_para, vector<string> para) : Command(raw_para, para, CommandType::kLoad)
{
    add2HistoryStack = true;
    canUndo = false;
}