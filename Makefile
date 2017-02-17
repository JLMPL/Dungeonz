# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dominik/Desktop/Rekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dominik/Desktop/Rekt

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dominik/Desktop/Rekt/CMakeFiles /home/dominik/Desktop/Rekt/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dominik/Desktop/Rekt/CMakeFiles 0
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
# Target rules for targets named out

# Build rule for target.
out: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 out
.PHONY : out

# fast build rule for target.
out/fast:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/build
.PHONY : out/fast

src/ai/ai.o: src/ai/ai.cpp.o

.PHONY : src/ai/ai.o

# target to build an object file
src/ai/ai.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai.cpp.o
.PHONY : src/ai/ai.cpp.o

src/ai/ai.i: src/ai/ai.cpp.i

.PHONY : src/ai/ai.i

# target to preprocess a source file
src/ai/ai.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai.cpp.i
.PHONY : src/ai/ai.cpp.i

src/ai/ai.s: src/ai/ai.cpp.s

.PHONY : src/ai/ai.s

# target to generate assembly for a file
src/ai/ai.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai.cpp.s
.PHONY : src/ai/ai.cpp.s

src/ai/ai_mob.o: src/ai/ai_mob.cpp.o

.PHONY : src/ai/ai_mob.o

# target to build an object file
src/ai/ai_mob.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai_mob.cpp.o
.PHONY : src/ai/ai_mob.cpp.o

src/ai/ai_mob.i: src/ai/ai_mob.cpp.i

.PHONY : src/ai/ai_mob.i

# target to preprocess a source file
src/ai/ai_mob.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai_mob.cpp.i
.PHONY : src/ai/ai_mob.cpp.i

src/ai/ai_mob.s: src/ai/ai_mob.cpp.s

.PHONY : src/ai/ai_mob.s

# target to generate assembly for a file
src/ai/ai_mob.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai_mob.cpp.s
.PHONY : src/ai/ai_mob.cpp.s

src/ai/ai_player.o: src/ai/ai_player.cpp.o

.PHONY : src/ai/ai_player.o

# target to build an object file
src/ai/ai_player.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai_player.cpp.o
.PHONY : src/ai/ai_player.cpp.o

src/ai/ai_player.i: src/ai/ai_player.cpp.i

.PHONY : src/ai/ai_player.i

# target to preprocess a source file
src/ai/ai_player.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai_player.cpp.i
.PHONY : src/ai/ai_player.cpp.i

src/ai/ai_player.s: src/ai/ai_player.cpp.s

.PHONY : src/ai/ai_player.s

# target to generate assembly for a file
src/ai/ai_player.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/ai/ai_player.cpp.s
.PHONY : src/ai/ai_player.cpp.s

src/base64/base64.o: src/base64/base64.cpp.o

.PHONY : src/base64/base64.o

# target to build an object file
src/base64/base64.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/base64/base64.cpp.o
.PHONY : src/base64/base64.cpp.o

src/base64/base64.i: src/base64/base64.cpp.i

.PHONY : src/base64/base64.i

# target to preprocess a source file
src/base64/base64.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/base64/base64.cpp.i
.PHONY : src/base64/base64.cpp.i

src/base64/base64.s: src/base64/base64.cpp.s

.PHONY : src/base64/base64.s

# target to generate assembly for a file
src/base64/base64.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/base64/base64.cpp.s
.PHONY : src/base64/base64.cpp.s

src/collision/collision_handler.o: src/collision/collision_handler.cpp.o

.PHONY : src/collision/collision_handler.o

# target to build an object file
src/collision/collision_handler.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/collision/collision_handler.cpp.o
.PHONY : src/collision/collision_handler.cpp.o

src/collision/collision_handler.i: src/collision/collision_handler.cpp.i

.PHONY : src/collision/collision_handler.i

# target to preprocess a source file
src/collision/collision_handler.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/collision/collision_handler.cpp.i
.PHONY : src/collision/collision_handler.cpp.i

src/collision/collision_handler.s: src/collision/collision_handler.cpp.s

.PHONY : src/collision/collision_handler.s

# target to generate assembly for a file
src/collision/collision_handler.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/collision/collision_handler.cpp.s
.PHONY : src/collision/collision_handler.cpp.s

