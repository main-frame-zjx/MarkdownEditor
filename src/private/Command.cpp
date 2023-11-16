#include "Command.h"
#include <string>
#include <iostream>
#include <EditorState.h>
void Command::undo(EditorState &state)
{
    return;
}

Command::Command(std::wstring raw_para, std::vector<std::wstring> para, CommandType type) : raw_para(raw_para),
                                                                                          para(para),
                                                                                          type(type),
                                                                                          succ(true)
{
}

void Command::errorDown(std::wstring info)
{
    std::wcout << info << std::endl;
    succ = false;
}

void Command::exec_wrapper(EditorState &state)
{
    state.notifyBeforeExec(this);
    this->exec(state);
    if (add2HistoryStack)
    {
        state.command_history_push_back(this);
    }
    state.notifyAfterExec(this);
}