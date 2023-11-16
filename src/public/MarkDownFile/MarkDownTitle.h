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
    virtual std::list<MarkDownComponent *> getChildrenList() override;
    ~MarkDownTitle();
    virtual bool hasChild() override;
    virtual void addChild(MarkDownComponent *) override;
    virtual std::string getStr(bool raw) override;
    virtual std::string getForShowStr() override;
    virtual bool hasStr() override;
    virtual bool isHigherThan(MarkDownComponent *) override;
    int getTitleLevel() { return titleLevel; }
    virtual void flushChildrenList() override;
};