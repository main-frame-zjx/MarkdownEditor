#include <MarkDownFile.h>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <MarkDownRoot.h>
#include <MarkDownTitle.h>
#include <MarkDownBody.h>
#include <iostream>
#include <string>
using std::cout, std::endl;
using std::chrono::system_clock;
MarkDownFile::MarkDownFile(std::string url_in) : dirty(true), url(url_in), file_start_time(system_clock::now())
{
    std::fstream inFile;
    list_root = new MarkDownRoot();
    inFile.open(url, std::ios::in);
    if (!inFile)
    {
        // 如果文件未创建，创建空文件
        inFile.open(url, std::ios::out);
        inFile.close();
        inFile.open(url, std::ios::in);
    }
    assert(inFile);
    while (!inFile.eof())
    {
        std::string str;
        std::getline(inFile, str);
        if (str.empty())
            continue;
        insertWord(-1, str);
    }

    inFile.close();

    // tree_root = new MarkDownRoot();
}

MarkDownComponent *MarkDownFile::str2Comp(std::string str)
{
    MarkDownComponent *ret = nullptr;
    if (str[0] == '#')
        ret = new MarkDownTitle(str);
    else
        ret = new MarkDownBody(str);
    return ret;
}

MarkDownFile::~MarkDownFile()
{
    delete list_root;
}

void MarkDownFile::save()
{
    dirty = false;
    std::fstream inFile;
    inFile.open(url, std::ios::out);
    for (auto comp : list_root->getChildrenList())
    {
        inFile << comp->getStr(true) << std::endl;
    }
    inFile.close();
}

void MarkDownFile::insertWord(int line, std::string word)
{
    dirty = true;
    MarkDownComponent *new_line = str2Comp(word);
    list_root->insertWord(line, new_line);
}
void MarkDownFile::deleteLine(int line, std::string *store)
{
    dirty = true;
    list_root->deleteLine(line, store);
}
void MarkDownFile::deleteWord(std::string word, int *store_line, std::string *store_word)
{
    dirty = true;
    list_root->deleteWord(word, store_line, store_word);
}

void MarkDownFile::list()
{
    for (auto comp : list_root->getChildrenList())
    {
        cout << comp->getStr(true) << endl;
    }
}
void MarkDownFile::listTree()
{
}
void MarkDownFile::listDirTree(std::string word)
{
}