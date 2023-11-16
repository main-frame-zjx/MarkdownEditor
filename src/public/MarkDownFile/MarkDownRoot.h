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
    virtual std::wstring getStr(bool raw) override;
    virtual std::wstring getForShowStr() override;
    virtual bool hasStr() override;
    virtual bool isHigherThan(MarkDownComponent *) override;
    virtual void flushChildrenList() override;
    bool insertWord(int line, MarkDownComponent *);
    void deleteLine(int line, std::wstring *store = nullptr);
    void deleteWord(std::wstring word, int *store_line = nullptr, std::wstring *store_word = nullptr);
};