src/core/game.o: src/core/game.cpp.o

.PHONY : src/core/game.o

# target to build an object file
src/core/game.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/core/game.cpp.o
.PHONY : src/core/game.cpp.o

src/core/game.i: src/core/game.cpp.i

.PHONY : src/core/game.i

# target to preprocess a source file
src/core/game.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/core/game.cpp.i
.PHONY : src/core/game.cpp.i

src/core/game.s: src/core/game.cpp.s

.PHONY : src/core/game.s

# target to generate assembly for a file
src/core/game.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/core/game.cpp.s
.PHONY : src/core/game.cpp.s

src/gameplay/chest.o: src/gameplay/chest.cpp.o

.PHONY : src/gameplay/chest.o

# target to build an object file
src/gameplay/chest.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/chest.cpp.o
.PHONY : src/gameplay/chest.cpp.o

src/gameplay/chest.i: src/gameplay/chest.cpp.i

.PHONY : src/gameplay/chest.i

# target to preprocess a source file
src/gameplay/chest.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/chest.cpp.i
.PHONY : src/gameplay/chest.cpp.i

src/gameplay/chest.s: src/gameplay/chest.cpp.s

.PHONY : src/gameplay/chest.s

# target to generate assembly for a file
src/gameplay/chest.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/chest.cpp.s
.PHONY : src/gameplay/chest.cpp.s

src/gameplay/door.o: src/gameplay/door.cpp.o

.PHONY : src/gameplay/door.o

# target to build an object file
src/gameplay/door.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/door.cpp.o
.PHONY : src/gameplay/door.cpp.o

src/gameplay/door.i: src/gameplay/door.cpp.i

.PHONY : src/gameplay/door.i

# target to preprocess a source file
src/gameplay/door.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/door.cpp.i
.PHONY : src/gameplay/door.cpp.i

src/gameplay/door.s: src/gameplay/door.cpp.s

.PHONY : src/gameplay/door.s

# target to generate assembly for a file
src/gameplay/door.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/door.cpp.s
.PHONY : src/gameplay/door.cpp.s

src/gameplay/entity.o: src/gameplay/entity.cpp.o

.PHONY : src/gameplay/entity.o

# target to build an object file
src/gameplay/entity.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/entity.cpp.o
.PHONY : src/gameplay/entity.cpp.o

src/gameplay/entity.i: src/gameplay/entity.cpp.i

.PHONY : src/gameplay/entity.i

# target to preprocess a source file
src/gameplay/entity.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/entity.cpp.i
.PHONY : src/gameplay/entity.cpp.i

src/gameplay/entity.s: src/gameplay/entity.cpp.s

.PHONY : src/gameplay/entity.s

# target to generate assembly for a file
src/gameplay/entity.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/entity.cpp.s
.PHONY : src/gameplay/entity.cpp.s

src/gameplay/inventory.o: src/gameplay/inventory.cpp.o

.PHONY : src/gameplay/inventory.o

# target to build an object file
src/gameplay/inventory.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/inventory.cpp.o
.PHONY : src/gameplay/inventory.cpp.o

src/gameplay/inventory.i: src/gameplay/inventory.cpp.i

.PHONY : src/gameplay/inventory.i

# target to preprocess a source file
src/gameplay/inventory.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/inventory.cpp.i
.PHONY : src/gameplay/inventory.cpp.i

src/gameplay/inventory.s: src/gameplay/inventory.cpp.s

.PHONY : src/gameplay/inventory.s

# target to generate assembly for a file
src/gameplay/inventory.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/inventory.cpp.s
.PHONY : src/gameplay/inventory.cpp.s

src/gameplay/item.o: src/gameplay/item.cpp.o

.PHONY : src/gameplay/item.o

# target to build an object file
src/gameplay/item.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/item.cpp.o
.PHONY : src/gameplay/item.cpp.o

src/gameplay/item.i: src/gameplay/item.cpp.i

.PHONY : src/gameplay/item.i

# target to preprocess a source file
src/gameplay/item.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/item.cpp.i
.PHONY : src/gameplay/item.cpp.i

src/gameplay/item.s: src/gameplay/item.cpp.s

.PHONY : src/gameplay/item.s

