#pragma once
#include "Command.h"
#include "CommandFactory.h"
#include <deque>
#include <iostream>


class MarkDownEditor{
private:
    std::deque<Command*> command_history;
    std::deque<Command*> undo_cache;

public:
    MarkDownEditor();
    void Launch();
};