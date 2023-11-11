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
  kWs
};

class Command
{
protected:
  CommandType type;
  bool add2HistoryStack;
  std::vector<std::string> para;
  std::string raw_para;

public:
  virtual void exec(EditorState &state) = 0;
  virtual void undo(EditorState &state);
  bool getAdd2HistoryStack() { return add2HistoryStack; }
  Command(std::string raw_para, std::vector<std::string> para, CommandType type);
  CommandType getType() { return type; }
};