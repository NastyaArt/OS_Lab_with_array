# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /cygdrive/c/Users/Nastya/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Nastya/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/Nastya/CLion/Lab1_OS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MyExecutable.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyExecutable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyExecutable.dir/flags.make

CMakeFiles/MyExecutable.dir/main.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyExecutable.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyExecutable.dir/main.c.o   -c /cygdrive/d/Nastya/CLion/Lab1_OS/main.c

CMakeFiles/MyExecutable.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/Nastya/CLion/Lab1_OS/main.c > CMakeFiles/MyExecutable.dir/main.c.i

CMakeFiles/MyExecutable.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/Nastya/CLion/Lab1_OS/main.c -o CMakeFiles/MyExecutable.dir/main.c.s

CMakeFiles/MyExecutable.dir/main.c.o.requires:

.PHONY : CMakeFiles/MyExecutable.dir/main.c.o.requires

CMakeFiles/MyExecutable.dir/main.c.o.provides: CMakeFiles/MyExecutable.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/MyExecutable.dir/build.make CMakeFiles/MyExecutable.dir/main.c.o.provides.build
.PHONY : CMakeFiles/MyExecutable.dir/main.c.o.provides

CMakeFiles/MyExecutable.dir/main.c.o.provides.build: CMakeFiles/MyExecutable.dir/main.c.o


CMakeFiles/MyExecutable.dir/manager.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/manager.c.o: ../manager.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MyExecutable.dir/manager.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyExecutable.dir/manager.c.o   -c /cygdrive/d/Nastya/CLion/Lab1_OS/manager.c

CMakeFiles/MyExecutable.dir/manager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/manager.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/Nastya/CLion/Lab1_OS/manager.c > CMakeFiles/MyExecutable.dir/manager.c.i

CMakeFiles/MyExecutable.dir/manager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/manager.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/Nastya/CLion/Lab1_OS/manager.c -o CMakeFiles/MyExecutable.dir/manager.c.s

CMakeFiles/MyExecutable.dir/manager.c.o.requires:

.PHONY : CMakeFiles/MyExecutable.dir/manager.c.o.requires

CMakeFiles/MyExecutable.dir/manager.c.o.provides: CMakeFiles/MyExecutable.dir/manager.c.o.requires
	$(MAKE) -f CMakeFiles/MyExecutable.dir/build.make CMakeFiles/MyExecutable.dir/manager.c.o.provides.build
.PHONY : CMakeFiles/MyExecutable.dir/manager.c.o.provides

CMakeFiles/MyExecutable.dir/manager.c.o.provides.build: CMakeFiles/MyExecutable.dir/manager.c.o


CMakeFiles/MyExecutable.dir/tests.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/tests.c.o: ../tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MyExecutable.dir/tests.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MyExecutable.dir/tests.c.o   -c /cygdrive/d/Nastya/CLion/Lab1_OS/tests.c

CMakeFiles/MyExecutable.dir/tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/tests.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/Nastya/CLion/Lab1_OS/tests.c > CMakeFiles/MyExecutable.dir/tests.c.i

CMakeFiles/MyExecutable.dir/tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/tests.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/Nastya/CLion/Lab1_OS/tests.c -o CMakeFiles/MyExecutable.dir/tests.c.s

CMakeFiles/MyExecutable.dir/tests.c.o.requires:

.PHONY : CMakeFiles/MyExecutable.dir/tests.c.o.requires

CMakeFiles/MyExecutable.dir/tests.c.o.provides: CMakeFiles/MyExecutable.dir/tests.c.o.requires
	$(MAKE) -f CMakeFiles/MyExecutable.dir/build.make CMakeFiles/MyExecutable.dir/tests.c.o.provides.build
.PHONY : CMakeFiles/MyExecutable.dir/tests.c.o.provides

CMakeFiles/MyExecutable.dir/tests.c.o.provides.build: CMakeFiles/MyExecutable.dir/tests.c.o


# Object files for target MyExecutable
MyExecutable_OBJECTS = \
"CMakeFiles/MyExecutable.dir/main.c.o" \
"CMakeFiles/MyExecutable.dir/manager.c.o" \
"CMakeFiles/MyExecutable.dir/tests.c.o"

# External object files for target MyExecutable
MyExecutable_EXTERNAL_OBJECTS =

MyExecutable.exe: CMakeFiles/MyExecutable.dir/main.c.o
MyExecutable.exe: CMakeFiles/MyExecutable.dir/manager.c.o
MyExecutable.exe: CMakeFiles/MyExecutable.dir/tests.c.o
MyExecutable.exe: CMakeFiles/MyExecutable.dir/build.make
MyExecutable.exe: CMakeFiles/MyExecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable MyExecutable.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyExecutable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyExecutable.dir/build: MyExecutable.exe

.PHONY : CMakeFiles/MyExecutable.dir/build

CMakeFiles/MyExecutable.dir/requires: CMakeFiles/MyExecutable.dir/main.c.o.requires
CMakeFiles/MyExecutable.dir/requires: CMakeFiles/MyExecutable.dir/manager.c.o.requires
CMakeFiles/MyExecutable.dir/requires: CMakeFiles/MyExecutable.dir/tests.c.o.requires

.PHONY : CMakeFiles/MyExecutable.dir/requires

CMakeFiles/MyExecutable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyExecutable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyExecutable.dir/clean

CMakeFiles/MyExecutable.dir/depend:
	cd /cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Nastya/CLion/Lab1_OS /cygdrive/d/Nastya/CLion/Lab1_OS /cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug /cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug /cygdrive/d/Nastya/CLion/Lab1_OS/cmake-build-debug/CMakeFiles/MyExecutable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyExecutable.dir/depend

