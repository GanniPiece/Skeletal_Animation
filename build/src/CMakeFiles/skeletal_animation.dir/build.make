# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build

# Include any dependencies generated for this target.
include src/CMakeFiles/Skeletal_Animation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/Skeletal_Animation.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Skeletal_Animation.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Skeletal_Animation.dir/flags.make

src/CMakeFiles/Skeletal_Animation.dir/main.cpp.o: src/CMakeFiles/Skeletal_Animation.dir/flags.make
src/CMakeFiles/Skeletal_Animation.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/Skeletal_Animation.dir/main.cpp.o: src/CMakeFiles/Skeletal_Animation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Skeletal_Animation.dir/main.cpp.o"
	cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Skeletal_Animation.dir/main.cpp.o -MF CMakeFiles/Skeletal_Animation.dir/main.cpp.o.d -o CMakeFiles/Skeletal_Animation.dir/main.cpp.o -c /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/src/main.cpp

src/CMakeFiles/Skeletal_Animation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Skeletal_Animation.dir/main.cpp.i"
	cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/src/main.cpp > CMakeFiles/Skeletal_Animation.dir/main.cpp.i

src/CMakeFiles/Skeletal_Animation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Skeletal_Animation.dir/main.cpp.s"
	cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/src/main.cpp -o CMakeFiles/Skeletal_Animation.dir/main.cpp.s

# Object files for target Skeletal_Animation
Skeletal_Animation_OBJECTS = \
"CMakeFiles/Skeletal_Animation.dir/main.cpp.o"

# External object files for target Skeletal_Animation
Skeletal_Animation_EXTERNAL_OBJECTS =

bin/Skeletal_Animation: src/CMakeFiles/Skeletal_Animation.dir/main.cpp.o
bin/Skeletal_Animation: src/CMakeFiles/Skeletal_Animation.dir/build.make
bin/Skeletal_Animation: src/thirdparty/glad/libglad.a
bin/Skeletal_Animation: /usr/local/lib/libassimp.5.1.0.dylib
bin/Skeletal_Animation: src/thirdparty/stb/libstb.a
bin/Skeletal_Animation: src/thirdparty/imgui/libimgui.a
bin/Skeletal_Animation: /usr/local/lib/libGLEW.2.2.0.dylib
bin/Skeletal_Animation: /Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk/usr/lib/libz.tbd
bin/Skeletal_Animation: src/thirdparty/glad/libglad.a
bin/Skeletal_Animation: /usr/local/lib/libglfw.3.3.dylib
bin/Skeletal_Animation: src/CMakeFiles/Skeletal_Animation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/Skeletal_Animation"
	cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Skeletal_Animation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Skeletal_Animation.dir/build: bin/Skeletal_Animation
.PHONY : src/CMakeFiles/Skeletal_Animation.dir/build

src/CMakeFiles/Skeletal_Animation.dir/clean:
	cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Skeletal_Animation.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Skeletal_Animation.dir/clean

src/CMakeFiles/Skeletal_Animation.dir/depend:
	cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/src /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/src /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build/src/CMakeFiles/Skeletal_Animation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Skeletal_Animation.dir/depend

