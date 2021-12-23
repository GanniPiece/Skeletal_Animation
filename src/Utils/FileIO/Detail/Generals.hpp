#ifndef HOMEWORK01_UTILS_FILEIO_DETAILS_GENERALS_HPP_
#define HOMEWORK01_UTILS_FILEIO_DETAILS_GENERALS_HPP_

#include <fstream>

namespace FileIO
{

namespace Detail
{

std::streampos GetTextLength(std::ifstream &in);

} // namespace Detail

} // namespace FileIO

#endif // HOMEWORK01_UTILS_FILEIO_DETAILS_GENERALS_HPP_
