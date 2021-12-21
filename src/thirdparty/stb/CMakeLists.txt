set (LIBRARY_NAME stb)

set (${LIBRARY_NAME}_HEADER_DIR include)
set (${LIBRARY_NAME}_SOURCE_DIR src)

set (${LIBRARY_NAME}_HEADER_CODE
    ${${LIBRARY_NAME}_HEADER_DIR}/stb_image.h
)
set (${LIBRARY_NAME}_SOURCE_CODE
    ${${LIBRARY_NAME}_SOURCE_DIR}/stb_image.cpp
)

add_library(${LIBRARY_NAME}
    STATIC
        ${${LIBRARY_NAME}_HEADER_CODE}
        ${${LIBRARY_NAME}_SOURCE_CODE}
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/${${LIBRARY_NAME}_HEADER_DIR}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/${${LIBRARY_NAME}_SOURCE_DIR}
)
