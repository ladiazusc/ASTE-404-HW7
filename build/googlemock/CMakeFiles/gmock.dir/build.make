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
include googlemock/CMakeFiles/gmock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include googlemock/CMakeFiles/gmock.dir/compiler_depend.make

# Include the progress variables for this target.
include googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include googlemock/CMakeFiles/gmock.dir/flags.make

googlemock/CMakeFiles/gmock.dir/codegen:
.PHONY : googlemock/CMakeFiles/gmock.dir/codegen

googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: googlemock/CMakeFiles/gmock.dir/flags.make
googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: googlemock/CMakeFiles/gmock.dir/includes_CXX.rsp
googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: C:/Users/luisd/OneDrive/Desktop/Fall\ 2024/ASTE404/week6/hw7\ -\ Copy/googletest/googlemock/src/gmock-all.cc
googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: googlemock/CMakeFiles/gmock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj"
	cd /d C:\Users\luisd\OneDrive\Desktop\FALL20~1\ASTE404\week6\HW7-CO~1\build\GOOGLE~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj -MF CMakeFiles\gmock.dir\src\gmock-all.cc.obj.d -o CMakeFiles\gmock.dir\src\gmock-all.cc.obj -c "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest\googlemock\src\gmock-all.cc"

googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /d C:\Users\luisd\OneDrive\Desktop\FALL20~1\ASTE404\week6\HW7-CO~1\build\GOOGLE~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest\googlemock\src\gmock-all.cc" > CMakeFiles\gmock.dir\src\gmock-all.cc.i

googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /d C:\Users\luisd\OneDrive\Desktop\FALL20~1\ASTE404\week6\HW7-CO~1\build\GOOGLE~1 && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest\googlemock\src\gmock-all.cc" -o CMakeFiles\gmock.dir\src\gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.obj"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmock.a: googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj
lib/libgmock.a: googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmock.a: googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\lib\libgmock.a"
	cd /d C:\Users\luisd\OneDrive\Desktop\FALL20~1\ASTE404\week6\HW7-CO~1\build\GOOGLE~1 && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean_target.cmake
	cd /d C:\Users\luisd\OneDrive\Desktop\FALL20~1\ASTE404\week6\HW7-CO~1\build\GOOGLE~1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gmock.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googlemock/CMakeFiles/gmock.dir/build: lib/libgmock.a
.PHONY : googlemock/CMakeFiles/gmock.dir/build

googlemock/CMakeFiles/gmock.dir/clean:
	cd /d C:\Users\luisd\OneDrive\Desktop\FALL20~1\ASTE404\week6\HW7-CO~1\build\GOOGLE~1 && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean.cmake
.PHONY : googlemock/CMakeFiles/gmock.dir/clean

googlemock/CMakeFiles/gmock.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\googletest\googlemock" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build\googlemock" "C:\Users\luisd\OneDrive\Desktop\Fall 2024\ASTE404\week6\hw7 - Copy\build\googlemock\CMakeFiles\gmock.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : googlemock/CMakeFiles/gmock.dir/depend