# target to generate assembly for a file
src/gameplay/item.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/item.cpp.s
.PHONY : src/gameplay/item.cpp.s

src/gameplay/level.o: src/gameplay/level.cpp.o

.PHONY : src/gameplay/level.o

# target to build an object file
src/gameplay/level.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/level.cpp.o
.PHONY : src/gameplay/level.cpp.o

src/gameplay/level.i: src/gameplay/level.cpp.i

.PHONY : src/gameplay/level.i

# target to preprocess a source file
src/gameplay/level.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/level.cpp.i
.PHONY : src/gameplay/level.cpp.i

src/gameplay/level.s: src/gameplay/level.cpp.s

.PHONY : src/gameplay/level.s

# target to generate assembly for a file
src/gameplay/level.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/level.cpp.s
.PHONY : src/gameplay/level.cpp.s

src/gameplay/lever.o: src/gameplay/lever.cpp.o

.PHONY : src/gameplay/lever.o

# target to build an object file
src/gameplay/lever.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/lever.cpp.o
.PHONY : src/gameplay/lever.cpp.o

src/gameplay/lever.i: src/gameplay/lever.cpp.i

.PHONY : src/gameplay/lever.i

# target to preprocess a source file
src/gameplay/lever.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/lever.cpp.i
.PHONY : src/gameplay/lever.cpp.i

src/gameplay/lever.s: src/gameplay/lever.cpp.s

.PHONY : src/gameplay/lever.s

# target to generate assembly for a file
src/gameplay/lever.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/lever.cpp.s
.PHONY : src/gameplay/lever.cpp.s

src/gameplay/living.o: src/gameplay/living.cpp.o

.PHONY : src/gameplay/living.o

# target to build an object file
src/gameplay/living.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/living.cpp.o
.PHONY : src/gameplay/living.cpp.o

src/gameplay/living.i: src/gameplay/living.cpp.i

.PHONY : src/gameplay/living.i

# target to preprocess a source file
src/gameplay/living.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/living.cpp.i
.PHONY : src/gameplay/living.cpp.i

src/gameplay/living.s: src/gameplay/living.cpp.s

.PHONY : src/gameplay/living.s

# target to generate assembly for a file
src/gameplay/living.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/living.cpp.s
.PHONY : src/gameplay/living.cpp.s

src/gameplay/map.o: src/gameplay/map.cpp.o

.PHONY : src/gameplay/map.o

# target to build an object file
src/gameplay/map.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/map.cpp.o
.PHONY : src/gameplay/map.cpp.o

src/gameplay/map.i: src/gameplay/map.cpp.i

.PHONY : src/gameplay/map.i

# target to preprocess a source file
src/gameplay/map.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/map.cpp.i
.PHONY : src/gameplay/map.cpp.i

src/gameplay/map.s: src/gameplay/map.cpp.s

.PHONY : src/gameplay/map.s

# target to generate assembly for a file
src/gameplay/map.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/map.cpp.s
.PHONY : src/gameplay/map.cpp.s

src/gameplay/spike_trap.o: src/gameplay/spike_trap.cpp.o

.PHONY : src/gameplay/spike_trap.o

# target to build an object file
src/gameplay/spike_trap.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/spike_trap.cpp.o
.PHONY : src/gameplay/spike_trap.cpp.o

src/gameplay/spike_trap.i: src/gameplay/spike_trap.cpp.i

.PHONY : src/gameplay/spike_trap.i

# target to preprocess a source file
src/gameplay/spike_trap.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/spike_trap.cpp.i
.PHONY : src/gameplay/spike_trap.cpp.i

src/gameplay/spike_trap.s: src/gameplay/spike_trap.cpp.s

.PHONY : src/gameplay/spike_trap.s

# target to generate assembly for a file
src/gameplay/spike_trap.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gameplay/spike_trap.cpp.s
.PHONY : src/gameplay/spike_trap.cpp.s

src/gui/graphic_inv.o: src/gui/graphic_inv.cpp.o

.PHONY : src/gui/graphic_inv.o

# target to build an object file
src/gui/graphic_inv.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/graphic_inv.cpp.o
.PHONY : src/gui/graphic_inv.cpp.o

src/gui/graphic_inv.i: src/gui/graphic_inv.cpp.i

