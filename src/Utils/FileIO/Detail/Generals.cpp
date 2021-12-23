#include "Generals.hpp"

namespace FileIO
{

namespace Detail
{

std::streampos GetTextLength(std::ifstream &in)
{
    in.seekg(0, std::ios::end);
    std::streampos Length{in.tellg()};
    in.seekg(0, std::ios::beg);

    return Length;
}

} // namespace Detail

} // namespace FileIO
