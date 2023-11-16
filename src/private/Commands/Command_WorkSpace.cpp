#include "Command_WorkSpace.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "iostream"
using std::wcout, std::endl;
void Command_WorkSpace::exec(EditorState &state)
{
    for (int i = 0; i < state.load_files.size(); i++)
    {
        auto file = state.load_files[i];
        wcout << i + 1 << " " << file->getURL();
        if (file->isDirty())
            wcout << '*';
        if (i == state.current_focus_file)
            wcout << '<';
        wcout << endl;
    }
}

Command_WorkSpace::Command_WorkSpace(std::wstring raw_para, std::vector<std::wstring> para) : Command(raw_para, para, CommandType::kWs)
{
    add2HistoryStack = false;
    canUndo = false;
}