#pragma once
#include <deque>

class Command;
class EditorState
{
    std::deque<Command *> command_history;
    std::deque<Command *> undo_cache;
};