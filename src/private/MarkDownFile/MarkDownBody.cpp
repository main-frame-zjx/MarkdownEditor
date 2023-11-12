#include <MarkDownBody.h>
#include <iostream>
std::list<MarkDownComponent *> MarkDownBody::getChildrenList()
{
    return std::list<MarkDownComponent *>();
}

MarkDownBody::~MarkDownBody()
{
}
bool MarkDownBody::hasChild()
{
    return false;
}
std::string MarkDownBody::getStr(bool raw)
{
    if (raw)
        return prefix + content;
    else
        return content;
}
bool MarkDownBody::hasStr()
{
    return true;
}

MarkDownBody::MarkDownBody(std::string raw_str) : MarkDownComponent(ComponentType::kBody)
{
    auto lastPos = raw_str.find_first_of(' ', 0);
    int len = raw_str.length();
    if (lastPos >= len)
        lastPos = len;
    prefix = raw_str.substr(0, lastPos);
    content = raw_str.substr(lastPos, len - lastPos);
}

int MarkDownBody::getSpaceLine()
{
    return 1;
}