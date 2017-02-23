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

src/Ai/Ai.o: src/Ai/Ai.cpp.o

.PHONY : src/Ai/Ai.o

# target to build an object file
src/Ai/Ai.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/Ai.cpp.o
.PHONY : src/Ai/Ai.cpp.o

src/Ai/Ai.i: src/Ai/Ai.cpp.i

.PHONY : src/Ai/Ai.i

# target to preprocess a source file
src/Ai/Ai.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/Ai.cpp.i
.PHONY : src/Ai/Ai.cpp.i

src/Ai/Ai.s: src/Ai/Ai.cpp.s

.PHONY : src/Ai/Ai.s

# target to generate assembly for a file
src/Ai/Ai.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/Ai.cpp.s
.PHONY : src/Ai/Ai.cpp.s

src/Ai/AiMob.o: src/Ai/AiMob.cpp.o

.PHONY : src/Ai/AiMob.o

# target to build an object file
src/Ai/AiMob.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/AiMob.cpp.o
.PHONY : src/Ai/AiMob.cpp.o

src/Ai/AiMob.i: src/Ai/AiMob.cpp.i

.PHONY : src/Ai/AiMob.i

# target to preprocess a source file
src/Ai/AiMob.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/AiMob.cpp.i
.PHONY : src/Ai/AiMob.cpp.i

src/Ai/AiMob.s: src/Ai/AiMob.cpp.s

.PHONY : src/Ai/AiMob.s

# target to generate assembly for a file
src/Ai/AiMob.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/AiMob.cpp.s
.PHONY : src/Ai/AiMob.cpp.s

src/Ai/AiPlayer.o: src/Ai/AiPlayer.cpp.o

.PHONY : src/Ai/AiPlayer.o

# target to build an object file
src/Ai/AiPlayer.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/AiPlayer.cpp.o
.PHONY : src/Ai/AiPlayer.cpp.o

src/Ai/AiPlayer.i: src/Ai/AiPlayer.cpp.i

.PHONY : src/Ai/AiPlayer.i

# target to preprocess a source file
src/Ai/AiPlayer.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/AiPlayer.cpp.i
.PHONY : src/Ai/AiPlayer.cpp.i

src/Ai/AiPlayer.s: src/Ai/AiPlayer.cpp.s

.PHONY : src/Ai/AiPlayer.s

# target to generate assembly for a file
src/Ai/AiPlayer.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Ai/AiPlayer.cpp.s
.PHONY : src/Ai/AiPlayer.cpp.s

src/Collision/CollisionHandler.o: src/Collision/CollisionHandler.cpp.o

.PHONY : src/Collision/CollisionHandler.o

# target to build an object file
src/Collision/CollisionHandler.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Collision/CollisionHandler.cpp.o
.PHONY : src/Collision/CollisionHandler.cpp.o

src/Collision/CollisionHandler.i: src/Collision/CollisionHandler.cpp.i

.PHONY : src/Collision/CollisionHandler.i

# target to preprocess a source file
src/Collision/CollisionHandler.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Collision/CollisionHandler.cpp.i
.PHONY : src/Collision/CollisionHandler.cpp.i

src/Collision/CollisionHandler.s: src/Collision/CollisionHandler.cpp.s

.PHONY : src/Collision/CollisionHandler.s

# target to generate assembly for a file
src/Collision/CollisionHandler.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Collision/CollisionHandler.cpp.s
.PHONY : src/Collision/CollisionHandler.cpp.s

src/Core/Game.o: src/Core/Game.cpp.o

.PHONY : src/Core/Game.o

# target to build an object file
src/Core/Game.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Core/Game.cpp.o
.PHONY : src/Core/Game.cpp.o

src/Core/Game.i: src/Core/Game.cpp.i

.PHONY : src/Core/Game.i

# target to preprocess a source file
src/Core/Game.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Core/Game.cpp.i
.PHONY : src/Core/Game.cpp.i

src/Core/Game.s: src/Core/Game.cpp.s

.PHONY : src/Core/Game.s

# target to generate assembly for a file
src/Core/Game.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Core/Game.cpp.s
.PHONY : src/Core/Game.cpp.s

src/Gameplay/Chest.o: src/Gameplay/Chest.cpp.o

.PHONY : src/Gameplay/Chest.o

# target to build an object file
src/Gameplay/Chest.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Chest.cpp.o
.PHONY : src/Gameplay/Chest.cpp.o

