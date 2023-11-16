#pragma once
#include <iostream>
#include <fstream>
#include "LogListenerBase.h"

class Command;
class CommandHistoryListener : public LogListenerBase
{
private:
    std::wfstream logFile;

public:
    CommandHistoryListener(std::wstring logPath);
    ~CommandHistoryListener();
    virtual void notifyAfterExec(Command *cmd, EditorState &state) override;
};