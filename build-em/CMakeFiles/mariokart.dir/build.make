# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/heath/mk-gint

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/heath/mk-gint/build-em

# Include any dependencies generated for this target.
include CMakeFiles/mariokart.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mariokart.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mariokart.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mariokart.dir/flags.make

CMakeFiles/mariokart.dir/src/3d.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/3d.c.o: ../src/3d.c
CMakeFiles/mariokart.dir/src/3d.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mariokart.dir/src/3d.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/3d.c.o -MF CMakeFiles/mariokart.dir/src/3d.c.o.d -o CMakeFiles/mariokart.dir/src/3d.c.o -c /home/heath/mk-gint/src/3d.c

CMakeFiles/mariokart.dir/src/3d.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/3d.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/3d.c > CMakeFiles/mariokart.dir/src/3d.c.i

CMakeFiles/mariokart.dir/src/3d.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/3d.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/3d.c -o CMakeFiles/mariokart.dir/src/3d.c.s

CMakeFiles/mariokart.dir/src/buttons.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/buttons.c.o: ../src/buttons.c
CMakeFiles/mariokart.dir/src/buttons.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mariokart.dir/src/buttons.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/buttons.c.o -MF CMakeFiles/mariokart.dir/src/buttons.c.o.d -o CMakeFiles/mariokart.dir/src/buttons.c.o -c /home/heath/mk-gint/src/buttons.c

CMakeFiles/mariokart.dir/src/buttons.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/buttons.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/buttons.c > CMakeFiles/mariokart.dir/src/buttons.c.i

CMakeFiles/mariokart.dir/src/buttons.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/buttons.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/buttons.c -o CMakeFiles/mariokart.dir/src/buttons.c.s

CMakeFiles/mariokart.dir/src/configurableConstants.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/configurableConstants.c.o: ../src/configurableConstants.c
CMakeFiles/mariokart.dir/src/configurableConstants.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mariokart.dir/src/configurableConstants.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/configurableConstants.c.o -MF CMakeFiles/mariokart.dir/src/configurableConstants.c.o.d -o CMakeFiles/mariokart.dir/src/configurableConstants.c.o -c /home/heath/mk-gint/src/configurableConstants.c

CMakeFiles/mariokart.dir/src/configurableConstants.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/configurableConstants.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/configurableConstants.c > CMakeFiles/mariokart.dir/src/configurableConstants.c.i

CMakeFiles/mariokart.dir/src/configurableConstants.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/configurableConstants.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/configurableConstants.c -o CMakeFiles/mariokart.dir/src/configurableConstants.c.s

CMakeFiles/mariokart.dir/src/data.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/data.c.o: ../src/data.c
CMakeFiles/mariokart.dir/src/data.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mariokart.dir/src/data.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/data.c.o -MF CMakeFiles/mariokart.dir/src/data.c.o.d -o CMakeFiles/mariokart.dir/src/data.c.o -c /home/heath/mk-gint/src/data.c

CMakeFiles/mariokart.dir/src/data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/data.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/data.c > CMakeFiles/mariokart.dir/src/data.c.i

CMakeFiles/mariokart.dir/src/data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/data.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/data.c -o CMakeFiles/mariokart.dir/src/data.c.s

CMakeFiles/mariokart.dir/src/debugHud.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/debugHud.c.o: ../src/debugHud.c
CMakeFiles/mariokart.dir/src/debugHud.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/mariokart.dir/src/debugHud.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/debugHud.c.o -MF CMakeFiles/mariokart.dir/src/debugHud.c.o.d -o CMakeFiles/mariokart.dir/src/debugHud.c.o -c /home/heath/mk-gint/src/debugHud.c

CMakeFiles/mariokart.dir/src/debugHud.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/debugHud.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/debugHud.c > CMakeFiles/mariokart.dir/src/debugHud.c.i

CMakeFiles/mariokart.dir/src/debugHud.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/debugHud.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/debugHud.c -o CMakeFiles/mariokart.dir/src/debugHud.c.s

CMakeFiles/mariokart.dir/src/images.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/images.c.o: ../src/images.c
CMakeFiles/mariokart.dir/src/images.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/mariokart.dir/src/images.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/images.c.o -MF CMakeFiles/mariokart.dir/src/images.c.o.d -o CMakeFiles/mariokart.dir/src/images.c.o -c /home/heath/mk-gint/src/images.c

CMakeFiles/mariokart.dir/src/images.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/images.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/images.c > CMakeFiles/mariokart.dir/src/images.c.i

