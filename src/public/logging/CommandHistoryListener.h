#pragma once
#include <iostream>
#include <fstream>
#include "LogListenerBase.h"

class Command;
class CommandHistoryListener : public LogListenerBase
{
private:
    std::fstream logFile;

public:
    CommandHistoryListener(std::string logPath);
    ~CommandHistoryListener();
    virtual void notifyAfterExec(Command *cmd) override;
};