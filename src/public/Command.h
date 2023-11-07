#pragma once
//#include <bits/stdc++.h>
#include <vector>
#include <string>

enum CommandType {
  kAppendHead,
  kAppendTail,
  kInsert,
  kDelete,
  kLoad,
  kSave,
  kSwitch,
  kClose,
  kUndo,
  kRedo,
  kList,
  kListTree,
  kDirTree,
  kHistory,
  kStats,
  kExit
};

class Command{
protected:
    bool add2HistoryStack;
    std::vector<std::string> para;

public:
    virtual void exec() = 0;
    virtual void undo();
    bool getAdd2HistoryStack(){ return add2HistoryStack;}
};