src/Gameplay/Chest.i: src/Gameplay/Chest.cpp.i

.PHONY : src/Gameplay/Chest.i

# target to preprocess a source file
src/Gameplay/Chest.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Chest.cpp.i
.PHONY : src/Gameplay/Chest.cpp.i

src/Gameplay/Chest.s: src/Gameplay/Chest.cpp.s

.PHONY : src/Gameplay/Chest.s

# target to generate assembly for a file
src/Gameplay/Chest.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Chest.cpp.s
.PHONY : src/Gameplay/Chest.cpp.s

src/Gameplay/Door.o: src/Gameplay/Door.cpp.o

.PHONY : src/Gameplay/Door.o

# target to build an object file
src/Gameplay/Door.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Door.cpp.o
.PHONY : src/Gameplay/Door.cpp.o

src/Gameplay/Door.i: src/Gameplay/Door.cpp.i

.PHONY : src/Gameplay/Door.i

# target to preprocess a source file
src/Gameplay/Door.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Door.cpp.i
.PHONY : src/Gameplay/Door.cpp.i

src/Gameplay/Door.s: src/Gameplay/Door.cpp.s

.PHONY : src/Gameplay/Door.s

# target to generate assembly for a file
src/Gameplay/Door.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Door.cpp.s
.PHONY : src/Gameplay/Door.cpp.s

src/Gameplay/Entity.o: src/Gameplay/Entity.cpp.o

.PHONY : src/Gameplay/Entity.o

# target to build an object file
src/Gameplay/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Entity.cpp.o
.PHONY : src/Gameplay/Entity.cpp.o

src/Gameplay/Entity.i: src/Gameplay/Entity.cpp.i

.PHONY : src/Gameplay/Entity.i

# target to preprocess a source file
src/Gameplay/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Entity.cpp.i
.PHONY : src/Gameplay/Entity.cpp.i

src/Gameplay/Entity.s: src/Gameplay/Entity.cpp.s

.PHONY : src/Gameplay/Entity.s

# target to generate assembly for a file
src/Gameplay/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Entity.cpp.s
.PHONY : src/Gameplay/Entity.cpp.s

src/Gameplay/Inventory.o: src/Gameplay/Inventory.cpp.o

.PHONY : src/Gameplay/Inventory.o

# target to build an object file
src/Gameplay/Inventory.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Inventory.cpp.o
.PHONY : src/Gameplay/Inventory.cpp.o

src/Gameplay/Inventory.i: src/Gameplay/Inventory.cpp.i

.PHONY : src/Gameplay/Inventory.i

# target to preprocess a source file
src/Gameplay/Inventory.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Inventory.cpp.i
.PHONY : src/Gameplay/Inventory.cpp.i

src/Gameplay/Inventory.s: src/Gameplay/Inventory.cpp.s

.PHONY : src/Gameplay/Inventory.s

# target to generate assembly for a file
src/Gameplay/Inventory.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Inventory.cpp.s
.PHONY : src/Gameplay/Inventory.cpp.s

src/Gameplay/ItemBag.o: src/Gameplay/ItemBag.cpp.o

.PHONY : src/Gameplay/ItemBag.o

# target to build an object file
src/Gameplay/ItemBag.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/ItemBag.cpp.o
.PHONY : src/Gameplay/ItemBag.cpp.o

src/Gameplay/ItemBag.i: src/Gameplay/ItemBag.cpp.i

.PHONY : src/Gameplay/ItemBag.i

# target to preprocess a source file
src/Gameplay/ItemBag.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/ItemBag.cpp.i
.PHONY : src/Gameplay/ItemBag.cpp.i

src/Gameplay/ItemBag.s: src/Gameplay/ItemBag.cpp.s

.PHONY : src/Gameplay/ItemBag.s

# target to generate assembly for a file
src/Gameplay/ItemBag.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/ItemBag.cpp.s
.PHONY : src/Gameplay/ItemBag.cpp.s

src/Gameplay/Level.o: src/Gameplay/Level.cpp.o

.PHONY : src/Gameplay/Level.o

# target to build an object file
src/Gameplay/Level.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Level.cpp.o
.PHONY : src/Gameplay/Level.cpp.o

src/Gameplay/Level.i: src/Gameplay/Level.cpp.i

.PHONY : src/Gameplay/Level.i

