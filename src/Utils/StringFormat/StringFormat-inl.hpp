#pragma clang diagnostic ignored "-Wformat-nonliteral"

namespace StringFormat
{

template <class... Args>
std::string StringFormat(const std::string &format, Args... args)
{
    const size_t stringEndSize = 1;
    size_t formatSize = snprintf(nullptr, 0, format.c_str(), args...);
    if (formatSize < 0)
    {
        std::cerr << "Error: format string failed";
        exit(EXIT_FAILURE);
    }

    std::vector<char> buffer(formatSize + stringEndSize);

    snprintf(buffer.data(), buffer.size(), format.c_str(), args...);

    return std::string{buffer.begin(), buffer.begin() + formatSize};
}

} // namespace StringFormat
