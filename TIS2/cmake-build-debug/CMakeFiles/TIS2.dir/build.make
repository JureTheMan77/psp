# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/jure/Dokumenti/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jure/Dokumenti/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jure/Dokumenti/psp/TIS2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jure/Dokumenti/psp/TIS2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TIS2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TIS2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TIS2.dir/flags.make

CMakeFiles/TIS2.dir/main.cpp.o: CMakeFiles/TIS2.dir/flags.make
CMakeFiles/TIS2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jure/Dokumenti/psp/TIS2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TIS2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIS2.dir/main.cpp.o -c /home/jure/Dokumenti/psp/TIS2/main.cpp

CMakeFiles/TIS2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIS2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jure/Dokumenti/psp/TIS2/main.cpp > CMakeFiles/TIS2.dir/main.cpp.i

CMakeFiles/TIS2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIS2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jure/Dokumenti/psp/TIS2/main.cpp -o CMakeFiles/TIS2.dir/main.cpp.s

CMakeFiles/TIS2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TIS2.dir/main.cpp.o.requires

CMakeFiles/TIS2.dir/main.cpp.o.provides: CMakeFiles/TIS2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIS2.dir/build.make CMakeFiles/TIS2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TIS2.dir/main.cpp.o.provides

CMakeFiles/TIS2.dir/main.cpp.o.provides.build: CMakeFiles/TIS2.dir/main.cpp.o


# Object files for target TIS2
TIS2_OBJECTS = \
"CMakeFiles/TIS2.dir/main.cpp.o"

# External object files for target TIS2
TIS2_EXTERNAL_OBJECTS =

TIS2: CMakeFiles/TIS2.dir/main.cpp.o
TIS2: CMakeFiles/TIS2.dir/build.make
TIS2: CMakeFiles/TIS2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jure/Dokumenti/psp/TIS2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TIS2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TIS2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TIS2.dir/build: TIS2

.PHONY : CMakeFiles/TIS2.dir/build

CMakeFiles/TIS2.dir/requires: CMakeFiles/TIS2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/TIS2.dir/requires

CMakeFiles/TIS2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TIS2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TIS2.dir/clean

CMakeFiles/TIS2.dir/depend:
	cd /home/jure/Dokumenti/psp/TIS2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jure/Dokumenti/psp/TIS2 /home/jure/Dokumenti/psp/TIS2 /home/jure/Dokumenti/psp/TIS2/cmake-build-debug /home/jure/Dokumenti/psp/TIS2/cmake-build-debug /home/jure/Dokumenti/psp/TIS2/cmake-build-debug/CMakeFiles/TIS2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TIS2.dir/depend