# target to preprocess a source file
src/Gameplay/Level.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Level.cpp.i
.PHONY : src/Gameplay/Level.cpp.i

src/Gameplay/Level.s: src/Gameplay/Level.cpp.s

.PHONY : src/Gameplay/Level.s

# target to generate assembly for a file
src/Gameplay/Level.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Level.cpp.s
.PHONY : src/Gameplay/Level.cpp.s

src/Gameplay/Lever.o: src/Gameplay/Lever.cpp.o

.PHONY : src/Gameplay/Lever.o

# target to build an object file
src/Gameplay/Lever.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Lever.cpp.o
.PHONY : src/Gameplay/Lever.cpp.o

src/Gameplay/Lever.i: src/Gameplay/Lever.cpp.i

.PHONY : src/Gameplay/Lever.i

# target to preprocess a source file
src/Gameplay/Lever.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Lever.cpp.i
.PHONY : src/Gameplay/Lever.cpp.i

src/Gameplay/Lever.s: src/Gameplay/Lever.cpp.s

.PHONY : src/Gameplay/Lever.s

# target to generate assembly for a file
src/Gameplay/Lever.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Lever.cpp.s
.PHONY : src/Gameplay/Lever.cpp.s

src/Gameplay/Living.o: src/Gameplay/Living.cpp.o

.PHONY : src/Gameplay/Living.o

# target to build an object file
src/Gameplay/Living.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Living.cpp.o
.PHONY : src/Gameplay/Living.cpp.o

src/Gameplay/Living.i: src/Gameplay/Living.cpp.i

.PHONY : src/Gameplay/Living.i

# target to preprocess a source file
src/Gameplay/Living.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Living.cpp.i
.PHONY : src/Gameplay/Living.cpp.i

src/Gameplay/Living.s: src/Gameplay/Living.cpp.s

.PHONY : src/Gameplay/Living.s

# target to generate assembly for a file
src/Gameplay/Living.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Living.cpp.s
.PHONY : src/Gameplay/Living.cpp.s

src/Gameplay/Map.o: src/Gameplay/Map.cpp.o

.PHONY : src/Gameplay/Map.o

# target to build an object file
src/Gameplay/Map.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Map.cpp.o
.PHONY : src/Gameplay/Map.cpp.o

src/Gameplay/Map.i: src/Gameplay/Map.cpp.i

.PHONY : src/Gameplay/Map.i

# target to preprocess a source file
src/Gameplay/Map.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Map.cpp.i
.PHONY : src/Gameplay/Map.cpp.i

src/Gameplay/Map.s: src/Gameplay/Map.cpp.s

.PHONY : src/Gameplay/Map.s

# target to generate assembly for a file
src/Gameplay/Map.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Map.cpp.s
.PHONY : src/Gameplay/Map.cpp.s

src/Gameplay/Missile.o: src/Gameplay/Missile.cpp.o

.PHONY : src/Gameplay/Missile.o

# target to build an object file
src/Gameplay/Missile.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Missile.cpp.o
.PHONY : src/Gameplay/Missile.cpp.o

src/Gameplay/Missile.i: src/Gameplay/Missile.cpp.i

.PHONY : src/Gameplay/Missile.i

# target to preprocess a source file
src/Gameplay/Missile.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Missile.cpp.i
.PHONY : src/Gameplay/Missile.cpp.i

src/Gameplay/Missile.s: src/Gameplay/Missile.cpp.s

.PHONY : src/Gameplay/Missile.s

# target to generate assembly for a file
src/Gameplay/Missile.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/Missile.cpp.s
.PHONY : src/Gameplay/Missile.cpp.s

src/Gameplay/PressPlate.o: src/Gameplay/PressPlate.cpp.o

.PHONY : src/Gameplay/PressPlate.o

# target to build an object file
src/Gameplay/PressPlate.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/PressPlate.cpp.o
.PHONY : src/Gameplay/PressPlate.cpp.o

src/Gameplay/PressPlate.i: src/Gameplay/PressPlate.cpp.i

.PHONY : src/Gameplay/PressPlate.i

# target to preprocess a source file
src/Gameplay/PressPlate.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/PressPlate.cpp.i
.PHONY : src/Gameplay/PressPlate.cpp.i

src/Gameplay/PressPlate.s: src/Gameplay/PressPlate.cpp.s

.PHONY : src/Gameplay/PressPlate.s