.PHONY : src/gui/graphic_inv.i

# target to preprocess a source file
src/gui/graphic_inv.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/graphic_inv.cpp.i
.PHONY : src/gui/graphic_inv.cpp.i

src/gui/graphic_inv.s: src/gui/graphic_inv.cpp.s

.PHONY : src/gui/graphic_inv.s

# target to generate assembly for a file
src/gui/graphic_inv.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/graphic_inv.cpp.s
.PHONY : src/gui/graphic_inv.cpp.s

src/gui/graphic_loot.o: src/gui/graphic_loot.cpp.o

.PHONY : src/gui/graphic_loot.o

# target to build an object file
src/gui/graphic_loot.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/graphic_loot.cpp.o
.PHONY : src/gui/graphic_loot.cpp.o

src/gui/graphic_loot.i: src/gui/graphic_loot.cpp.i

.PHONY : src/gui/graphic_loot.i

# target to preprocess a source file
src/gui/graphic_loot.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/graphic_loot.cpp.i
.PHONY : src/gui/graphic_loot.cpp.i

src/gui/graphic_loot.s: src/gui/graphic_loot.cpp.s

.PHONY : src/gui/graphic_loot.s

# target to generate assembly for a file
src/gui/graphic_loot.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/graphic_loot.cpp.s
.PHONY : src/gui/graphic_loot.cpp.s

src/gui/gui.o: src/gui/gui.cpp.o

.PHONY : src/gui/gui.o

# target to build an object file
src/gui/gui.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/gui.cpp.o
.PHONY : src/gui/gui.cpp.o

src/gui/gui.i: src/gui/gui.cpp.i

.PHONY : src/gui/gui.i

# target to preprocess a source file
src/gui/gui.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/gui.cpp.i
.PHONY : src/gui/gui.cpp.i

src/gui/gui.s: src/gui/gui.cpp.s

.PHONY : src/gui/gui.s

# target to generate assembly for a file
src/gui/gui.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/gui.cpp.s
.PHONY : src/gui/gui.cpp.s

src/gui/slot.o: src/gui/slot.cpp.o

.PHONY : src/gui/slot.o

# target to build an object file
src/gui/slot.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/slot.cpp.o
.PHONY : src/gui/slot.cpp.o

src/gui/slot.i: src/gui/slot.cpp.i

.PHONY : src/gui/slot.i

# target to preprocess a source file
src/gui/slot.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/slot.cpp.i
.PHONY : src/gui/slot.cpp.i

src/gui/slot.s: src/gui/slot.cpp.s

.PHONY : src/gui/slot.s

# target to generate assembly for a file
src/gui/slot.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/gui/slot.cpp.s
.PHONY : src/gui/slot.cpp.s

src/input/input_handler.o: src/input/input_handler.cpp.o

.PHONY : src/input/input_handler.o

# target to build an object file
src/input/input_handler.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/input/input_handler.cpp.o
.PHONY : src/input/input_handler.cpp.o

src/input/input_handler.i: src/input/input_handler.cpp.i

.PHONY : src/input/input_handler.i

# target to preprocess a source file
src/input/input_handler.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/input/input_handler.cpp.i
.PHONY : src/input/input_handler.cpp.i

src/input/input_handler.s: src/input/input_handler.cpp.s

.PHONY : src/input/input_handler.s

# target to generate assembly for a file
src/input/input_handler.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/input/input_handler.cpp.s
.PHONY : src/input/input_handler.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/render/animated_sprite.o: src/render/animated_sprite.cpp.o

.PHONY : src/render/animated_sprite.o

# target to build an object file
src/render/animated_sprite.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/animated_sprite.cpp.o
.PHONY : src/render/animated_sprite.cpp.o

src/render/animated_sprite.i: src/render/animated_sprite.cpp.i

.PHONY : src/render/animated_sprite.i

# target to preprocess a source file
src/render/animated_sprite.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/animated_sprite.cpp.i
.PHONY : src/render/animated_sprite.cpp.i

src/render/animated_sprite.s: src/render/animated_sprite.cpp.s

.PHONY : src/render/animated_sprite.s

# target to generate assembly for a file
src/render/animated_sprite.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/animated_sprite.cpp.s
.PHONY : src/render/animated_sprite.cpp.s

