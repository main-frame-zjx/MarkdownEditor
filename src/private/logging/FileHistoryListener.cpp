#include "FileHistoryListener.h"
#include "Command.h"
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>
#include <memory>
#include "ParamUtil.h"
#include "MarkDownFile.h"
#include "EditorState.h"

using std::chrono::system_clock, std::string;

static std::string current_time()
{
    system_clock::time_point tp = system_clock::now();

    time_t raw_time = system_clock::to_time_t(tp);

    // tm*使用完后不用delete，因为tm*是由localtime创建的，并且每个线程中会有一个
    struct tm *timeinfo = std::localtime(&raw_time);

    char buf[24] = {0};
    // 标准c++中也可以使用"%F %X,"，但VC2017中不能这样用
    strftime(buf, 24, "%Y-%m-%d %H:%M:%S,", timeinfo);

    // tm只能到秒，毫秒需要另外获取
    // std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());

    // std::string milliseconds_str = std::to_string(ms.count() % 1000);

    // if (milliseconds_str.length() < 3)
    // {
    //     milliseconds_str = std::string(3 - milliseconds_str.length(), '0') + milliseconds_str;
    // }

    // return std::string(buf) + milliseconds_str;
    return std::string(buf);
}

std::string duration_time(system_clock::time_point startTime, system_clock::time_point endTime)
{
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    int hour = 0, min = 0, sec = 0;
    std::string ret;
    if (duration.count() >= 3600)
    {
        auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
        hour = hours.count();
        duration -= hours;
        if (hour > 0)
            ret += std::to_string(hour) + string(" 小时 ");
    }

    if (duration.count() >= 60)
    {
        auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
        min = minutes.count();
        duration -= minutes;
        if (min > 0)
            ret += std::to_string(min) + string(" 分钟 ");
    }

    sec = duration.count();
    ret += std::to_string(sec) + string(" 秒 ");

    return ret;
}

FileHistoryListener::FileHistoryListener(std::string logPath) : logFile(logPath, std::ios::app)
{
    if (!logFile.is_open())
    {
        std::cerr << "Error opening log file: " << logPath << std::endl;
    }
    else
    {
        logFile << "session start at " << current_time() << std::endl;
    }
}

void FileHistoryListener::notifyBeforeExec(Command *cmd, EditorState &state)
{
    // Record the current time and command type in the log file
    if (cmd->getType() == CommandType::kClose)
    {
        int close_index = getIntParam(cmd->getPara(), 1) - 1;
        if (close_index < 0)
        {
            return;
        }
        if (close_index >= state.load_files.size())
        {
            return;
        }
        string duration = duration_time(state.load_files[close_index]->getFileStartTime(), system_clock::now());
        logFile << state.load_files[close_index]->getURL() << " "
                << duration << std::endl;
    }
    if (cmd->getType() == CommandType::kExit)
    {
        for (auto file : state.load_files)
        {
            string duration = duration_time(file->getFileStartTime(), system_clock::now());
            logFile << file->getURL() << " "
                    << duration << std::endl;
        }
    }
}

FileHistoryListener::~FileHistoryListener()
{
    logFile.close();
}