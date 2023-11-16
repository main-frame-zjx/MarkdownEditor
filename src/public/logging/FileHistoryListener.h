#pragma once
#include <iostream>
#include <fstream>
#include "LogListenerBase.h"

class Command;
class FileHistoryListener : public LogListenerBase
{
private:
    std::fstream logFile;

public:
    FileHistoryListener(std::string logPath);
    ~FileHistoryListener();
    virtual void notifyBeforeExec(Command *cmd, EditorState &state) override;
};