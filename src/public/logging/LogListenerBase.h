#pragma once
class EditorState;
class Command;
class LogListenerBase
{
public:
    virtual ~LogListenerBase() {}
    virtual void notifyBeforeExec(Command *cmd, EditorState &state){};
    virtual void notifyAfterExec(Command *cmd, EditorState &state){};
};