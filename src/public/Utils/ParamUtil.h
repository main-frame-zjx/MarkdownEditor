#pragma once
#include <string>
#include <vector>

int getIntParam(const std::vector<std::wstring> &para, int index);
int tryGetIntParam(const std::vector<std::wstring> &para, int index);
std::wstring getStrParam(const std::vector<std::wstring> &para, int index);
std::wstring tryGetStrParam(const std::vector<std::wstring> &para, int index);
std::wstring getLongStrParam(const std::wstring &para, int index);
// int getIntParam(const std::wstring &para, int index);
std::vector<std::wstring> stringSplit(const std::wstring &str, char delim);
std::string wstring2string(const std::wstring &wstr);