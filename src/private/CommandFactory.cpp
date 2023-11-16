#include "CommandFactory.h"
#include "Command.h"
#include "Command_Exit.h"
#include "Command_Load.h"
#include "Command_WorkSpace.h"
#include "Command_Switch.h"
#include "Command_Save.h"
#include "Command_Insert.h"
#include "Command_AppendHead.h"
#include "Command_AppendTail.h"
#include "Command_List.h"
#include "Command_Delete.h"
#include "Command_Undo.h"
#include "Command_Redo.h"
#include "Command_Null.h"
#include "Command_History.h"
#include "Command_Stats.h"
#include "Command_Close.h"
#include "Command_ListTree.h"
#include "Command_DirTree.h"
#include "ParamUtil.h"

Command *CommandFactory::GetCommand(std::string raw_para)
{
    std::vector<std::string> para = stringSplit(raw_para, ' ');
    if (para[0] == std::string("load"))
    {
        return new Command_Load(raw_para, para);
    }
    else if (para[0] == std::string("ws"))
    {
        return new Command_WorkSpace(raw_para, para);
    }
    else if (para[0] == std::string("switch"))
    {
        return new Command_Switch(raw_para, para);
    }
    else if (para[0] == std::string("save"))
    {
        return new Command_Save(raw_para, para);
    }
    else if (para[0] == std::string("insert"))
    {
        return new Command_Insert(raw_para, para);
    }
    else if (para[0] == std::string("append-head"))
    {
        return new Command_AppendHead(raw_para, para);
    }
    else if (para[0] == std::string("append-tail"))
    {
        return new Command_AppendTail(raw_para, para);
    }
    else if (para[0] == std::string("delete"))
    {
        return new Command_Delete(raw_para, para);
    }
    else if (para[0] == std::string("undo"))
    {
        return new Command_Undo(raw_para, para);
    }
    else if (para[0] == std::string("redo"))
    {
        return new Command_Redo(raw_para, para);
    }
    else if (para[0] == std::string("list"))
    {
        return new Command_List(raw_para, para);
    }
    else if (para[0] == std::string("exit"))
    {
        return new Command_Exit(raw_para, para);
    }
    else if (para[0] == std::string("history"))
    {
        return new Command_History(raw_para, para);
    }
    else if (para[0] == std::string("stats"))
    {
        return new Command_Stats(raw_para, para);
    }
    else if (para[0] == std::string("list-tree"))
    {
        return new Command_ListTree(raw_para, para);
    }
    else if (para[0] == std::string("dir-tree"))
    {
        return new Command_DirTree(raw_para, para);
    }
    else if (para[0] == std::string("close"))
    {
        return new Command_Close(raw_para, para);
    }
    return new Command_Null(raw_para, para);
}