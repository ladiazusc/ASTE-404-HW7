# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build"

# Include any dependencies generated for this target.
include CMakeFiles/main_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_exe.dir/flags.make

CMakeFiles/main_exe.dir/codegen:
.PHONY : CMakeFiles/main_exe.dir/codegen

CMakeFiles/main_exe.dir/main.cpp.obj: CMakeFiles/main_exe.dir/flags.make
CMakeFiles/main_exe.dir/main.cpp.obj: C:/Users/luisd/OneDrive/Desktop/Fall\ 2024/ASTE404/week6/hw7\ -\ Copy/googletest/main.cpp
CMakeFiles/main_exe.dir/main.cpp.obj: CMakeFiles/main_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_exe.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_exe.dir/main.cpp.obj -MF CMakeFiles\main_exe.dir\main.cpp.obj.d -o CMakeFiles\main_exe.dir\main.cpp.obj -c "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest\main.cpp"

CMakeFiles/main_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main_exe.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest\main.cpp" > CMakeFiles\main_exe.dir\main.cpp.i

CMakeFiles/main_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main_exe.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest\main.cpp" -o CMakeFiles\main_exe.dir\main.cpp.s

# Object files for target main_exe
main_exe_OBJECTS = \
"CMakeFiles/main_exe.dir/main.cpp.obj"

# External object files for target main_exe
main_exe_EXTERNAL_OBJECTS =

main_exe.exe: CMakeFiles/main_exe.dir/main.cpp.obj
main_exe.exe: CMakeFiles/main_exe.dir/build.make
main_exe.exe: CMakeFiles/main_exe.dir/linkLibs.rsp
main_exe.exe: CMakeFiles/main_exe.dir/objects1.rsp
main_exe.exe: CMakeFiles/main_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main_exe.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main_exe.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_exe.dir/build: main_exe.exe
.PHONY : CMakeFiles/main_exe.dir/build

CMakeFiles/main_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main_exe.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main_exe.dir/clean

CMakeFiles/main_exe.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build\CMakeFiles\main_exe.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/main_exe.dir/depend
