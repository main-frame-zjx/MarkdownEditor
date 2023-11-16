#pragma once
#include <MarkDownComponent.h>
class MarkDownTitle : public MarkDownComponent
{
private:
    std::list<MarkDownComponent *> childrenList;
    std::wstring content;
    std::wstring prefix;
    int titleLevel;

public:
    MarkDownTitle(std::wstring raw_str);
    virtual std::list<MarkDownComponent *> getChildrenList() override;
    ~MarkDownTitle();
    virtual bool hasChild() override;
    virtual void addChild(MarkDownComponent *) override;
    virtual std::wstring getStr(bool raw) override;
    virtual std::wstring getForShowStr() override;
    virtual bool hasStr() override;
    virtual bool isHigherThan(MarkDownComponent *) override;
    int getTitleLevel() { return titleLevel; }
    virtual void flushChildrenList() override;
};