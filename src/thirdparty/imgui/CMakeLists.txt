set (LIBRARY_NAME imgui)

set (${LIBRARY_NAME}_HEADER_CODE
    imgui/imconfig.h
    imgui/imgui.h
    imgui/imgui_impl_glfw.h
    imgui/imgui_impl_opengl3.h
    imgui/imgui_internal.h
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h
)

set (${LIBRARY_NAME}_SOURCE_CODE
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_impl_glfw.cpp
    imgui/imgui_impl_opengl3.cpp
    imgui/imgui_widgets.cpp
)

add_library(${LIBRARY_NAME}
    STATIC
        ${${LIBRARY_NAME}_HEADER_CODE}
        ${${LIBRARY_NAME}_SOURCE_CODE}
)

target_link_libraries(${LIBRARY_NAME}
    PRIVATE
        glad
        glfw
)

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
