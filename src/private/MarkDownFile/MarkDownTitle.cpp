#include <MarkDownTitle.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
std::list<MarkDownComponent *> MarkDownTitle::getChildrenList()
{
    return childrenList;
}

MarkDownTitle::~MarkDownTitle()
{
    for (auto child : childrenList)
        delete child;
}
bool MarkDownTitle::hasChild()
{
    return true;
}
std::wstring MarkDownTitle::getStr(bool raw)
{
    if (raw)
        return prefix + content;
    else
        return content;
}
bool MarkDownTitle::hasStr()
{
    return true;
}

MarkDownTitle::MarkDownTitle(std::wstring raw_str) : MarkDownComponent(ComponentType::kTitle)
{
    assert(raw_str[0] == '#');
    auto lastPos = raw_str.find_first_not_of('#', 0);
    int len = raw_str.length();
    if (lastPos >= len)
        lastPos = len;
    prefix = raw_str.substr(0, lastPos);
    content = raw_str.substr(lastPos, len - lastPos);
    titleLevel = lastPos;
}

bool MarkDownTitle::isHigherThan(MarkDownComponent *comp)
{
    if (comp->type == ComponentType::kRoot)
    {
        std::wcout << "You can't compare MarkDownRoot to MarkDownTitle" << std::endl;
        return false;
    }
    else if (comp->type == ComponentType::kBody)
        return true;
    else
    {
        auto title_comp = dynamic_cast<MarkDownTitle *>(comp);
        return titleLevel < title_comp->getTitleLevel();
    }
}
void MarkDownTitle::addChild(MarkDownComponent *comp)
{
    childrenList.push_back(comp);
}

void MarkDownTitle::flushChildrenList()
{
    childrenList.clear();
}

std::wstring MarkDownTitle::getForShowStr()
{
    std::wstring str_cp = content;
    str_cp.erase(std::remove_if(str_cp.begin(), str_cp.end(), ::isspace), str_cp.end());
    return str_cp;
}
