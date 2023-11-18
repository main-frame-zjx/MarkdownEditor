#pragma once
#include "EditorState.h"

class MarkDownEditor
{
private:
    EditorState state;

public:
    MarkDownEditor(bool logging = true);
    void Launch();
    void exex_command(std::string str);
};