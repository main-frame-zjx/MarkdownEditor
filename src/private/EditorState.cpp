#include "EditorState.h"
#include "LogListenerBase.h"

void EditorState::command_history_push_back(Command *cmd) { command_history.push_back(cmd); }
bool EditorState::command_history_empty() { return command_history.empty(); }
Command *EditorState::command_history_back() { return command_history.back(); }
void EditorState::addListener(LogListenerBase *listener)
{
    listeners.push_back(listener);
}

void EditorState::notifyBeforeExec(Command *cmd)
{
    for (auto listener : listeners)
        listener->notifyBeforeExec(cmd, *this);
}
void EditorState::notifyAfterExec(Command *cmd)
{
    for (auto listener : listeners)
        listener->notifyAfterExec(cmd, *this);
}

EditorState::EditorState()
{
}