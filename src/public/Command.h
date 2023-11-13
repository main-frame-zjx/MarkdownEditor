#pragma once
// #include <bits/stdc++.h>
#include <vector>
#include <string>

class EditorState;

enum CommandType
{
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
  kExit,
  kWs,
  kNull
};

class Command
{
protected:
  CommandType type;
  bool add2HistoryStack = true;
  bool canUndo = false;
  std::vector<std::string> para;
  std::string raw_para;
  bool succ;
  virtual void exec(EditorState &state) = 0;

public:
  void exec_wrapper(EditorState &state);
  virtual void undo(EditorState &state);
  bool getAdd2HistoryStack() { return add2HistoryStack; }
  bool getSucc() { return succ; }
  bool getCanUndo() { return canUndo; }
  Command(std::string raw_para, std::vector<std::string> para, CommandType type);
  CommandType getType() { return type; }
  void errorDown(std::string info);
  std::string getRawPara() { return raw_para; }
};