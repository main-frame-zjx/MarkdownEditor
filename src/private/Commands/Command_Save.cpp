#include "Command_Save.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
using std::wstring, std::vector;
void Command_Save::exec(EditorState &state)
{
    for (auto file : state.load_files)
    {
        file->save();
    }
}

Command_Save::Command_Save(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kSave)
{
    add2HistoryStack = true;
    canUndo = false;
}