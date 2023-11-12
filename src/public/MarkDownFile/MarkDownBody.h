#pragma once
#include <MarkDownComponent.h>
class MarkDownBody : public MarkDownComponent
{
private:
    std::string content;
    std::string prefix;

public:
    MarkDownBody(std::string raw_str);
    virtual int getSpaceLine() override;
    virtual std::list<MarkDownComponent *> getChildrenList() override;
    ~MarkDownBody();
    virtual bool hasChild() override;
    virtual std::string getStr(bool raw) override;
    virtual bool hasStr() override;
};