CMakeFiles/mariokart.dir/src/images.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/images.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/images.c -o CMakeFiles/mariokart.dir/src/images.c.s

CMakeFiles/mariokart.dir/src/main.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/main.c.o: ../src/main.c
CMakeFiles/mariokart.dir/src/main.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/mariokart.dir/src/main.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/main.c.o -MF CMakeFiles/mariokart.dir/src/main.c.o.d -o CMakeFiles/mariokart.dir/src/main.c.o -c /home/heath/mk-gint/src/main.c

CMakeFiles/mariokart.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/main.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/main.c > CMakeFiles/mariokart.dir/src/main.c.i

CMakeFiles/mariokart.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/main.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/main.c -o CMakeFiles/mariokart.dir/src/main.c.s

CMakeFiles/mariokart.dir/src/maths.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/maths.c.o: ../src/maths.c
CMakeFiles/mariokart.dir/src/maths.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/mariokart.dir/src/maths.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/maths.c.o -MF CMakeFiles/mariokart.dir/src/maths.c.o.d -o CMakeFiles/mariokart.dir/src/maths.c.o -c /home/heath/mk-gint/src/maths.c

CMakeFiles/mariokart.dir/src/maths.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/maths.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/maths.c > CMakeFiles/mariokart.dir/src/maths.c.i

CMakeFiles/mariokart.dir/src/maths.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/maths.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/maths.c -o CMakeFiles/mariokart.dir/src/maths.c.s

CMakeFiles/mariokart.dir/src/miniz.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/miniz.c.o: ../src/miniz.c
CMakeFiles/mariokart.dir/src/miniz.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/mariokart.dir/src/miniz.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/miniz.c.o -MF CMakeFiles/mariokart.dir/src/miniz.c.o.d -o CMakeFiles/mariokart.dir/src/miniz.c.o -c /home/heath/mk-gint/src/miniz.c

CMakeFiles/mariokart.dir/src/miniz.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/miniz.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/miniz.c > CMakeFiles/mariokart.dir/src/miniz.c.i

CMakeFiles/mariokart.dir/src/miniz.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/miniz.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/miniz.c -o CMakeFiles/mariokart.dir/src/miniz.c.s

CMakeFiles/mariokart.dir/src/particles.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/particles.c.o: ../src/particles.c
CMakeFiles/mariokart.dir/src/particles.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/mariokart.dir/src/particles.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/particles.c.o -MF CMakeFiles/mariokart.dir/src/particles.c.o.d -o CMakeFiles/mariokart.dir/src/particles.c.o -c /home/heath/mk-gint/src/particles.c

CMakeFiles/mariokart.dir/src/particles.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/particles.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/particles.c > CMakeFiles/mariokart.dir/src/particles.c.i

CMakeFiles/mariokart.dir/src/particles.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/particles.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/particles.c -o CMakeFiles/mariokart.dir/src/particles.c.s

CMakeFiles/mariokart.dir/src/physics.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/physics.c.o: ../src/physics.c
CMakeFiles/mariokart.dir/src/physics.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/mariokart.dir/src/physics.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/physics.c.o -MF CMakeFiles/mariokart.dir/src/physics.c.o.d -o CMakeFiles/mariokart.dir/src/physics.c.o -c /home/heath/mk-gint/src/physics.c

CMakeFiles/mariokart.dir/src/physics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/physics.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/physics.c > CMakeFiles/mariokart.dir/src/physics.c.i

CMakeFiles/mariokart.dir/src/physics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/physics.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/physics.c -o CMakeFiles/mariokart.dir/src/physics.c.s

CMakeFiles/mariokart.dir/src/sprites.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/sprites.c.o: ../src/sprites.c
CMakeFiles/mariokart.dir/src/sprites.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/mariokart.dir/src/sprites.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/sprites.c.o -MF CMakeFiles/mariokart.dir/src/sprites.c.o.d -o CMakeFiles/mariokart.dir/src/sprites.c.o -c /home/heath/mk-gint/src/sprites.c

CMakeFiles/mariokart.dir/src/sprites.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/sprites.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/sprites.c > CMakeFiles/mariokart.dir/src/sprites.c.i

CMakeFiles/mariokart.dir/src/sprites.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/sprites.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/sprites.c -o CMakeFiles/mariokart.dir/src/sprites.c.s