src/render/bar.o: src/render/bar.cpp.o

.PHONY : src/render/bar.o

# target to build an object file
src/render/bar.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/bar.cpp.o
.PHONY : src/render/bar.cpp.o

src/render/bar.i: src/render/bar.cpp.i

.PHONY : src/render/bar.i

# target to preprocess a source file
src/render/bar.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/bar.cpp.i
.PHONY : src/render/bar.cpp.i

src/render/bar.s: src/render/bar.cpp.s

.PHONY : src/render/bar.s

# target to generate assembly for a file
src/render/bar.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/bar.cpp.s
.PHONY : src/render/bar.cpp.s

src/render/big_particle.o: src/render/big_particle.cpp.o

.PHONY : src/render/big_particle.o

# target to build an object file
src/render/big_particle.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/big_particle.cpp.o
.PHONY : src/render/big_particle.cpp.o

src/render/big_particle.i: src/render/big_particle.cpp.i

.PHONY : src/render/big_particle.i

# target to preprocess a source file
src/render/big_particle.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/big_particle.cpp.i
.PHONY : src/render/big_particle.cpp.i

src/render/big_particle.s: src/render/big_particle.cpp.s

.PHONY : src/render/big_particle.s

# target to generate assembly for a file
src/render/big_particle.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/big_particle.cpp.s
.PHONY : src/render/big_particle.cpp.s

src/render/indication_handler.o: src/render/indication_handler.cpp.o

.PHONY : src/render/indication_handler.o

# target to build an object file
src/render/indication_handler.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/indication_handler.cpp.o
.PHONY : src/render/indication_handler.cpp.o

src/render/indication_handler.i: src/render/indication_handler.cpp.i

.PHONY : src/render/indication_handler.i

# target to preprocess a source file
src/render/indication_handler.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/indication_handler.cpp.i
.PHONY : src/render/indication_handler.cpp.i

src/render/indication_handler.s: src/render/indication_handler.cpp.s

.PHONY : src/render/indication_handler.s

# target to generate assembly for a file
src/render/indication_handler.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/indication_handler.cpp.s
.PHONY : src/render/indication_handler.cpp.s

src/render/renderer.o: src/render/renderer.cpp.o

.PHONY : src/render/renderer.o

# target to build an object file
src/render/renderer.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/renderer.cpp.o
.PHONY : src/render/renderer.cpp.o

src/render/renderer.i: src/render/renderer.cpp.i

.PHONY : src/render/renderer.i

# target to preprocess a source file
src/render/renderer.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/renderer.cpp.i
.PHONY : src/render/renderer.cpp.i

src/render/renderer.s: src/render/renderer.cpp.s

.PHONY : src/render/renderer.s

# target to generate assembly for a file
src/render/renderer.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/renderer.cpp.s
.PHONY : src/render/renderer.cpp.s

src/render/sprite.o: src/render/sprite.cpp.o

.PHONY : src/render/sprite.o

# target to build an object file
src/render/sprite.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/sprite.cpp.o
.PHONY : src/render/sprite.cpp.o

src/render/sprite.i: src/render/sprite.cpp.i

.PHONY : src/render/sprite.i

# target to preprocess a source file
src/render/sprite.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/sprite.cpp.i
.PHONY : src/render/sprite.cpp.i

src/render/sprite.s: src/render/sprite.cpp.s

.PHONY : src/render/sprite.s

# target to generate assembly for a file
src/render/sprite.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/render/sprite.cpp.s
.PHONY : src/render/sprite.cpp.s

src/resource/animation.o: src/resource/animation.cpp.o

.PHONY : src/resource/animation.o

# target to build an object file
src/resource/animation.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/animation.cpp.o
.PHONY : src/resource/animation.cpp.o

src/resource/animation.i: src/resource/animation.cpp.i

.PHONY : src/resource/animation.i

# target to preprocess a source file
src/resource/animation.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/animation.cpp.i
.PHONY : src/resource/animation.cpp.i

src/resource/animation.s: src/resource/animation.cpp.s

.PHONY : src/resource/animation.s

# target to generate assembly for a file
src/resource/animation.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/animation.cpp.s
.PHONY : src/resource/animation.cpp.s

src/resource/animation_cache.o: src/resource/animation_cache.cpp.o

