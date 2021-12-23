#ifndef HOMEWORK01_UTILS_GLOBAL_HPP_
#define HOMEWORK01_UTILS_GLOBAL_HPP_

#include <cstdio>

// Code Refactor
#define PROGRAM_MAYBE_UNUSED(x) ((void)(x));

// OpenGL related
#define PROGRAM_BUFFER_OFFSET(x) (static_cast<char *>(0) + (x))

// Assertion
#ifndef NDEBUG
#define PROGRAM_ASSERT(expression)                                             \
    do                                                                         \
    {                                                                          \
        if (!(expression))                                                     \
        {                                                                      \
            fprintf(stderr, "[%s: %d]: Assertion `%s' failed.\n", __FILE__,    \
                    __LINE__, #expression);                                    \
        }                                                                      \
    } while (0)
#else
#define PROGRAM_ASSERT(expression) ((void)(0))
#endif

#endif // HOMEWORK01_UTILS_GLOBAL_HPP_
