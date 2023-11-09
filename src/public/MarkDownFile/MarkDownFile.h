#pragma once
#include <string>

class MarkDownFile
{
private:
    bool dirty;
    std::string url;

public:
    MarkDownFile(std::string url_in);
    void save();
};