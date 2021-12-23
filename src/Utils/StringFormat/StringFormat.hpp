#ifndef HOMEWORK01_UTILS_OUTPUT_OUTPUT_HPP_
#define HOMEWORK01_UTILS_OUTPUT_OUTPUT_HPP_

#include <cstdint>

#include <array>
#include <iostream>
#include <string>
#include <vector>

namespace StringFormat
{

/**
 * @brief Format a std::string output
 * @details
 *     This function tend to use snprintf as the format function. If an encoding
 *     error occurs, The program will call exit(EXIT_FAILURE).
 *
 * @tparam Args Argument type
 * @param format format std::string which follow the format rule in printf
 * @param args Argument
 * @return Formatted string
 */
template <class... Args>
std::string StringFormat(const std::string &format, Args... args);

} // namespace StringFormat

#include "StringFormat-inl.hpp"

#endif // HOMEWORK01_UTILS_OUTPUT_OUTPUT_HPP_
