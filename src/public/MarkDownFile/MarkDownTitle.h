#pragma once
#include <MarkDownComponent.h>
class MarkDownTitle : public MarkDownComponent
{
private:
    std::list<MarkDownComponent *> childrenList;
    std::string content;
    std::string prefix;
    int titleLevel;

public:
    MarkDownTitle(std::string raw_str);
    virtual int getSpaceLine() override;
    virtual std::list<MarkDownComponent *> getChildrenList() override;
    ~MarkDownTitle();
    virtual bool hasChild() override;
    virtual std::string getStr(bool raw) override;
    virtual bool hasStr() override;
};