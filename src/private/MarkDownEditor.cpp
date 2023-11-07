#include "MarkDownEditor.h"

void MarkDownEditor::Launch(){
    while (true)
    {
        Command* cmd = Command::nextCommand();
        cmd->exec();
        if(cmd->getAdd2HistoryStack()){
            command_history.push_back(cmd);
        } else{
            delete cmd;
        }

    }
    
}

MarkDownEditor::MarkDownEditor(){
    ;
}