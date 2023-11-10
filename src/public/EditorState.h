#pragma once
#include <deque>
#include <vector>

class Command;
class MarkDownFile;
class EditorState
{
public:
    std::deque<Command *> command_history;
    std::deque<Command *> undo_cache;
    std::vector<MarkDownFile *> load_files;
    int current_focus_file;
};