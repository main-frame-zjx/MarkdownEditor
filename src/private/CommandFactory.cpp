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

Command *CommandFactory::GetCommand(std::vector<std::string> para)
{
    if (para[0] == std::string("load"))
    {
        return new Command_Load(para);
    }
    else if (para[0] == std::string("ws"))
    {
        return new Command_WorkSpace(para);
    }
    else if (para[0] == std::string("switch"))
    {
        return new Command_Switch(para);
    }
    else if (para[0] == std::string("save"))
    {
        return new Command_Save(para);
    }
    else if (para[0] == std::string("insert"))
    {
        return new Command_Insert(para);
    }
    else if (para[0] == std::string("append-head"))
    {
        return new Command_AppendHead(para);
    }
    else if (para[0] == std::string("delete"))
    {
        return new Command_Delete(para);
    }
    else if (para[0] == std::string("undo"))
    {
        return new Command_Undo(para);
    }
    else if (para[0] == std::string("redo"))
    {
        return new Command_Redo(para);
    }
    return new Command_Exit(para);
}