#pragma once
#include <vector>
#include <string>
class Command;

class CommandFactory
{
public:
    static Command *GetCommand(std::string raw_para);
};