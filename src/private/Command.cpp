#include "Command.h"
#include <string>
#include <iostream>
#include <EditorState.h>
void Command::undo(EditorState &state)
{
    return;
}

Command::Command(std::string raw_para, std::vector<std::string> para, CommandType type) : raw_para(raw_para),
                                                                                          para(para),
                                                                                          type(type),
                                                                                          succ(true)
{
}

void Command::errorDown(std::string info)
{
    std::cout << info << std::endl;
    succ = false;
}

void Command::exec_wrapper(EditorState &state)
{
    this->exec(state);
    if (add2HistoryStack)
    {
        state.command_history.push_back(this);
    }
}