.PHONY : src/resource/animation_cache.o

# target to build an object file
src/resource/animation_cache.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/animation_cache.cpp.o
.PHONY : src/resource/animation_cache.cpp.o

src/resource/animation_cache.i: src/resource/animation_cache.cpp.i

.PHONY : src/resource/animation_cache.i

# target to preprocess a source file
src/resource/animation_cache.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/animation_cache.cpp.i
.PHONY : src/resource/animation_cache.cpp.i

src/resource/animation_cache.s: src/resource/animation_cache.cpp.s

.PHONY : src/resource/animation_cache.s

# target to generate assembly for a file
src/resource/animation_cache.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/animation_cache.cpp.s
.PHONY : src/resource/animation_cache.cpp.s

src/resource/font_cache.o: src/resource/font_cache.cpp.o

.PHONY : src/resource/font_cache.o

# target to build an object file
src/resource/font_cache.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/font_cache.cpp.o
.PHONY : src/resource/font_cache.cpp.o

src/resource/font_cache.i: src/resource/font_cache.cpp.i

.PHONY : src/resource/font_cache.i

# target to preprocess a source file
src/resource/font_cache.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/font_cache.cpp.i
.PHONY : src/resource/font_cache.cpp.i

src/resource/font_cache.s: src/resource/font_cache.cpp.s

.PHONY : src/resource/font_cache.s

# target to generate assembly for a file
src/resource/font_cache.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/font_cache.cpp.s
.PHONY : src/resource/font_cache.cpp.s

src/resource/texture_cache.o: src/resource/texture_cache.cpp.o

.PHONY : src/resource/texture_cache.o

# target to build an object file
src/resource/texture_cache.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/texture_cache.cpp.o
.PHONY : src/resource/texture_cache.cpp.o

src/resource/texture_cache.i: src/resource/texture_cache.cpp.i

.PHONY : src/resource/texture_cache.i

# target to preprocess a source file
src/resource/texture_cache.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/texture_cache.cpp.i
.PHONY : src/resource/texture_cache.cpp.i

src/resource/texture_cache.s: src/resource/texture_cache.cpp.s

.PHONY : src/resource/texture_cache.s

# target to generate assembly for a file
src/resource/texture_cache.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/resource/texture_cache.cpp.s
.PHONY : src/resource/texture_cache.cpp.s

src/script/lua_interface.o: src/script/lua_interface.cpp.o

.PHONY : src/script/lua_interface.o

# target to build an object file
src/script/lua_interface.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/script/lua_interface.cpp.o
.PHONY : src/script/lua_interface.cpp.o

src/script/lua_interface.i: src/script/lua_interface.cpp.i

.PHONY : src/script/lua_interface.i

# target to preprocess a source file
src/script/lua_interface.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/script/lua_interface.cpp.i
.PHONY : src/script/lua_interface.cpp.i

src/script/lua_interface.s: src/script/lua_interface.cpp.s

.PHONY : src/script/lua_interface.s

# target to generate assembly for a file
src/script/lua_interface.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/script/lua_interface.cpp.s
.PHONY : src/script/lua_interface.cpp.s

src/script/script_handler.o: src/script/script_handler.cpp.o

.PHONY : src/script/script_handler.o

# target to build an object file
src/script/script_handler.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/script/script_handler.cpp.o
.PHONY : src/script/script_handler.cpp.o

src/script/script_handler.i: src/script/script_handler.cpp.i

.PHONY : src/script/script_handler.i

# target to preprocess a source file
src/script/script_handler.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/script/script_handler.cpp.i
.PHONY : src/script/script_handler.cpp.i

src/script/script_handler.s: src/script/script_handler.cpp.s

.PHONY : src/script/script_handler.s

