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
    std::string getURL() { return url; }
    bool isDirty() { return dirty; }
    // line = -1表示最后一行
    void insertWord(int line, std::string word);
    // line = -1表示最后一行
    void deleteLine(int line, std::string *store = nullptr);
    void deleteWord(std::string word, int *store_line = nullptr);
};