CMakeFiles/mariokart.dir/src/state.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/state.c.o: ../src/state.c
CMakeFiles/mariokart.dir/src/state.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/mariokart.dir/src/state.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/state.c.o -MF CMakeFiles/mariokart.dir/src/state.c.o.d -o CMakeFiles/mariokart.dir/src/state.c.o -c /home/heath/mk-gint/src/state.c

CMakeFiles/mariokart.dir/src/state.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/state.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/state.c > CMakeFiles/mariokart.dir/src/state.c.i

CMakeFiles/mariokart.dir/src/state.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/state.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/state.c -o CMakeFiles/mariokart.dir/src/state.c.s

CMakeFiles/mariokart.dir/src/tilemap.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/tilemap.c.o: ../src/tilemap.c
CMakeFiles/mariokart.dir/src/tilemap.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/mariokart.dir/src/tilemap.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/tilemap.c.o -MF CMakeFiles/mariokart.dir/src/tilemap.c.o.d -o CMakeFiles/mariokart.dir/src/tilemap.c.o -c /home/heath/mk-gint/src/tilemap.c

CMakeFiles/mariokart.dir/src/tilemap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/tilemap.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/tilemap.c > CMakeFiles/mariokart.dir/src/tilemap.c.i

CMakeFiles/mariokart.dir/src/tilemap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/tilemap.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/tilemap.c -o CMakeFiles/mariokart.dir/src/tilemap.c.s

CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o: CMakeFiles/mariokart.dir/flags.make
CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o: ../src/platforms/emscripten.c
CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o: CMakeFiles/mariokart.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o -MF CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o.d -o CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o -c /home/heath/mk-gint/src/platforms/emscripten.c

CMakeFiles/mariokart.dir/src/platforms/emscripten.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mariokart.dir/src/platforms/emscripten.c.i"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/heath/mk-gint/src/platforms/emscripten.c > CMakeFiles/mariokart.dir/src/platforms/emscripten.c.i

CMakeFiles/mariokart.dir/src/platforms/emscripten.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mariokart.dir/src/platforms/emscripten.c.s"
	/usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/heath/mk-gint/src/platforms/emscripten.c -o CMakeFiles/mariokart.dir/src/platforms/emscripten.c.s

# Object files for target mariokart
mariokart_OBJECTS = \
"CMakeFiles/mariokart.dir/src/3d.c.o" \
"CMakeFiles/mariokart.dir/src/buttons.c.o" \
"CMakeFiles/mariokart.dir/src/configurableConstants.c.o" \
"CMakeFiles/mariokart.dir/src/data.c.o" \
"CMakeFiles/mariokart.dir/src/debugHud.c.o" \
"CMakeFiles/mariokart.dir/src/images.c.o" \
"CMakeFiles/mariokart.dir/src/main.c.o" \
"CMakeFiles/mariokart.dir/src/maths.c.o" \
"CMakeFiles/mariokart.dir/src/miniz.c.o" \
"CMakeFiles/mariokart.dir/src/particles.c.o" \
"CMakeFiles/mariokart.dir/src/physics.c.o" \
"CMakeFiles/mariokart.dir/src/sprites.c.o" \
"CMakeFiles/mariokart.dir/src/state.c.o" \
"CMakeFiles/mariokart.dir/src/tilemap.c.o" \
"CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o"

# External object files for target mariokart
mariokart_EXTERNAL_OBJECTS =

mariokart.html: CMakeFiles/mariokart.dir/src/3d.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/buttons.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/configurableConstants.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/data.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/debugHud.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/images.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/main.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/maths.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/miniz.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/particles.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/physics.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/sprites.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/state.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/tilemap.c.o
mariokart.html: CMakeFiles/mariokart.dir/src/platforms/emscripten.c.o
mariokart.html: CMakeFiles/mariokart.dir/build.make
mariokart.html: CMakeFiles/mariokart.dir/objects1.rsp
mariokart.html: CMakeFiles/mariokart.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heath/mk-gint/build-em/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking C executable mariokart.html"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mariokart.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mariokart.dir/build: mariokart.html
.PHONY : CMakeFiles/mariokart.dir/build

CMakeFiles/mariokart.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mariokart.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mariokart.dir/clean

CMakeFiles/mariokart.dir/depend:
	cd /home/heath/mk-gint/build-em && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heath/mk-gint /home/heath/mk-gint /home/heath/mk-gint/build-em /home/heath/mk-gint/build-em /home/heath/mk-gint/build-em/CMakeFiles/mariokart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mariokart.dir/depend

