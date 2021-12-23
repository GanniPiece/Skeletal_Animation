#include "FileIn.hpp"

#include "Detail/Generals.hpp"

#include <fstream>

namespace FileIO
{

bool ReadFileFullText(const char *fileName, std::string &outputText)
{
    std::ifstream in(fileName, std::ios::in | std::ios::binary);

    if (in.is_open() && in.good())
    {
        outputText.clear();
        outputText.resize(Detail::GetTextLength(in));
        in.read(&(outputText[0]), outputText.size());
        in.close();

        return true;
    }

    return false;
}

std::string ReadFileFullText(const char *fileName)
{
    std::string output;

    if (ReadFileFullText(fileName, output))
    {
        return output;
    }

    return std::string();
}

} // namespace FileIO
