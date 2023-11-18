#include "MarkDownEditor.h"
#include <iostream>
#include "Command.h"
#include "CommandFactory.h"
#include "CommandHistoryListener.h"
#include "FileHistoryListener.h"
#include <string>
using std::cin, std::wcout;
using std::endl;
using std::string;

void MarkDownEditor::Launch()
{

    while (!state.exit)
    {

        string line;
        if (cin.eof())
            break;
        std::getline(cin, line);

        Command *cmd = CommandFactory::GetCommand(line);

        cmd->exec_wrapper(state);
    }
}

MarkDownEditor::MarkDownEditor(bool logging)
{
    if (logging)
    {
        state.addListener(new CommandHistoryListener("command_history.txt"));
        state.addListener(new FileHistoryListener("file_history.txt"));
    }
}

void MarkDownEditor::exex_command(std::string str)
{
    Command *cmd = CommandFactory::GetCommand(str);
    cmd->exec_wrapper(state);
}
