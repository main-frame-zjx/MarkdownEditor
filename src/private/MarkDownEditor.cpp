#include "MarkDownEditor.h"
#include <iostream>
#include "Command.h"
#include "CommandFactory.h"
using std::cin;
using std::endl;
using std::string;
using std::vector;
vector<string> stringSplit(const string &str, char delim);

void MarkDownEditor::Launch()
{
    while (true)
    {
        string line;
        getline(cin, line);
        vector<string> para = stringSplit(line, ' ');
        Command *cmd = CommandFactory::GetCommand(para);
        cmd->exec(state);
        // if (cmd->getAdd2HistoryStack())
        // {
        //     command_history.push_back(cmd);
        // }
        // else
        // {
        //     delete cmd;
        // }
    }
}

MarkDownEditor::MarkDownEditor()
{
    ;
}

vector<string> stringSplit(const string &str, char delim)
{
    vector<string> elems;
    auto lastPos = str.find_first_not_of(delim, 0);
    auto pos = str.find_first_of(delim, lastPos);
    while (pos != string::npos || lastPos != string::npos)
    {
        elems.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delim, pos);
        pos = str.find_first_of(delim, lastPos);
    }
    return elems;
}