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
CMAKE_SOURCE_DIR = C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MiletoKmConverter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MiletoKmConverter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MiletoKmConverter.dir/flags.make

CMakeFiles/MiletoKmConverter.dir/main.cpp.obj: CMakeFiles/MiletoKmConverter.dir/flags.make
CMakeFiles/MiletoKmConverter.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MiletoKmConverter.dir/main.cpp.obj"
	C:\hax\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MiletoKmConverter.dir\main.cpp.obj -c C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\main.cpp

CMakeFiles/MiletoKmConverter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiletoKmConverter.dir/main.cpp.i"
	C:\hax\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\main.cpp > CMakeFiles\MiletoKmConverter.dir\main.cpp.i

CMakeFiles/MiletoKmConverter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiletoKmConverter.dir/main.cpp.s"
	C:\hax\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\main.cpp -o CMakeFiles\MiletoKmConverter.dir\main.cpp.s

# Object files for target MiletoKmConverter
MiletoKmConverter_OBJECTS = \
"CMakeFiles/MiletoKmConverter.dir/main.cpp.obj"

# External object files for target MiletoKmConverter
MiletoKmConverter_EXTERNAL_OBJECTS =

MiletoKmConverter.exe: CMakeFiles/MiletoKmConverter.dir/main.cpp.obj
MiletoKmConverter.exe: CMakeFiles/MiletoKmConverter.dir/build.make
MiletoKmConverter.exe: CMakeFiles/MiletoKmConverter.dir/linklibs.rsp
MiletoKmConverter.exe: CMakeFiles/MiletoKmConverter.dir/objects1.rsp
MiletoKmConverter.exe: CMakeFiles/MiletoKmConverter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MiletoKmConverter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MiletoKmConverter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MiletoKmConverter.dir/build: MiletoKmConverter.exe

.PHONY : CMakeFiles/MiletoKmConverter.dir/build

CMakeFiles/MiletoKmConverter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MiletoKmConverter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MiletoKmConverter.dir/clean

CMakeFiles/MiletoKmConverter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\cmake-build-debug C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\cmake-build-debug C:\Users\megha\greenfox\mesterhazygy\week-01\day-03\MiletoKmConverter\cmake-build-debug\CMakeFiles\MiletoKmConverter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MiletoKmConverter.dir/depend