# target to generate assembly for a file
src/Gameplay/PressPlate.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/PressPlate.cpp.s
.PHONY : src/Gameplay/PressPlate.cpp.s

src/Gameplay/SpikeTrap.o: src/Gameplay/SpikeTrap.cpp.o

.PHONY : src/Gameplay/SpikeTrap.o

# target to build an object file
src/Gameplay/SpikeTrap.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/SpikeTrap.cpp.o
.PHONY : src/Gameplay/SpikeTrap.cpp.o

src/Gameplay/SpikeTrap.i: src/Gameplay/SpikeTrap.cpp.i

.PHONY : src/Gameplay/SpikeTrap.i

# target to preprocess a source file
src/Gameplay/SpikeTrap.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/SpikeTrap.cpp.i
.PHONY : src/Gameplay/SpikeTrap.cpp.i

src/Gameplay/SpikeTrap.s: src/Gameplay/SpikeTrap.cpp.s

.PHONY : src/Gameplay/SpikeTrap.s

# target to generate assembly for a file
src/Gameplay/SpikeTrap.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gameplay/SpikeTrap.cpp.s
.PHONY : src/Gameplay/SpikeTrap.cpp.s

src/Gui/GraphicInv.o: src/Gui/GraphicInv.cpp.o

.PHONY : src/Gui/GraphicInv.o

# target to build an object file
src/Gui/GraphicInv.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/GraphicInv.cpp.o
.PHONY : src/Gui/GraphicInv.cpp.o

src/Gui/GraphicInv.i: src/Gui/GraphicInv.cpp.i

.PHONY : src/Gui/GraphicInv.i

# target to preprocess a source file
src/Gui/GraphicInv.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/GraphicInv.cpp.i
.PHONY : src/Gui/GraphicInv.cpp.i

src/Gui/GraphicInv.s: src/Gui/GraphicInv.cpp.s

.PHONY : src/Gui/GraphicInv.s

# target to generate assembly for a file
src/Gui/GraphicInv.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/GraphicInv.cpp.s
.PHONY : src/Gui/GraphicInv.cpp.s

src/Gui/GraphicLoot.o: src/Gui/GraphicLoot.cpp.o

.PHONY : src/Gui/GraphicLoot.o

# target to build an object file
src/Gui/GraphicLoot.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/GraphicLoot.cpp.o
.PHONY : src/Gui/GraphicLoot.cpp.o

src/Gui/GraphicLoot.i: src/Gui/GraphicLoot.cpp.i

.PHONY : src/Gui/GraphicLoot.i

# target to preprocess a source file
src/Gui/GraphicLoot.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/GraphicLoot.cpp.i
.PHONY : src/Gui/GraphicLoot.cpp.i

src/Gui/GraphicLoot.s: src/Gui/GraphicLoot.cpp.s

.PHONY : src/Gui/GraphicLoot.s

# target to generate assembly for a file
src/Gui/GraphicLoot.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/GraphicLoot.cpp.s
.PHONY : src/Gui/GraphicLoot.cpp.s

src/Gui/Gui.o: src/Gui/Gui.cpp.o

.PHONY : src/Gui/Gui.o

# target to build an object file
src/Gui/Gui.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/Gui.cpp.o
.PHONY : src/Gui/Gui.cpp.o

src/Gui/Gui.i: src/Gui/Gui.cpp.i

.PHONY : src/Gui/Gui.i

# target to preprocess a source file
src/Gui/Gui.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/Gui.cpp.i
.PHONY : src/Gui/Gui.cpp.i

src/Gui/Gui.s: src/Gui/Gui.cpp.s

.PHONY : src/Gui/Gui.s

# target to generate assembly for a file
src/Gui/Gui.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/Gui.cpp.s
.PHONY : src/Gui/Gui.cpp.s

src/Gui/Slot.o: src/Gui/Slot.cpp.o

.PHONY : src/Gui/Slot.o

# target to build an object file
src/Gui/Slot.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/Slot.cpp.o
.PHONY : src/Gui/Slot.cpp.o

src/Gui/Slot.i: src/Gui/Slot.cpp.i

.PHONY : src/Gui/Slot.i

# target to preprocess a source file
src/Gui/Slot.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/Slot.cpp.i
.PHONY : src/Gui/Slot.cpp.i

src/Gui/Slot.s: src/Gui/Slot.cpp.s

