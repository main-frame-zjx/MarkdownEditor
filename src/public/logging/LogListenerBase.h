#pragma once
class Command;
class LogListenerBase
{
public:
    virtual ~LogListenerBase() {}
    virtual void notifyBeforeExec(Command *cmd){};
    virtual void notifyAfterExec(Command *cmd){};
};