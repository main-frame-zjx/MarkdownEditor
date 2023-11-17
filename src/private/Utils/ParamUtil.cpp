
#include <ParamUtil.h>
#include <iostream>
#include <exception>

using std::string, std::vector;
int getIntParam(const vector<string> &para, int index)
{
    // 检查索引是否越界
    if (index < 0 || index >= static_cast<int>(para.size()))
    {
        std::cerr << "Error: Index out of range." << std::endl;
        return -1;
    }

    try
    {
        return std::stoi(para[index]);
    }
    catch (const std::invalid_argument &e)
    {
        // 参数无法转换为整数，抛出 std::invalid_argument 异常
        std::cerr << "Error: Invalid argument. " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        // 转换超出目标类型的范围，抛出 std::out_of_range 异常
        std::cerr << "Error: Out of range. " << e.what() << std::endl;
    }

    // 转换失败，返回 -1
    return -1;
}

int tryGetIntParam(const vector<string> &para, int index)
{
    // 检查索引是否越界
    if (index < 0 || index >= static_cast<int>(para.size()))
    {
        // std::cerr << "Error: Index out of range." << std::endl;
        return -1;
    }

    try
    {
        return std::stoi(para[index]);
    }
    catch (const std::invalid_argument &e)
    {
        return -1;
    }
    catch (const std::out_of_range &e)
    {
        return -1;
    }

    // 转换失败，返回 -1
    return -1;
}

string getStrParam(const vector<string> &para, int index)
{
    // 检查索引是否越界
    if (index < 0 || index >= static_cast<int>(para.size()))
    {
        std::cerr << "Error: Index out of range." << std::endl;
        return string("");
    }
    return para[index];
}

string tryGetStrParam(const vector<string> &para, int index)
{
    // 检查索引是否越界
    if (index < 0 || index >= static_cast<int>(para.size()))
    {
        return string("");
    }
    return para[index];
}

string getLongStrParam(const string &str, int index)
{
    char delim = ' ';
    auto lastPos = str.find_first_not_of(delim, 0);
    auto pos = str.find_first_of(delim, lastPos);
    for (int i = 0; i < index; i++)
    {
        lastPos = str.find_first_not_of(delim, pos);
        pos = str.find_first_of(delim, lastPos);
        if (lastPos == string::npos)
            return "";
    }
    return str.substr(lastPos, str.length() - lastPos);
}
// int getIntParam(const string &str, int index)
// {
//     string lastStr;
//     auto lastPos = str.find_first_not_of(' ', 0);
//     auto pos = str.find_first_of(' ', lastPos);
//     for (int i = 0; i < index; i++)
//     {
//     }
// }

vector<string> stringSplit(const string &str, char delim)
{
    vector<string> elems;
    auto lastPos = str.find_first_not_of(delim, 0);
    auto pos = str.find_first_of(delim, lastPos);
    while (lastPos != string::npos)
    {
        elems.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delim, pos);
        pos = str.find_first_of(delim, lastPos);
    }
    return elems;
}