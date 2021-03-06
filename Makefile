# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /opt/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jii/CLionProjects/MemeSlug

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jii/CLionProjects/MemeSlug

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/clion-2018.1.5/bin/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/opt/clion-2018.1.5/bin/cmake/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jii/CLionProjects/MemeSlug/CMakeFiles /home/jii/CLionProjects/MemeSlug/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jii/CLionProjects/MemeSlug/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named core

# Build rule for target.
core: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 core
.PHONY : core

# fast build rule for target.
core/fast:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/build
.PHONY : core/fast

#=============================================================================
# Target rules for targets named MemeSlug

# Build rule for target.
MemeSlug: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MemeSlug
.PHONY : MemeSlug

# fast build rule for target.
MemeSlug/fast:
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/build
.PHONY : MemeSlug/fast

#=============================================================================
# Target rules for targets named runAllTest

# Build rule for target.
runAllTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 runAllTest
.PHONY : runAllTest

# fast build rule for target.
runAllTest/fast:
	$(MAKE) -f Test/CMakeFiles/runAllTest.dir/build.make Test/CMakeFiles/runAllTest.dir/build
.PHONY : runAllTest/fast

Achievement.o: Achievement.cpp.o

.PHONY : Achievement.o

# target to build an object file
Achievement.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Achievement.cpp.o
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Achievement.cpp.o
.PHONY : Achievement.cpp.o

Achievement.i: Achievement.cpp.i

.PHONY : Achievement.i

# target to preprocess a source file
Achievement.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Achievement.cpp.i
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Achievement.cpp.i
.PHONY : Achievement.cpp.i

Achievement.s: Achievement.cpp.s

.PHONY : Achievement.s

# target to generate assembly for a file
Achievement.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Achievement.cpp.s
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Achievement.cpp.s
.PHONY : Achievement.cpp.s

Bullet.o: Bullet.cpp.o

.PHONY : Bullet.o

# target to build an object file
Bullet.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Bullet.cpp.o
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Bullet.cpp.o
.PHONY : Bullet.cpp.o

Bullet.i: Bullet.cpp.i

.PHONY : Bullet.i

# target to preprocess a source file
Bullet.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Bullet.cpp.i
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Bullet.cpp.i
.PHONY : Bullet.cpp.i

Bullet.s: Bullet.cpp.s

.PHONY : Bullet.s

# target to generate assembly for a file
Bullet.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Bullet.cpp.s
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Bullet.cpp.s
.PHONY : Bullet.cpp.s

Enemy.o: Enemy.cpp.o

.PHONY : Enemy.o

# target to build an object file
Enemy.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Enemy.cpp.o
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Enemy.cpp.o
.PHONY : Enemy.cpp.o

Enemy.i: Enemy.cpp.i

.PHONY : Enemy.i

# target to preprocess a source file
Enemy.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Enemy.cpp.i
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Enemy.cpp.i
.PHONY : Enemy.cpp.i

Enemy.s: Enemy.cpp.s

.PHONY : Enemy.s

# target to generate assembly for a file
Enemy.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Enemy.cpp.s
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Enemy.cpp.s
.PHONY : Enemy.cpp.s

Game.o: Game.cpp.o

.PHONY : Game.o

# target to build an object file
Game.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Game.cpp.o
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Game.cpp.o
.PHONY : Game.cpp.o

Game.i: Game.cpp.i

.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Game.cpp.i
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s

.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Game.cpp.s
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Game.cpp.s
.PHONY : Game.cpp.s

Main.o: Main.cpp.o

.PHONY : Main.o

# target to build an object file
Main.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Main.cpp.o
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Main.cpp.o
.PHONY : Main.cpp.o

Main.i: Main.cpp.i

.PHONY : Main.i

# target to preprocess a source file
Main.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Main.cpp.i
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Main.cpp.i
.PHONY : Main.cpp.i

Main.s: Main.cpp.s

.PHONY : Main.s

# target to generate assembly for a file
Main.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Main.cpp.s
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Main.cpp.s
.PHONY : Main.cpp.s

Pickup.o: Pickup.cpp.o

.PHONY : Pickup.o

# target to build an object file
Pickup.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Pickup.cpp.o
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Pickup.cpp.o
.PHONY : Pickup.cpp.o

Pickup.i: Pickup.cpp.i

.PHONY : Pickup.i

# target to preprocess a source file
Pickup.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Pickup.cpp.i
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Pickup.cpp.i
.PHONY : Pickup.cpp.i

Pickup.s: Pickup.cpp.s

.PHONY : Pickup.s

# target to generate assembly for a file
Pickup.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Pickup.cpp.s
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Pickup.cpp.s
.PHONY : Pickup.cpp.s

Platform.o: Platform.cpp.o

.PHONY : Platform.o

# target to build an object file
Platform.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Platform.cpp.o
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Platform.cpp.o
.PHONY : Platform.cpp.o

Platform.i: Platform.cpp.i

.PHONY : Platform.i

# target to preprocess a source file
Platform.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Platform.cpp.i
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Platform.cpp.i
.PHONY : Platform.cpp.i

Platform.s: Platform.cpp.s

.PHONY : Platform.s

# target to generate assembly for a file
Platform.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Platform.cpp.s
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Platform.cpp.s
.PHONY : Platform.cpp.s

Player.o: Player.cpp.o

.PHONY : Player.o

# target to build an object file
Player.cpp.o:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Player.cpp.o
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Player.cpp.o
.PHONY : Player.cpp.o

Player.i: Player.cpp.i

.PHONY : Player.i

# target to preprocess a source file
Player.cpp.i:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Player.cpp.i
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Player.cpp.i
.PHONY : Player.cpp.i

Player.s: Player.cpp.s

.PHONY : Player.s

# target to generate assembly for a file
Player.cpp.s:
	$(MAKE) -f CMakeFiles/core.dir/build.make CMakeFiles/core.dir/Player.cpp.s
	$(MAKE) -f CMakeFiles/MemeSlug.dir/build.make CMakeFiles/MemeSlug.dir/Player.cpp.s
.PHONY : Player.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... core"
	@echo "... MemeSlug"
	@echo "... runAllTest"
	@echo "... Achievement.o"
	@echo "... Achievement.i"
	@echo "... Achievement.s"
	@echo "... Bullet.o"
	@echo "... Bullet.i"
	@echo "... Bullet.s"
	@echo "... Enemy.o"
	@echo "... Enemy.i"
	@echo "... Enemy.s"
	@echo "... Game.o"
	@echo "... Game.i"
	@echo "... Game.s"
	@echo "... Main.o"
	@echo "... Main.i"
	@echo "... Main.s"
	@echo "... Pickup.o"
	@echo "... Pickup.i"
	@echo "... Pickup.s"
	@echo "... Platform.o"
	@echo "... Platform.i"
	@echo "... Platform.s"
	@echo "... Player.o"
	@echo "... Player.i"
	@echo "... Player.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

