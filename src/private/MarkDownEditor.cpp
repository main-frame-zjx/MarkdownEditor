#include "MarkDownEditor.h"
#include <iostream>
#include "Command.h"
#include "CommandFactory.h"
#include "CommandHistoryListener.h"
#include "FileHistoryListener.h"
#include <locale>
#include <string>
using std::endl;
using std::wcin, std::wcout;
using std::wstring;

void MarkDownEditor::Launch()
{
    std::wcout.imbue(std::locale());
    state.addListener(new CommandHistoryListener(L"command_history.txt"));
    state.addListener(new FileHistoryListener(L"file_history.txt"));
    while (true)
    {

        wstring line;
        if (wcin.eof())
            break;
        std::getline(wcin, line);

        Command *cmd = CommandFactory::GetCommand(line);

        cmd->exec_wrapper(state);
    }
}

MarkDownEditor::MarkDownEditor()
{
    ;
}
