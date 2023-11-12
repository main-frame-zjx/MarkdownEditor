#include <MarkDownTitle.h>
#include <assert.h>
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
std::string MarkDownTitle::getStr(bool raw)
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

MarkDownTitle::MarkDownTitle(std::string raw_str) : MarkDownComponent(ComponentType::kTitle)
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

int MarkDownTitle::getSpaceLine()
{
    int ret = 1;
    for (auto child : childrenList)
    {
        ret += child->getSpaceLine();
    }
    return ret;
}