.PHONY : src/Gui/Slot.s

# target to generate assembly for a file
src/Gui/Slot.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Gui/Slot.cpp.s
.PHONY : src/Gui/Slot.cpp.s

src/Input/InputHandler.o: src/Input/InputHandler.cpp.o

.PHONY : src/Input/InputHandler.o

# target to build an object file
src/Input/InputHandler.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Input/InputHandler.cpp.o
.PHONY : src/Input/InputHandler.cpp.o

src/Input/InputHandler.i: src/Input/InputHandler.cpp.i

.PHONY : src/Input/InputHandler.i

# target to preprocess a source file
src/Input/InputHandler.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Input/InputHandler.cpp.i
.PHONY : src/Input/InputHandler.cpp.i

src/Input/InputHandler.s: src/Input/InputHandler.cpp.s

.PHONY : src/Input/InputHandler.s

# target to generate assembly for a file
src/Input/InputHandler.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Input/InputHandler.cpp.s
.PHONY : src/Input/InputHandler.cpp.s

src/Render/AnimatedSprite.o: src/Render/AnimatedSprite.cpp.o

.PHONY : src/Render/AnimatedSprite.o

# target to build an object file
src/Render/AnimatedSprite.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/AnimatedSprite.cpp.o
.PHONY : src/Render/AnimatedSprite.cpp.o

src/Render/AnimatedSprite.i: src/Render/AnimatedSprite.cpp.i

.PHONY : src/Render/AnimatedSprite.i

# target to preprocess a source file
src/Render/AnimatedSprite.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/AnimatedSprite.cpp.i
.PHONY : src/Render/AnimatedSprite.cpp.i

src/Render/AnimatedSprite.s: src/Render/AnimatedSprite.cpp.s

.PHONY : src/Render/AnimatedSprite.s

# target to generate assembly for a file
src/Render/AnimatedSprite.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/AnimatedSprite.cpp.s
.PHONY : src/Render/AnimatedSprite.cpp.s

src/Render/Bar.o: src/Render/Bar.cpp.o

.PHONY : src/Render/Bar.o

# target to build an object file
src/Render/Bar.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Bar.cpp.o
.PHONY : src/Render/Bar.cpp.o

src/Render/Bar.i: src/Render/Bar.cpp.i

.PHONY : src/Render/Bar.i

# target to preprocess a source file
src/Render/Bar.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Bar.cpp.i
.PHONY : src/Render/Bar.cpp.i

src/Render/Bar.s: src/Render/Bar.cpp.s

.PHONY : src/Render/Bar.s

# target to generate assembly for a file
src/Render/Bar.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Bar.cpp.s
.PHONY : src/Render/Bar.cpp.s

src/Render/BigParticle.o: src/Render/BigParticle.cpp.o

.PHONY : src/Render/BigParticle.o

# target to build an object file
src/Render/BigParticle.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/BigParticle.cpp.o
.PHONY : src/Render/BigParticle.cpp.o

src/Render/BigParticle.i: src/Render/BigParticle.cpp.i

.PHONY : src/Render/BigParticle.i

# target to preprocess a source file
src/Render/BigParticle.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/BigParticle.cpp.i
.PHONY : src/Render/BigParticle.cpp.i

src/Render/BigParticle.s: src/Render/BigParticle.cpp.s

.PHONY : src/Render/BigParticle.s

# target to generate assembly for a file
src/Render/BigParticle.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/BigParticle.cpp.s
.PHONY : src/Render/BigParticle.cpp.s

src/Render/Indication.o: src/Render/Indication.cpp.o

.PHONY : src/Render/Indication.o

# target to build an object file
src/Render/Indication.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Indication.cpp.o
.PHONY : src/Render/Indication.cpp.o

src/Render/Indication.i: src/Render/Indication.cpp.i

.PHONY : src/Render/Indication.i

# target to preprocess a source file
src/Render/Indication.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Indication.cpp.i
.PHONY : src/Render/Indication.cpp.i

src/Render/Indication.s: src/Render/Indication.cpp.s

.PHONY : src/Render/Indication.s

# target to generate assembly for a file
src/Render/Indication.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Indication.cpp.s
.PHONY : src/Render/Indication.cpp.s

src/Render/IndicationHandler.o: src/Render/IndicationHandler.cpp.o

.PHONY : src/Render/IndicationHandler.o

