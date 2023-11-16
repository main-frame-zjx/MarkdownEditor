#pragma once
#include <MarkDownComponent.h>
class MarkDownRoot : public MarkDownComponent
{
private:
    std::list<MarkDownComponent *> childrenList;

public:
    MarkDownRoot();
    virtual std::list<MarkDownComponent *> getChildrenList() override;
    ~MarkDownRoot();
    virtual bool hasChild() override;
    virtual void addChild(MarkDownComponent *) override;
    virtual std::string getStr(bool raw) override;
    virtual std::string getForShowStr() override;
    virtual bool hasStr() override;
    virtual bool isHigherThan(MarkDownComponent *) override;
    virtual void flushChildrenList() override;
    bool insertWord(int line, MarkDownComponent *);
    void deleteLine(int line, std::string *store = nullptr);
    void deleteWord(std::string word, int *store_line = nullptr, std::string *store_word = nullptr);
};