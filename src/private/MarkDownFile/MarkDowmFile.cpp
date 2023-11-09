#include <MarkDownFile.h>
#include <iostream>
#include <fstream>
#include <assert.h>

MarkDownFile::MarkDownFile(std::string url_in) : dirty(false), url(url_in)
{
    std::fstream inFile;
    // 如果文件未创建，创建空文件
    inFile.open(url, std::ios::out);
    inFile.close();

    inFile.open(url, std::ios::in);
    assert(inFile);

    inFile.close();
}

void MarkDownFile::save()
{
}