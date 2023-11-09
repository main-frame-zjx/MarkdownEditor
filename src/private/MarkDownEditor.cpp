#include "MarkDownEditor.h"

void MarkDownEditor::Launch(){
    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        Command* cmd = CommandFactory::GetCommand();
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