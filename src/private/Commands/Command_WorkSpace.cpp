#include "Command_WorkSpace.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "iostream"
using std::cout, std::endl;
void Command_WorkSpace::exec(EditorState &state)
{
    for (int i = 0; i < state.load_files.size(); i++)
    {
        auto file = state.load_files[i];
        cout << i << " " << file->getURL();
        if (file->isDirty())
            cout << '*';
        if (i == state.current_focus_file)
            cout << '<';
        cout << endl;
    }
    for (auto file : state.load_files)
    {
        cout << file->getURL() << endl;
    }
}

Command_WorkSpace::Command_WorkSpace(std::string raw_para, std::vector<std::string> para) : Command(raw_para, para, CommandType::kWs)
{
    add2HistoryStack = false;
    canUndo = false;
}