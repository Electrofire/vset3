# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joel/Desktop/Sync

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joel/Desktop/Sync

# Include any dependencies generated for this target.
include CMakeFiles/syncTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/syncTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/syncTest.dir/flags.make

CMakeFiles/syncTest.dir/syncTest.o: CMakeFiles/syncTest.dir/flags.make
CMakeFiles/syncTest.dir/syncTest.o: syncTest.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/joel/Desktop/Sync/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/syncTest.dir/syncTest.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/syncTest.dir/syncTest.o -c /home/joel/Desktop/Sync/syncTest.cxx

CMakeFiles/syncTest.dir/syncTest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/syncTest.dir/syncTest.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/joel/Desktop/Sync/syncTest.cxx > CMakeFiles/syncTest.dir/syncTest.i

CMakeFiles/syncTest.dir/syncTest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/syncTest.dir/syncTest.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/joel/Desktop/Sync/syncTest.cxx -o CMakeFiles/syncTest.dir/syncTest.s

CMakeFiles/syncTest.dir/syncTest.o.requires:
.PHONY : CMakeFiles/syncTest.dir/syncTest.o.requires

CMakeFiles/syncTest.dir/syncTest.o.provides: CMakeFiles/syncTest.dir/syncTest.o.requires
	$(MAKE) -f CMakeFiles/syncTest.dir/build.make CMakeFiles/syncTest.dir/syncTest.o.provides.build
.PHONY : CMakeFiles/syncTest.dir/syncTest.o.provides

CMakeFiles/syncTest.dir/syncTest.o.provides.build: CMakeFiles/syncTest.dir/syncTest.o

# Object files for target syncTest
syncTest_OBJECTS = \
"CMakeFiles/syncTest.dir/syncTest.o"

# External object files for target syncTest
syncTest_EXTERNAL_OBJECTS =

syncTest: CMakeFiles/syncTest.dir/syncTest.o
syncTest: /usr/lib/libXt.so
syncTest: /usr/lib/libSM.so
syncTest: /usr/lib/libICE.so
syncTest: /usr/lib/libX11.so
syncTest: /usr/lib/libXext.so
syncTest: /usr/lib/libGL.so
syncTest: CMakeFiles/syncTest.dir/build.make
syncTest: CMakeFiles/syncTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable syncTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/syncTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/syncTest.dir/build: syncTest
.PHONY : CMakeFiles/syncTest.dir/build

CMakeFiles/syncTest.dir/requires: CMakeFiles/syncTest.dir/syncTest.o.requires
.PHONY : CMakeFiles/syncTest.dir/requires

CMakeFiles/syncTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/syncTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/syncTest.dir/clean

CMakeFiles/syncTest.dir/depend:
	cd /home/joel/Desktop/Sync && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joel/Desktop/Sync /home/joel/Desktop/Sync /home/joel/Desktop/Sync /home/joel/Desktop/Sync /home/joel/Desktop/Sync/CMakeFiles/syncTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/syncTest.dir/depend