# target to build an object file
src/Render/IndicationHandler.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/IndicationHandler.cpp.o
.PHONY : src/Render/IndicationHandler.cpp.o

src/Render/IndicationHandler.i: src/Render/IndicationHandler.cpp.i

.PHONY : src/Render/IndicationHandler.i

# target to preprocess a source file
src/Render/IndicationHandler.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/IndicationHandler.cpp.i
.PHONY : src/Render/IndicationHandler.cpp.i

src/Render/IndicationHandler.s: src/Render/IndicationHandler.cpp.s

.PHONY : src/Render/IndicationHandler.s

# target to generate assembly for a file
src/Render/IndicationHandler.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/IndicationHandler.cpp.s
.PHONY : src/Render/IndicationHandler.cpp.s

src/Render/Renderer.o: src/Render/Renderer.cpp.o

.PHONY : src/Render/Renderer.o

# target to build an object file
src/Render/Renderer.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Renderer.cpp.o
.PHONY : src/Render/Renderer.cpp.o

src/Render/Renderer.i: src/Render/Renderer.cpp.i

.PHONY : src/Render/Renderer.i

# target to preprocess a source file
src/Render/Renderer.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Renderer.cpp.i
.PHONY : src/Render/Renderer.cpp.i

src/Render/Renderer.s: src/Render/Renderer.cpp.s

.PHONY : src/Render/Renderer.s

# target to generate assembly for a file
src/Render/Renderer.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Renderer.cpp.s
.PHONY : src/Render/Renderer.cpp.s

src/Render/Sprite.o: src/Render/Sprite.cpp.o

.PHONY : src/Render/Sprite.o

# target to build an object file
src/Render/Sprite.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Sprite.cpp.o
.PHONY : src/Render/Sprite.cpp.o

src/Render/Sprite.i: src/Render/Sprite.cpp.i

.PHONY : src/Render/Sprite.i

# target to preprocess a source file
src/Render/Sprite.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Sprite.cpp.i
.PHONY : src/Render/Sprite.cpp.i

src/Render/Sprite.s: src/Render/Sprite.cpp.s

.PHONY : src/Render/Sprite.s

# target to generate assembly for a file
src/Render/Sprite.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Render/Sprite.cpp.s
.PHONY : src/Render/Sprite.cpp.s

src/Resource/Animation.o: src/Resource/Animation.cpp.o

.PHONY : src/Resource/Animation.o

# target to build an object file
src/Resource/Animation.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/Animation.cpp.o
.PHONY : src/Resource/Animation.cpp.o

src/Resource/Animation.i: src/Resource/Animation.cpp.i

.PHONY : src/Resource/Animation.i

# target to preprocess a source file
src/Resource/Animation.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/Animation.cpp.i
.PHONY : src/Resource/Animation.cpp.i

src/Resource/Animation.s: src/Resource/Animation.cpp.s

.PHONY : src/Resource/Animation.s

# target to generate assembly for a file
src/Resource/Animation.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/Animation.cpp.s
.PHONY : src/Resource/Animation.cpp.s

src/Resource/AnimationCache.o: src/Resource/AnimationCache.cpp.o

.PHONY : src/Resource/AnimationCache.o

# target to build an object file
src/Resource/AnimationCache.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/AnimationCache.cpp.o
.PHONY : src/Resource/AnimationCache.cpp.o

src/Resource/AnimationCache.i: src/Resource/AnimationCache.cpp.i

.PHONY : src/Resource/AnimationCache.i

# target to preprocess a source file
src/Resource/AnimationCache.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/AnimationCache.cpp.i
.PHONY : src/Resource/AnimationCache.cpp.i

src/Resource/AnimationCache.s: src/Resource/AnimationCache.cpp.s

.PHONY : src/Resource/AnimationCache.s

# target to generate assembly for a file
src/Resource/AnimationCache.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/AnimationCache.cpp.s
.PHONY : src/Resource/AnimationCache.cpp.s

src/Resource/FontCache.o: src/Resource/FontCache.cpp.o

.PHONY : src/Resource/FontCache.o

# target to build an object file
src/Resource/FontCache.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/FontCache.cpp.o
.PHONY : src/Resource/FontCache.cpp.o

src/Resource/FontCache.i: src/Resource/FontCache.cpp.i

.PHONY : src/Resource/FontCache.i

