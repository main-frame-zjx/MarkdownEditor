#include "MarkDownEditor.h"
#include <iostream>
#include "Command.h"
#include "CommandFactory.h"
#include "CommandHistoryListener.h"
using std::cin, std::cout;
using std::endl;
using std::string;

void MarkDownEditor::Launch()
{
    state.addListener(new CommandHistoryListener("command_history.txt"));
    while (true)
    {

        string line;
        if (cin.eof())
            break;
        getline(cin, line);

        Command *cmd = CommandFactory::GetCommand(line);

        cmd->exec_wrapper(state);
    }
}

MarkDownEditor::MarkDownEditor()
{
    ;
}
