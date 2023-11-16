#pragma once
#include <string>
#include <list>

enum ComponentType
{
    kRoot,
    kTitle,
    kBody
};

class MarkDownComponent
{

public:
    MarkDownComponent *parent;
    ComponentType type;
    MarkDownComponent(ComponentType type, MarkDownComponent *parent) : type(type), parent(parent) {}
    MarkDownComponent(ComponentType type) : type(type), parent(nullptr) {}
    virtual ~MarkDownComponent() {}
    virtual std::list<MarkDownComponent *> getChildrenList() = 0;
    virtual void addChild(MarkDownComponent *) = 0;
    virtual bool hasChild() = 0;
    virtual std::wstring getStr(bool raw) = 0;
    virtual std::wstring getForShowStr() = 0;
    virtual bool hasStr() = 0;
    virtual bool isHigherThan(MarkDownComponent *) = 0;
    virtual void flushChildrenList() = 0;
    // virtual void insertWord(int line, MarkDownComponent *comp) = 0;
    // virtual void deleteLine(int line, std::wstring *store = nullptr) = 0;
    // virtual void deleteWord(std::wstring word, int *store_line = nullptr) = 0;
};