# target to generate assembly for a file
src/script/script_handler.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/script/script_handler.cpp.s
.PHONY : src/script/script_handler.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... out"
	@echo "... src/ai/ai.o"
	@echo "... src/ai/ai.i"
	@echo "... src/ai/ai.s"
	@echo "... src/ai/ai_mob.o"
	@echo "... src/ai/ai_mob.i"
	@echo "... src/ai/ai_mob.s"
	@echo "... src/ai/ai_player.o"
	@echo "... src/ai/ai_player.i"
	@echo "... src/ai/ai_player.s"
	@echo "... src/base64/base64.o"
	@echo "... src/base64/base64.i"
	@echo "... src/base64/base64.s"
	@echo "... src/collision/collision_handler.o"
	@echo "... src/collision/collision_handler.i"
	@echo "... src/collision/collision_handler.s"
	@echo "... src/core/game.o"
	@echo "... src/core/game.i"
	@echo "... src/core/game.s"
	@echo "... src/gameplay/chest.o"
	@echo "... src/gameplay/chest.i"
	@echo "... src/gameplay/chest.s"
	@echo "... src/gameplay/door.o"
	@echo "... src/gameplay/door.i"
	@echo "... src/gameplay/door.s"
	@echo "... src/gameplay/entity.o"
	@echo "... src/gameplay/entity.i"
	@echo "... src/gameplay/entity.s"
	@echo "... src/gameplay/inventory.o"
	@echo "... src/gameplay/inventory.i"
	@echo "... src/gameplay/inventory.s"
	@echo "... src/gameplay/item.o"
	@echo "... src/gameplay/item.i"
	@echo "... src/gameplay/item.s"
	@echo "... src/gameplay/level.o"
	@echo "... src/gameplay/level.i"
	@echo "... src/gameplay/level.s"
	@echo "... src/gameplay/lever.o"
	@echo "... src/gameplay/lever.i"
	@echo "... src/gameplay/lever.s"
	@echo "... src/gameplay/living.o"
	@echo "... src/gameplay/living.i"
	@echo "... src/gameplay/living.s"
	@echo "... src/gameplay/map.o"
	@echo "... src/gameplay/map.i"
	@echo "... src/gameplay/map.s"
	@echo "... src/gameplay/spike_trap.o"
	@echo "... src/gameplay/spike_trap.i"
	@echo "... src/gameplay/spike_trap.s"
	@echo "... src/gui/graphic_inv.o"
	@echo "... src/gui/graphic_inv.i"
	@echo "... src/gui/graphic_inv.s"
	@echo "... src/gui/graphic_loot.o"
	@echo "... src/gui/graphic_loot.i"
	@echo "... src/gui/graphic_loot.s"
	@echo "... src/gui/gui.o"
	@echo "... src/gui/gui.i"
	@echo "... src/gui/gui.s"
	@echo "... src/gui/slot.o"
	@echo "... src/gui/slot.i"
	@echo "... src/gui/slot.s"
	@echo "... src/input/input_handler.o"
	@echo "... src/input/input_handler.i"
	@echo "... src/input/input_handler.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/render/animated_sprite.o"
	@echo "... src/render/animated_sprite.i"
	@echo "... src/render/animated_sprite.s"
	@echo "... src/render/bar.o"
	@echo "... src/render/bar.i"
	@echo "... src/render/bar.s"
	@echo "... src/render/big_particle.o"
	@echo "... src/render/big_particle.i"
	@echo "... src/render/big_particle.s"
	@echo "... src/render/indication_handler.o"
	@echo "... src/render/indication_handler.i"
	@echo "... src/render/indication_handler.s"
	@echo "... src/render/renderer.o"
	@echo "... src/render/renderer.i"
	@echo "... src/render/renderer.s"
	@echo "... src/render/sprite.o"
	@echo "... src/render/sprite.i"
	@echo "... src/render/sprite.s"
	@echo "... src/resource/animation.o"
	@echo "... src/resource/animation.i"
	@echo "... src/resource/animation.s"
	@echo "... src/resource/animation_cache.o"
	@echo "... src/resource/animation_cache.i"
	@echo "... src/resource/animation_cache.s"
	@echo "... src/resource/font_cache.o"
	@echo "... src/resource/font_cache.i"
	@echo "... src/resource/font_cache.s"
	@echo "... src/resource/texture_cache.o"
	@echo "... src/resource/texture_cache.i"
	@echo "... src/resource/texture_cache.s"
	@echo "... src/script/lua_interface.o"
	@echo "... src/script/lua_interface.i"
	@echo "... src/script/lua_interface.s"
	@echo "... src/script/script_handler.o"
	@echo "... src/script/script_handler.i"
	@echo "... src/script/script_handler.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

