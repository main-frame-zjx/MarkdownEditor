#include "CommandHistoryListener.h"
#include "Command.h"
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>
#include <memory>

using std::chrono::system_clock;

std::string current_time()
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

// auto getFormatNowTime()
// {
//     // 获取当前系统时间点
//     auto now = std::chrono::system_clock::now();

//     // 将时间点转换为time_t类型
//     std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

//     // 使用std::put_time函数格式化时间
//     std::tm tmStruct = *std::localtime(&currentTime);

//     // 格式化日期和时间
//     return std::put_time(&tmStruct, "%Y%m%d %H:%M:%S");
// }

CommandHistoryListener::CommandHistoryListener(std::string logPath) : logFile(logPath, std::ios::app)
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

void CommandHistoryListener::notifyAfterExec(Command *cmd)
{
    // Record the current time and command type in the log file
    logFile << current_time() << " "
            << cmd->getRawPara() << (cmd->getSucc() ? " | succ" : " | fail") << std::endl;
}

CommandHistoryListener::~CommandHistoryListener()
{
    logFile.close();
}