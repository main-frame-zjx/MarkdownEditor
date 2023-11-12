#include "MarkDownEditor.h"
#include <iostream>
#include "Command.h"
#include "CommandFactory.h"
using std::cin, std::cout;
using std::endl;
using std::string;

void MarkDownEditor::Launch()
{
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
