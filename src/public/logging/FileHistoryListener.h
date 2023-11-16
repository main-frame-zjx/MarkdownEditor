#pragma once
#include <iostream>
#include <fstream>
#include "LogListenerBase.h"

class Command;
class FileHistoryListener : public LogListenerBase
{
private:
    std::wfstream logFile;

public:
    FileHistoryListener(std::wstring logPath);
    ~FileHistoryListener();
    virtual void notifyBeforeExec(Command *cmd, EditorState &state) override;
};