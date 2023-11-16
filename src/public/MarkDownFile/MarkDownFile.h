#pragma once
#include <string>
#include <MarkDownRoot.h>
#include <chrono>
class MarkDownFile
{
private:
    bool dirty;
    std::wstring url;
    MarkDownRoot *list_root;
    MarkDownRoot *tree_root;
    MarkDownComponent *str2Comp(std::wstring);
    void updateTree();
    void listSubTree(MarkDownComponent *, int deep, int flag);
    MarkDownComponent *searchComp(std::wstring);
    std::chrono::system_clock::time_point file_start_time;

public:
    MarkDownFile(std::wstring url_in);
    ~MarkDownFile();
    void save();
    std::wstring getURL() { return url; }
    bool isDirty() { return dirty; }
    // line = -1表示最后一行
    void insertWord(int line, std::wstring word);
    // line = -1表示最后一行
    void deleteLine(int line, std::wstring *store = nullptr);
    void deleteWord(std::wstring word, int *store_line = nullptr, std::wstring *store_word = nullptr);
    void list();
    void listTree();
    void listDirTree(std::wstring word);
    std::chrono::system_clock::time_point getFileStartTime() { return file_start_time; }
};