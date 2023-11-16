#pragma once
#include <string>
#include <vector>

int getIntParam(const std::vector<std::string> &para, int index);
int tryGetIntParam(const std::vector<std::string> &para, int index);
std::string getStrParam(const std::vector<std::string> &para, int index);
std::string tryGetStrParam(const std::vector<std::string> &para, int index);
std::string getLongStrParam(const std::string &para, int index);
// int getIntParam(const std::string &para, int index);
std::vector<std::string> stringSplit(const std::string &str, char delim);