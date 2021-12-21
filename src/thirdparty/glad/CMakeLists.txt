set (LIBRARY_NAME glad)

set (${LIBRARY_NAME}_HEADER_CODE
    include/glad/glad.h
    include/KHR/khrplatform.h
)

set (${LIBRARY_NAME}_SOURCE_CODE src/glad.c)

add_library(${LIBRARY_NAME}
    STATIC
        ${${LIBRARY_NAME}_HEADER_CODE}
        ${${LIBRARY_NAME}_SOURCE_CODE}
)

target_include_directories(${LIBRARY_NAME} PUBLIC "include")