# target to preprocess a source file
src/Resource/FontCache.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/FontCache.cpp.i
.PHONY : src/Resource/FontCache.cpp.i

src/Resource/FontCache.s: src/Resource/FontCache.cpp.s

.PHONY : src/Resource/FontCache.s

# target to generate assembly for a file
src/Resource/FontCache.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/FontCache.cpp.s
.PHONY : src/Resource/FontCache.cpp.s

src/Resource/TextureCache.o: src/Resource/TextureCache.cpp.o

.PHONY : src/Resource/TextureCache.o

# target to build an object file
src/Resource/TextureCache.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/TextureCache.cpp.o
.PHONY : src/Resource/TextureCache.cpp.o

src/Resource/TextureCache.i: src/Resource/TextureCache.cpp.i

.PHONY : src/Resource/TextureCache.i

# target to preprocess a source file
src/Resource/TextureCache.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/TextureCache.cpp.i
.PHONY : src/Resource/TextureCache.cpp.i

src/Resource/TextureCache.s: src/Resource/TextureCache.cpp.s

.PHONY : src/Resource/TextureCache.s

# target to generate assembly for a file
src/Resource/TextureCache.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Resource/TextureCache.cpp.s
.PHONY : src/Resource/TextureCache.cpp.s

src/Script/LuaInterface.o: src/Script/LuaInterface.cpp.o

.PHONY : src/Script/LuaInterface.o

# target to build an object file
src/Script/LuaInterface.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Script/LuaInterface.cpp.o
.PHONY : src/Script/LuaInterface.cpp.o

src/Script/LuaInterface.i: src/Script/LuaInterface.cpp.i

.PHONY : src/Script/LuaInterface.i

# target to preprocess a source file
src/Script/LuaInterface.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Script/LuaInterface.cpp.i
.PHONY : src/Script/LuaInterface.cpp.i

src/Script/LuaInterface.s: src/Script/LuaInterface.cpp.s

.PHONY : src/Script/LuaInterface.s

# target to generate assembly for a file
src/Script/LuaInterface.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Script/LuaInterface.cpp.s
.PHONY : src/Script/LuaInterface.cpp.s

src/Script/ScriptHandler.o: src/Script/ScriptHandler.cpp.o

.PHONY : src/Script/ScriptHandler.o

# target to build an object file
src/Script/ScriptHandler.cpp.o:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Script/ScriptHandler.cpp.o
.PHONY : src/Script/ScriptHandler.cpp.o

src/Script/ScriptHandler.i: src/Script/ScriptHandler.cpp.i

.PHONY : src/Script/ScriptHandler.i

# target to preprocess a source file
src/Script/ScriptHandler.cpp.i:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Script/ScriptHandler.cpp.i
.PHONY : src/Script/ScriptHandler.cpp.i

src/Script/ScriptHandler.s: src/Script/ScriptHandler.cpp.s

.PHONY : src/Script/ScriptHandler.s

