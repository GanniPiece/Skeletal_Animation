#ifndef HOMEWORK01_UTILS_COMPILERS_HPP_
#define HOMEWORK01_UTILS_COMPILERS_HPP_

// clang-format off

// Warning push pop
#if defined(_MSC_VER)

#define PRAGMA_TO(X) __pragma(X)
#define PRAGMA_WARNING_PUSH PRAGMA_TO(warning(push))
#define PRAGMA_WARNING_POP PRAGMA_TO(warning(pop))
#define PRAGMA_WARNING_DISABLE(number) PRAGMA_TO(warning(disable : number))

#elif defined(__GNUC__)

#define PRAGMA_TO(X) _Pragma(#X)
#define PRAGMA_WARNING_PUSH PRAGMA_TO(GCC diagnostic push)
#define PRAGMA_WARNING_POP PRAGMA_TO(GCC diagnostic pop)
#define PRAGMA_WARNING_DISABLE(name) PRAGMA_TO(GCC diagnostic ignored #name)

#elif defined(__clang__)

#define PRAGMA_TO(X) _Pragma(#X)
#define PRAGMA_WARNING_PUSH PRAGMA_TO(GCC diagnostic push)
#define PRAGMA_WARNING_POP PRAGMA_TO(GCC diagnostic pop)
#define PRAGMA_WARNING_DISABLE(name) PRAGMA_TO(GCC diagnostic ignored #name)

#else

#define PRAGMA_TO(X)
#define PRAGMA_WARNING_PUSH
#define PRAGMA_WARNING_POP
#define PRAGMA_WARNING_DISABLE(name)

#endif

#if defined(__GNUC__)
#define PRAGMA_WARNING_DISABLE_FLOATEQUAL PRAGMA_WARNING_DISABLE(-Wfloat-equal)
#elif defined(__clang__)
#define PRAGMA_WARNING_DISABLE_FLOATEQUAL PRAGMA_WARNING_DISABLE(-Wfloat-equal)
#else
#define PRAGMA_WARNING_DISABLE_FLOATEQUAL
#endif

#if defined(__GNUC__)
#define PRAGMA_WARNING_DISABLE_DOUBLEPROMOTION PRAGMA_WARNING_DISABLE(-Wdouble-promotion)
#elif defined(__clang__)
#define PRAGMA_WARNING_DISABLE_DOUBLEPROMOTION PRAGMA_WARNING_DISABLE(-Wdouble-promotion)
#else
#define PRAGMA_WARNING_DISABLE_DOUBLEPROMOTION
#endif

#if defined(_MSC_VER)
#define PRAGMA_WARNING_DISABLE_CONSTANTCONDITIONAL PRAGMA_WARNING_DISABLE(4127)
#else
#define PRAGMA_WARNING_DISABLE_CONSTANTCONDITIONAL
#endif

// clang-format on

#endif // HOMEWORK01_UTILS_COMPILERS_HPP_
