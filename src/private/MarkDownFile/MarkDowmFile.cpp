#include <MarkDownFile.h>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <MarkDownRoot.h>
#include <MarkDownTitle.h>
#include <MarkDownBody.h>
#include <iostream>
#include <string>
#include <algorithm>
using std::cout, std::endl;
using std::chrono::system_clock;
MarkDownFile::MarkDownFile(std::string url_in) : dirty(true), url(url_in), file_start_time(system_clock::now())
{
    std::fstream inFile;
    list_root = new MarkDownRoot();
    tree_root = new MarkDownRoot();
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
    updateTree();
    listSubTree(tree_root, 0, 0);
}
void MarkDownFile::listDirTree(std::string word)
{
    updateTree();
    MarkDownComponent *comp = searchComp(word);
    if (comp == nullptr)
    {
        std::cout << "didn't find '" << word << "' in file." << std::endl;
        return;
    }
    listSubTree(comp, 1, 0);
}
// flag的第i位表示之前第i层是不是中间
static std::string getListStr(MarkDownComponent *comp, int deep, int flag)
{
    assert(deep > 0);
    std::string ret = "";
    for (int i = 0; i < deep - 1; i++)
    {
        if (flag & (1 << i))
            ret += "| ";
        else
            ret += "  ";
    }
    if (flag & (1 << (deep - 1)))
        ret += "├─";
    else
        ret += "└─";
    ret += comp->getForShowStr();
    return ret;
}
void MarkDownFile::listSubTree(MarkDownComponent *comp, int deep, int flag)
{
    if (comp->hasStr())
        std::cout << getListStr(comp, deep, flag) << std::endl;
    if (!comp->hasChild())
        return;
    for (auto child_comp : comp->getChildrenList())
    {
        if (child_comp == comp->getChildrenList().back())
        {
            listSubTree(child_comp, deep + 1, flag);
        }
        else
        {
            listSubTree(child_comp, deep + 1, flag | (1 << deep));
        }
    }
}

void MarkDownFile::updateTree()
{
    MarkDownComponent *current_father = tree_root;
    current_father->flushChildrenList();
    for (auto comp : list_root->getChildrenList())
    {
        // 1.一直向上找得到当前comp的父节点
        while (!current_father->isHigherThan(comp))
        {
            current_father = current_father->parent;
        }
        comp->parent = current_father;
        current_father->addChild(comp);
        current_father = comp;
        current_father->flushChildrenList();
    }
}

MarkDownComponent *MarkDownFile::searchComp(std::string word)
{
    std::cout << "in searchComp, word: " << word << std::endl;
    for (auto comp : list_root->getChildrenList())
    {
        if (!comp->hasStr())
            continue;
        auto str_cp = comp->getStr(false);
        str_cp.erase(std::remove_if(str_cp.begin(), str_cp.end(), ::isspace), str_cp.end());
        if (str_cp == word)
            return comp;
    }
    return nullptr;
}