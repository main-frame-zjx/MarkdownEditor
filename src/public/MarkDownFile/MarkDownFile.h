#pragma once
#include <string>
#include <MarkDownRoot.h>
#include <chrono>
class MarkDownFile
{
private:
    bool dirty;
    std::string url;
    MarkDownRoot *list_root;
    // MarkDownRoot *tree_root;
    MarkDownComponent *str2Comp(std::string);
    std::chrono::system_clock::time_point file_start_time;

public:
    MarkDownFile(std::string url_in);
    ~MarkDownFile();
    void save();
    std::string getURL() { return url; }
    bool isDirty() { return dirty; }
    // line = -1表示最后一行
    void insertWord(int line, std::string word);
    // line = -1表示最后一行
    void deleteLine(int line, std::string *store = nullptr);
    void deleteWord(std::string word, int *store_line = nullptr, std::string *store_word = nullptr);
    void list();
    void listTree();
    void listDirTree(std::string word);
    std::chrono::system_clock::time_point getFileStartTime() { return file_start_time; }
};