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
    // 设置输出流的locale为UTF-8
    std::wcout.imbue(std::locale("en_US.UTF-8"));
    state.addListener(new CommandHistoryListener("command_history.txt"));
    state.addListener(new FileHistoryListener("file_history.txt"));
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