# target to generate assembly for a file
src/Script/ScriptHandler.cpp.s:
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/src/Script/ScriptHandler.cpp.s
.PHONY : src/Script/ScriptHandler.cpp.s

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

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... out"
	@echo "... src/Ai/Ai.o"
	@echo "... src/Ai/Ai.i"
	@echo "... src/Ai/Ai.s"
	@echo "... src/Ai/AiMob.o"
	@echo "... src/Ai/AiMob.i"
	@echo "... src/Ai/AiMob.s"
	@echo "... src/Ai/AiPlayer.o"
	@echo "... src/Ai/AiPlayer.i"
	@echo "... src/Ai/AiPlayer.s"
	@echo "... src/Collision/CollisionHandler.o"
	@echo "... src/Collision/CollisionHandler.i"
	@echo "... src/Collision/CollisionHandler.s"
	@echo "... src/Core/Game.o"
	@echo "... src/Core/Game.i"
	@echo "... src/Core/Game.s"
	@echo "... src/Gameplay/Chest.o"
	@echo "... src/Gameplay/Chest.i"
	@echo "... src/Gameplay/Chest.s"
	@echo "... src/Gameplay/Door.o"
	@echo "... src/Gameplay/Door.i"
	@echo "... src/Gameplay/Door.s"
	@echo "... src/Gameplay/Entity.o"
	@echo "... src/Gameplay/Entity.i"
	@echo "... src/Gameplay/Entity.s"
	@echo "... src/Gameplay/Inventory.o"
	@echo "... src/Gameplay/Inventory.i"
	@echo "... src/Gameplay/Inventory.s"
	@echo "... src/Gameplay/ItemBag.o"
	@echo "... src/Gameplay/ItemBag.i"
	@echo "... src/Gameplay/ItemBag.s"
	@echo "... src/Gameplay/Level.o"
	@echo "... src/Gameplay/Level.i"
	@echo "... src/Gameplay/Level.s"
	@echo "... src/Gameplay/Lever.o"
	@echo "... src/Gameplay/Lever.i"
	@echo "... src/Gameplay/Lever.s"
	@echo "... src/Gameplay/Living.o"
	@echo "... src/Gameplay/Living.i"
	@echo "... src/Gameplay/Living.s"
	@echo "... src/Gameplay/Map.o"
	@echo "... src/Gameplay/Map.i"
	@echo "... src/Gameplay/Map.s"
	@echo "... src/Gameplay/Missile.o"
	@echo "... src/Gameplay/Missile.i"
	@echo "... src/Gameplay/Missile.s"
	@echo "... src/Gameplay/PressPlate.o"
	@echo "... src/Gameplay/PressPlate.i"
	@echo "... src/Gameplay/PressPlate.s"
	@echo "... src/Gameplay/SpikeTrap.o"
	@echo "... src/Gameplay/SpikeTrap.i"
	@echo "... src/Gameplay/SpikeTrap.s"
	@echo "... src/Gui/GraphicInv.o"
	@echo "... src/Gui/GraphicInv.i"
	@echo "... src/Gui/GraphicInv.s"
	@echo "... src/Gui/GraphicLoot.o"
	@echo "... src/Gui/GraphicLoot.i"
	@echo "... src/Gui/GraphicLoot.s"
	@echo "... src/Gui/Gui.o"
	@echo "... src/Gui/Gui.i"
	@echo "... src/Gui/Gui.s"
	@echo "... src/Gui/Slot.o"
	@echo "... src/Gui/Slot.i"
	@echo "... src/Gui/Slot.s"
	@echo "... src/Input/InputHandler.o"
	@echo "... src/Input/InputHandler.i"
	@echo "... src/Input/InputHandler.s"
	@echo "... src/Render/AnimatedSprite.o"
	@echo "... src/Render/AnimatedSprite.i"
	@echo "... src/Render/AnimatedSprite.s"
	@echo "... src/Render/Bar.o"
	@echo "... src/Render/Bar.i"
	@echo "... src/Render/Bar.s"
	@echo "... src/Render/BigParticle.o"
	@echo "... src/Render/BigParticle.i"
	@echo "... src/Render/BigParticle.s"
	@echo "... src/Render/Indication.o"
	@echo "... src/Render/Indication.i"
	@echo "... src/Render/Indication.s"
	@echo "... src/Render/IndicationHandler.o"
	@echo "... src/Render/IndicationHandler.i"
	@echo "... src/Render/IndicationHandler.s"
	@echo "... src/Render/Renderer.o"
	@echo "... src/Render/Renderer.i"
	@echo "... src/Render/Renderer.s"
	@echo "... src/Render/Sprite.o"
	@echo "... src/Render/Sprite.i"
	@echo "... src/Render/Sprite.s"
	@echo "... src/Resource/Animation.o"
	@echo "... src/Resource/Animation.i"
	@echo "... src/Resource/Animation.s"
	@echo "... src/Resource/AnimationCache.o"
	@echo "... src/Resource/AnimationCache.i"
	@echo "... src/Resource/AnimationCache.s"
	@echo "... src/Resource/FontCache.o"
	@echo "... src/Resource/FontCache.i"
	@echo "... src/Resource/FontCache.s"
	@echo "... src/Resource/TextureCache.o"
	@echo "... src/Resource/TextureCache.i"
	@echo "... src/Resource/TextureCache.s"
	@echo "... src/Script/LuaInterface.o"
	@echo "... src/Script/LuaInterface.i"
	@echo "... src/Script/LuaInterface.s"
	@echo "... src/Script/ScriptHandler.o"
	@echo "... src/Script/ScriptHandler.i"
	@echo "... src/Script/ScriptHandler.s"
	@echo "... src/base64/base64.o"
	@echo "... src/base64/base64.i"
	@echo "... src/base64/base64.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

