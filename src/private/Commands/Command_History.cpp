#include "Command_History.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include <fstream>
#include <iostream>

using std::wstring, std::vector;
void Command_History::exec(EditorState &state)
{
    int his_num = tryGetIntParam(para, 1);
    if (his_num < 0)
        his_num = -1;
    std::wfstream logFile("command_history.txt", std::ios::in);
    vector<wstring> logEntry;
    wstring str;
    int count = 0;

    while (std::getline(logFile, str))
    {
        logEntry.push_back(str);
        count++;
    }
    int start = count - his_num;
    if (his_num == -1 || start < 0)
        start = 0;
    for (int i = start; i < count; i++)
    {
        std::wcout << "line: " << i + 1 << " , " << logEntry[i] << std::endl;
    }
    logFile.close();
}

Command_History::Command_History(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kList)
{
    add2HistoryStack = false;
    canUndo = false;
}