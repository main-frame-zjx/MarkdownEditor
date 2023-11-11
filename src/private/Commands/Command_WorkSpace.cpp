#include "Command_WorkSpace.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "iostream"
using std::cout, std::endl;
void Command_WorkSpace::exec(EditorState &state)
{
    for (auto file : state.load_files)
    {
        cout << file->getURL() << endl;
    }
}

Command_WorkSpace::Command_WorkSpace(std::vector<std::string> para) : Command(para, CommandType::kWs)
{
    add2HistoryStack = true;
}