# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/73/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/73/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/afsara/CLionProjects/offline2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/afsara/CLionProjects/offline2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/offline2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/offline2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/offline2.dir/flags.make

CMakeFiles/offline2.dir/sources/main.cpp.o: CMakeFiles/offline2.dir/flags.make
CMakeFiles/offline2.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afsara/CLionProjects/offline2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/offline2.dir/sources/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/offline2.dir/sources/main.cpp.o -c /home/afsara/CLionProjects/offline2/sources/main.cpp

CMakeFiles/offline2.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/offline2.dir/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afsara/CLionProjects/offline2/sources/main.cpp > CMakeFiles/offline2.dir/sources/main.cpp.i

CMakeFiles/offline2.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/offline2.dir/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afsara/CLionProjects/offline2/sources/main.cpp -o CMakeFiles/offline2.dir/sources/main.cpp.s

CMakeFiles/offline2.dir/sources/demo.cpp.o: CMakeFiles/offline2.dir/flags.make
CMakeFiles/offline2.dir/sources/demo.cpp.o: ../sources/demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afsara/CLionProjects/offline2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/offline2.dir/sources/demo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/offline2.dir/sources/demo.cpp.o -c /home/afsara/CLionProjects/offline2/sources/demo.cpp

CMakeFiles/offline2.dir/sources/demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/offline2.dir/sources/demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afsara/CLionProjects/offline2/sources/demo.cpp > CMakeFiles/offline2.dir/sources/demo.cpp.i

CMakeFiles/offline2.dir/sources/demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/offline2.dir/sources/demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afsara/CLionProjects/offline2/sources/demo.cpp -o CMakeFiles/offline2.dir/sources/demo.cpp.s

CMakeFiles/offline2.dir/sources/demo2.cpp.o: CMakeFiles/offline2.dir/flags.make
CMakeFiles/offline2.dir/sources/demo2.cpp.o: ../sources/demo2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/afsara/CLionProjects/offline2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/offline2.dir/sources/demo2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/offline2.dir/sources/demo2.cpp.o -c /home/afsara/CLionProjects/offline2/sources/demo2.cpp

CMakeFiles/offline2.dir/sources/demo2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/offline2.dir/sources/demo2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/afsara/CLionProjects/offline2/sources/demo2.cpp > CMakeFiles/offline2.dir/sources/demo2.cpp.i

CMakeFiles/offline2.dir/sources/demo2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/offline2.dir/sources/demo2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/afsara/CLionProjects/offline2/sources/demo2.cpp -o CMakeFiles/offline2.dir/sources/demo2.cpp.s

# Object files for target offline2
offline2_OBJECTS = \
"CMakeFiles/offline2.dir/sources/main.cpp.o" \
"CMakeFiles/offline2.dir/sources/demo.cpp.o" \
"CMakeFiles/offline2.dir/sources/demo2.cpp.o"

# External object files for target offline2
offline2_EXTERNAL_OBJECTS =

offline2: CMakeFiles/offline2.dir/sources/main.cpp.o
offline2: CMakeFiles/offline2.dir/sources/demo.cpp.o
offline2: CMakeFiles/offline2.dir/sources/demo2.cpp.o
offline2: CMakeFiles/offline2.dir/build.make
offline2: CMakeFiles/offline2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/afsara/CLionProjects/offline2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable offline2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offline2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/offline2.dir/build: offline2

.PHONY : CMakeFiles/offline2.dir/build

CMakeFiles/offline2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/offline2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/offline2.dir/clean

CMakeFiles/offline2.dir/depend:
	cd /home/afsara/CLionProjects/offline2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/afsara/CLionProjects/offline2 /home/afsara/CLionProjects/offline2 /home/afsara/CLionProjects/offline2/cmake-build-debug /home/afsara/CLionProjects/offline2/cmake-build-debug /home/afsara/CLionProjects/offline2/cmake-build-debug/CMakeFiles/offline2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/offline2.dir/depend

