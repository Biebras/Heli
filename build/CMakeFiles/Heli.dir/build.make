# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sauliusvincevicius/Documents/Projects/Heli-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/Heli.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Heli.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Heli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Heli.dir/flags.make

CMakeFiles/Heli.dir/main.cpp.o: CMakeFiles/Heli.dir/flags.make
CMakeFiles/Heli.dir/main.cpp.o: /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/main.cpp
CMakeFiles/Heli.dir/main.cpp.o: CMakeFiles/Heli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Heli.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Heli.dir/main.cpp.o -MF CMakeFiles/Heli.dir/main.cpp.o.d -o CMakeFiles/Heli.dir/main.cpp.o -c /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/main.cpp

CMakeFiles/Heli.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Heli.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/main.cpp > CMakeFiles/Heli.dir/main.cpp.i

CMakeFiles/Heli.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Heli.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/main.cpp -o CMakeFiles/Heli.dir/main.cpp.s

CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o: CMakeFiles/Heli.dir/flags.make
CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o: /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/heli/src/graphics/graphics.cpp
CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o: CMakeFiles/Heli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o -MF CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o.d -o CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o -c /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/heli/src/graphics/graphics.cpp

CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/heli/src/graphics/graphics.cpp > CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.i

CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/heli/src/graphics/graphics.cpp -o CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.s

CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o: CMakeFiles/Heli.dir/flags.make
CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o: /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/heli/src/graphics/camera.cpp
CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o: CMakeFiles/Heli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o -MF CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o.d -o CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o -c /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/heli/src/graphics/camera.cpp

CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/heli/src/graphics/camera.cpp > CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.i

CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/heli/src/graphics/camera.cpp -o CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.s

# Object files for target Heli
Heli_OBJECTS = \
"CMakeFiles/Heli.dir/main.cpp.o" \
"CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o" \
"CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o"

# External object files for target Heli
Heli_EXTERNAL_OBJECTS =

Heli: CMakeFiles/Heli.dir/main.cpp.o
Heli: CMakeFiles/Heli.dir/heli/src/graphics/graphics.cpp.o
Heli: CMakeFiles/Heli.dir/heli/src/graphics/camera.cpp.o
Heli: CMakeFiles/Heli.dir/build.make
Heli: vendors/glfw/src/libglfw3.a
Heli: vendors/glad/libglad.a
Heli: vendors/glm/glm/libglm.a
Heli: CMakeFiles/Heli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Heli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Heli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Heli.dir/build: Heli
.PHONY : CMakeFiles/Heli.dir/build

CMakeFiles/Heli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Heli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Heli.dir/clean

CMakeFiles/Heli.dir/depend:
	cd /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sauliusvincevicius/Documents/Projects/Heli-Engine /Users/sauliusvincevicius/Documents/Projects/Heli-Engine /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build /Users/sauliusvincevicius/Documents/Projects/Heli-Engine/build/CMakeFiles/Heli.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Heli.dir/depend

