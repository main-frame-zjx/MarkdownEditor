#include "Command.h"

void Command::undo(EditorState &state)
{
    return;
}

Command::Command(std::string raw_para, std::vector<std::string> para, CommandType type) : raw_para(raw_para),
                                                                                          para(para),
                                                                                          type(type)
{
}
