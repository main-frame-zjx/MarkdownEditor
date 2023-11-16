
#include <ParamUtil.h>
#include <iostream>
#include <Windows.h>

using std::wstring, std::vector;
int getIntParam(const vector<wstring> &para, int index)
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

int tryGetIntParam(const vector<wstring> &para, int index)
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

wstring getStrParam(const vector<wstring> &para, int index)
{
    // 检查索引是否越界
    if (index < 0 || index >= static_cast<int>(para.size()))
    {
        std::cerr << "Error: Index out of range." << std::endl;
        return wstring(L"");
    }
    return para[index];
}

wstring tryGetStrParam(const vector<wstring> &para, int index)
{
    // 检查索引是否越界
    if (index < 0 || index >= static_cast<int>(para.size()))
    {
        return wstring(L"");
    }
    return para[index];
}

wstring getLongStrParam(const wstring &str, int index)
{
    char delim = ' ';
    auto lastPos = str.find_first_not_of(delim, 0);
    auto pos = str.find_first_of(delim, lastPos);
    for (int i = 0; i < index; i++)
    {
        lastPos = str.find_first_not_of(delim, pos);
        pos = str.find_first_of(delim, lastPos);
        if (lastPos == wstring::npos)
            return L"";
    }
    return str.substr(lastPos, str.length() - lastPos);
}
// int getIntParam(const wstring &str, int index)
// {
//     wstring lastStr;
//     auto lastPos = str.find_first_not_of(' ', 0);
//     auto pos = str.find_first_of(' ', lastPos);
//     for (int i = 0; i < index; i++)
//     {
//     }
// }

vector<wstring> stringSplit(const wstring &str, char delim)
{
    vector<wstring> elems;
    auto lastPos = str.find_first_not_of(delim, 0);
    auto pos = str.find_first_of(delim, lastPos);
    while (lastPos != wstring::npos)
    {
        elems.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delim, pos);
        pos = str.find_first_of(delim, lastPos);
    }
    return elems;
}

std::string wstring2string(const std::wstring &wstr)
{
    std::string result;
    // 获取缓冲区大小，并申请空间，缓冲区大小事按字节计算的
    int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
    char *buffer = new char[len + 1];
    // 宽字节编码转换成多字节编码
    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
    buffer[len] = '\0';
    // 删除缓冲区并返回值
    result.append(buffer);
    delete[] buffer;
    return result;
}
