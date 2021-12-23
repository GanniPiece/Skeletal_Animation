#ifndef HOMEWORK01_UTILS_FILEIO_FILEIN_HPP_
#define HOMEWORK01_UTILS_FILEIO_FILEIN_HPP_

#include <string>

namespace FileIO
{

bool ReadFileFullText(const char *fileName, std::string &outputText);

std::string ReadFileFullText(const char *fileName);

} // namespace FileIO

#endif // HOMEWORK01_UTILS_FILEIO_FILEIN_HPP_
