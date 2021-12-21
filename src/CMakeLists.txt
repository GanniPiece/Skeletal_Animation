cmake_minimum_required(VERSION 3.3.0)

set(${PROJECT_NAME}_EXECUTABLE_NAME ${PROJECT_NAME})

include(${${PROJECT_NAME}_MODULE_DIR}/CompilerOptions.cmake)

set(${PROJECT_NAME}_HEADER_CODE
    animation.h
    animator.h
    animdata.h
    assimp_glm_helpers.h
    bone.h
    camera.h
    mesh.h
    model_animation.h
    # shader_m.h
    shader.h
)


set(${PROJECT_NAME}_SOURCE_CODE
    main.cpp
#     animation.cpp
#     animator.cpp
#     bone.cpp
#     camera.cpp
#     mesh.cpp
#     model_animation.cpp
#     shader.cpp
)

add_executable(${${PROJECT_NAME}_EXECUTABLE_NAME}
    ${${PROJECT_NAME}_HEADER_CODE}
    ${${PROJECT_NAME}_SOURCE_CODE}
)

set_target_properties(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>
)

target_include_directories(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${GLM_INCLUDE_DIRS}
        ${STB_INCLUDE_DIRS}
)

target_compile_features(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        cxx_std_11
)

target_compile_options(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        "$<$<CONFIG:DEBUG>:${${PROJECT_NAME}_CXX_FLAGS_DEBUG}>"
        "$<$<CONFIG:RELEASE>:${${PROJECT_NAME}_CXX_FLAGS_RELEASE}>"
)

target_compile_definitions(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PRIVATE
        GLM_FORCE_SILENT_WARNINGS
)

target_link_libraries(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad
        glfw
        ${ASSIMP_LIBRARIES}
        stb
        $<$<PLATFORM_ID:Linux>:${CMAKE_DL_LIBS}>
)

# include(${${PROJECT_NAME}_MODULE_DIR}/PostBuildCommand.cmake)
