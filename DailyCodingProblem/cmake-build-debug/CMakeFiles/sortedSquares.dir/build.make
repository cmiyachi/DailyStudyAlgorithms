# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sortedSquares.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sortedSquares.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sortedSquares.dir/flags.make

CMakeFiles/sortedSquares.dir/sortedSquares.cpp.obj: CMakeFiles/sortedSquares.dir/flags.make
CMakeFiles/sortedSquares.dir/sortedSquares.cpp.obj: ../sortedSquares.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sortedSquares.dir/sortedSquares.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sortedSquares.dir\sortedSquares.cpp.obj -c C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\sortedSquares.cpp

CMakeFiles/sortedSquares.dir/sortedSquares.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sortedSquares.dir/sortedSquares.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\sortedSquares.cpp > CMakeFiles\sortedSquares.dir\sortedSquares.cpp.i

CMakeFiles/sortedSquares.dir/sortedSquares.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sortedSquares.dir/sortedSquares.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\sortedSquares.cpp -o CMakeFiles\sortedSquares.dir\sortedSquares.cpp.s

# Object files for target sortedSquares
sortedSquares_OBJECTS = \
"CMakeFiles/sortedSquares.dir/sortedSquares.cpp.obj"

# External object files for target sortedSquares
sortedSquares_EXTERNAL_OBJECTS =

sortedSquares.exe: CMakeFiles/sortedSquares.dir/sortedSquares.cpp.obj
sortedSquares.exe: CMakeFiles/sortedSquares.dir/build.make
sortedSquares.exe: CMakeFiles/sortedSquares.dir/linklibs.rsp
sortedSquares.exe: CMakeFiles/sortedSquares.dir/objects1.rsp
sortedSquares.exe: CMakeFiles/sortedSquares.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sortedSquares.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sortedSquares.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sortedSquares.dir/build: sortedSquares.exe

.PHONY : CMakeFiles/sortedSquares.dir/build

CMakeFiles/sortedSquares.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sortedSquares.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sortedSquares.dir/clean

CMakeFiles/sortedSquares.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\cmake-build-debug C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\cmake-build-debug C:\Users\chris\OneDrive\Documents\GitHub\DailyStudyAlgorithms\DailyCodingProblem\cmake-build-debug\CMakeFiles\sortedSquares.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sortedSquares.dir/depend

