#pragma once
#include "Command.h"
#include <deque>


class MarkDownEditor{
private:
    std::deque<Command*> command_history;
    std::deque<Command*> undo_cache;

public:
    MarkDownEditor();
    void Launch();
};