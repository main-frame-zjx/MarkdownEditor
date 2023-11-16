#pragma once
#include <MarkDownComponent.h>
class MarkDownBody : public MarkDownComponent
{
private:
    std::wstring content;
    std::wstring prefix;

public:
    MarkDownBody(std::wstring raw_str);
    virtual std::list<MarkDownComponent *> getChildrenList() override;
    ~MarkDownBody();
    virtual bool hasChild() override;
    virtual void addChild(MarkDownComponent *) override {}
    virtual std::wstring getForShowStr() override;
    virtual std::wstring getStr(bool raw) override;
    virtual bool hasStr() override;
    virtual bool isHigherThan(MarkDownComponent *) override;
    virtual void flushChildrenList() override {}
};