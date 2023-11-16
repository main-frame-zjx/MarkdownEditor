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
#include "Command_ListTree.h"
#include "Command_DirTree.h"
#include "ParamUtil.h"

Command *CommandFactory::GetCommand(std::wstring raw_para)
{
    std::vector<std::wstring> para = stringSplit(raw_para, ' ');
    if (para[0] == std::wstring(L"load"))
    {
        return new Command_Load(raw_para, para);
    }
    else if (para[0] == std::wstring(L"ws"))
    {
        return new Command_WorkSpace(raw_para, para);
    }
    else if (para[0] == std::wstring(L"switch"))
    {
        return new Command_Switch(raw_para, para);
    }
    else if (para[0] == std::wstring(L"save"))
    {
        return new Command_Save(raw_para, para);
    }
    else if (para[0] == std::wstring(L"insert"))
    {
        return new Command_Insert(raw_para, para);
    }
    else if (para[0] == std::wstring(L"append-head"))
    {
        return new Command_AppendHead(raw_para, para);
    }
    else if (para[0] == std::wstring(L"append-tail"))
    {
        return new Command_AppendTail(raw_para, para);
    }
    else if (para[0] == std::wstring(L"delete"))
    {
        return new Command_Delete(raw_para, para);
    }
    else if (para[0] == std::wstring(L"undo"))
    {
        return new Command_Undo(raw_para, para);
    }
    else if (para[0] == std::wstring(L"redo"))
    {
        return new Command_Redo(raw_para, para);
    }
    else if (para[0] == std::wstring(L"list"))
    {
        return new Command_List(raw_para, para);
    }
    else if (para[0] == std::wstring(L"exit"))
    {
        return new Command_Exit(raw_para, para);
    }
    else if (para[0] == std::wstring(L"history"))
    {
        return new Command_History(raw_para, para);
    }
    else if (para[0] == std::wstring(L"stats"))
    {
        return new Command_Stats(raw_para, para);
    }
    else if (para[0] == std::wstring(L"list-tree"))
    {
        return new Command_ListTree(raw_para, para);
    }
    else if (para[0] == std::wstring(L"dir-tree"))
    {
        return new Command_DirTree(raw_para, para);
    }
    return new Command_Null(raw_para, para);
}