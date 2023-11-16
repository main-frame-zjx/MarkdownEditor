#pragma once
#include <MarkDownComponent.h>
class MarkDownBody : public MarkDownComponent
{
private:
    std::string content;
    std::string prefix;

public:
    MarkDownBody(std::string raw_str);
    virtual std::list<MarkDownComponent *> getChildrenList() override;
    ~MarkDownBody();
    virtual bool hasChild() override;
    virtual void addChild(MarkDownComponent *) override {}
    virtual std::string getForShowStr() override;
    virtual std::string getStr(bool raw) override;
    virtual bool hasStr() override;
    virtual bool isHigherThan(MarkDownComponent *) override;
    virtual void flushChildrenList() override {}
};