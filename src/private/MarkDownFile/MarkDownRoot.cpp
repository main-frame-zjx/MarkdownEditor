#include <MarkDownRoot.h>
#include <iostream>
#include <string>
#include <algorithm>
using std::string;
std::list<MarkDownComponent *>
MarkDownRoot::getChildrenList()
{
    return childrenList;
}

MarkDownRoot::~MarkDownRoot()
{
    for (auto child : childrenList)
        delete child;
}
bool MarkDownRoot::hasChild()
{
    return true;
}
std::string MarkDownRoot::getStr(bool raw)
{
    return "";
}
bool MarkDownRoot::hasStr()
{
    return false;
}

bool MarkDownRoot::insertWord(int line, MarkDownComponent *comp)
{
    if (line == -1)
        line = childrenList.size() + 1;
    if (line < 1 || line - 1 > childrenList.size())
        return false;
    auto pos = childrenList.begin();
    std::advance(pos, (line - 1));
    childrenList.insert(pos, comp);
    return true;
}

void MarkDownRoot::deleteLine(int line, std::string *store)
{
    if (line <= 0 || line - 1 >= childrenList.size())
    {
        std::cout << "Error: Index out of bounds." << std::endl; // 返回 end() 表示无效位置
        return;
    }
    auto pos = childrenList.begin();
    std::advance(pos, (line - 1));
    auto comp = *pos;
    childrenList.erase(pos);
    if (store)
        *store = comp->getStr(true);
    delete comp;
}

void MarkDownRoot::deleteWord(std::string word, int *store_line, std::string *store_word)
{
    int line = 1;
    for (auto it = childrenList.begin(); it != childrenList.end(); it++)
    {
        string str_cp = (*it)->getStr(false);
        // 去掉空格
        // str_cp = str_cp.substr(1, str_cp.length());
        str_cp.erase(std::remove_if(str_cp.begin(), str_cp.end(), ::isspace), str_cp.end());
        bool match = (str_cp == word);
        if (match)
        {
            if (store_word)
                *store_word = (*it)->getStr(true);
            if (store_line)
                *store_line = line;
            childrenList.erase(it);
            return;
        }
        line++;
    }
    std::cout << "not find word." << std::endl;
    // throw "not find word.";
}

MarkDownRoot::MarkDownRoot() : MarkDownComponent(ComponentType::kRoot)
{
}

bool MarkDownRoot::isHigherThan(MarkDownComponent *comp)
{
    if (comp->type == ComponentType::kRoot)
    {
        std::cout << "You can't compare two MarkDownRoot" << std::endl;
        return false;
    }
    return true;
}

void MarkDownRoot::addChild(MarkDownComponent *comp)
{
    childrenList.push_back(comp);
}

void MarkDownRoot::flushChildrenList()
{
    childrenList.clear();
}

std::string MarkDownRoot::getForShowStr()
{
    return "";
}