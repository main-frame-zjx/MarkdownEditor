#pragma once
#include <MarkDownComponent.h>
class MarkDownRoot : public MarkDownComponent
{
private:
    std::list<MarkDownComponent *> childrenList;

public:
    MarkDownRoot();
    virtual int getSpaceLine() override;
    virtual std::list<MarkDownComponent *> getChildrenList() override;
    ~MarkDownRoot();
    virtual bool hasChild() override;
    virtual std::string getStr(bool raw) override;
    virtual bool hasStr() override;
    bool insertWord(int line, MarkDownComponent *);
    void deleteLine(int line, std::string *store = nullptr);
    void deleteWord(std::string word, int *store_line = nullptr, std::string *store_word = nullptr);
};