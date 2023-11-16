#pragma once
#include <deque>
#include <vector>
// #include "LogListenerBase.h"
#include <chrono>
class Command;
class LogListenerBase;
class MarkDownFile;
class EditorState
{
private:
    std::vector<LogListenerBase *> listeners;
    std::deque<Command *> command_history;
    // std::chrono::system_clock::time_point editor_start_time;

public:
    std::vector<MarkDownFile *> load_files;
    int current_focus_file;
    void command_history_push_back(Command *cmd);
    bool command_history_empty();
    Command *command_history_back();
    void addListener(LogListenerBase *);
    void notifyBeforeExec(Command *);
    void notifyAfterExec(Command *);
    EditorState();
};