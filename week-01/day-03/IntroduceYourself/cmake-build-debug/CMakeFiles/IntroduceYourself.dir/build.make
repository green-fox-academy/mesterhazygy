# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IntroduceYourself.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IntroduceYourself.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IntroduceYourself.dir/flags.make

CMakeFiles/IntroduceYourself.dir/main.cpp.obj: CMakeFiles/IntroduceYourself.dir/flags.make
CMakeFiles/IntroduceYourself.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IntroduceYourself.dir/main.cpp.obj"
	C:\hax\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\IntroduceYourself.dir\main.cpp.obj -c C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\main.cpp

CMakeFiles/IntroduceYourself.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IntroduceYourself.dir/main.cpp.i"
	C:\hax\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\main.cpp > CMakeFiles\IntroduceYourself.dir\main.cpp.i

CMakeFiles/IntroduceYourself.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IntroduceYourself.dir/main.cpp.s"
	C:\hax\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\main.cpp -o CMakeFiles\IntroduceYourself.dir\main.cpp.s

# Object files for target IntroduceYourself
IntroduceYourself_OBJECTS = \
"CMakeFiles/IntroduceYourself.dir/main.cpp.obj"

# External object files for target IntroduceYourself
IntroduceYourself_EXTERNAL_OBJECTS =

IntroduceYourself.exe: CMakeFiles/IntroduceYourself.dir/main.cpp.obj
IntroduceYourself.exe: CMakeFiles/IntroduceYourself.dir/build.make
IntroduceYourself.exe: CMakeFiles/IntroduceYourself.dir/linklibs.rsp
IntroduceYourself.exe: CMakeFiles/IntroduceYourself.dir/objects1.rsp
IntroduceYourself.exe: CMakeFiles/IntroduceYourself.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IntroduceYourself.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IntroduceYourself.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IntroduceYourself.dir/build: IntroduceYourself.exe

.PHONY : CMakeFiles/IntroduceYourself.dir/build

CMakeFiles/IntroduceYourself.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IntroduceYourself.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IntroduceYourself.dir/clean

CMakeFiles/IntroduceYourself.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\cmake-build-debug C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\cmake-build-debug C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\IntroduceYourself\cmake-build-debug\CMakeFiles\IntroduceYourself.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IntroduceYourself.dir/depend

