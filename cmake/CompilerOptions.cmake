if (MSVC)
    string (REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT}")
endif()

if (MSVC)
    set(${PROJECT_NAME}_CXX_FLAGS_DEBUG
        "/W4"
        "/WX"
    )
    set(${PROJECT_NAME}_CXX_FLAGS_RELEASE "/O2")
else()
    set(${PROJECT_NAME}_CXX_FLAGS_DEBUG
            "-pedantic"
            "-W"
            "-Wall"
            "-Wdouble-promotion"
            "-Wextra"
            "-Wfloat-equal"
            "-Wformat=2"
            "-Wimplicit-fallthrough"
            "-Winit-self"
            "-Winline"
            "-Wno-long-long"
            "-Wpointer-arith"
            "-Wshadow"
            "-Wsign-promo"
            "-Wundef"
            "-Wno-attributes"
    )
    set(${PROJECT_NAME}_CXX_FLAGS_RELEASE "-O3")
endif()
