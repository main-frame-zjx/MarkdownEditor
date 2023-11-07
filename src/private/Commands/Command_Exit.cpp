#include "Command_Exit.h"

void Command_Exit::exec(){
    exit(1);
}

Command_Exit::Command_Exit(){
    add2HistoryStack = false;
}