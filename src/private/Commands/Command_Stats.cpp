#include "Command_Stats.h"
#include "EditorState.h"
#include "MarkDownFile.h"
#include "ParamUtil.h"
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <iostream>
using std::wstring, std::vector;
using std::chrono::system_clock, std::wstring;

static std::wstring duration_time(system_clock::time_point startTime, system_clock::time_point endTime)
{
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    int hour = 0, min = 0, sec = 0;
    std::wstring ret;
    if (duration.count() >= 3600)
    {
        auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
        hour = hours.count();
        duration -= hours;
        if (hour > 0)
            ret += std::to_wstring(hour) + wstring(L" 小时 ");
    }

    if (duration.count() >= 60)
    {
        auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
        min = minutes.count();
        duration -= minutes;
        if (min > 0)
            ret += std::to_wstring(min) + wstring(L" 分钟 ");
    }

    sec = duration.count();
    ret += std::to_wstring(sec) + wstring(L" 秒 ");

    return ret;
}

void Command_Stats::exec(EditorState &state)
{
    wstring str = tryGetStrParam(para, 1);
    if (str == L"all")
    {
        for (auto file : state.load_files)
        {
            wstring duration = duration_time(file->getFileStartTime(), system_clock::now());
            std::wcout << file->getURL() << " "
                       << duration << std::endl;
        }
    }
    else
    {
        if (state.load_files.size() == 0)
            return;
        wstring duration = duration_time(state.load_files[state.current_focus_file]->getFileStartTime(), system_clock::now());
        std::wcout << state.load_files[state.current_focus_file]->getURL() << " "
                   << duration << std::endl;
    }
}

Command_Stats::Command_Stats(wstring raw_para, vector<wstring> para) : Command(raw_para, para, CommandType::kList)
{
    add2HistoryStack = false;
    canUndo = false;
}