# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /private/var/folders/zz/zyxvpxvq6csfxvn_n00014jr00094f/T/AppTranslocation/D0383483-66D8-4EB4-A591-99F97EB6CD52/d/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /private/var/folders/zz/zyxvpxvq6csfxvn_n00014jr00094f/T/AppTranslocation/D0383483-66D8-4EB4-A591-99F97EB6CD52/d/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/smight/Desktop/ft_ls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/smight/Desktop/ft_ls/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ft_ls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ft_ls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ft_ls.dir/flags.make

CMakeFiles/ft_ls.dir/src/main.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/smight/Desktop/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ft_ls.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/src/main.c.o   -c /Users/smight/Desktop/ft_ls/src/main.c

CMakeFiles/ft_ls.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/smight/Desktop/ft_ls/src/main.c > CMakeFiles/ft_ls.dir/src/main.c.i

CMakeFiles/ft_ls.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/smight/Desktop/ft_ls/src/main.c -o CMakeFiles/ft_ls.dir/src/main.c.s

CMakeFiles/ft_ls.dir/src/handle_error.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/src/handle_error.c.o: ../src/handle_error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/smight/Desktop/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ft_ls.dir/src/handle_error.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/src/handle_error.c.o   -c /Users/smight/Desktop/ft_ls/src/handle_error.c

CMakeFiles/ft_ls.dir/src/handle_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/src/handle_error.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/smight/Desktop/ft_ls/src/handle_error.c > CMakeFiles/ft_ls.dir/src/handle_error.c.i

CMakeFiles/ft_ls.dir/src/handle_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/src/handle_error.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/smight/Desktop/ft_ls/src/handle_error.c -o CMakeFiles/ft_ls.dir/src/handle_error.c.s

CMakeFiles/ft_ls.dir/src/files.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/src/files.c.o: ../src/files.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/smight/Desktop/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ft_ls.dir/src/files.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/src/files.c.o   -c /Users/smight/Desktop/ft_ls/src/files.c

CMakeFiles/ft_ls.dir/src/files.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/src/files.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/smight/Desktop/ft_ls/src/files.c > CMakeFiles/ft_ls.dir/src/files.c.i

CMakeFiles/ft_ls.dir/src/files.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/src/files.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/smight/Desktop/ft_ls/src/files.c -o CMakeFiles/ft_ls.dir/src/files.c.s

CMakeFiles/ft_ls.dir/src/print_files.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/src/print_files.c.o: ../src/print_files.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/smight/Desktop/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ft_ls.dir/src/print_files.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/src/print_files.c.o   -c /Users/smight/Desktop/ft_ls/src/print_files.c

CMakeFiles/ft_ls.dir/src/print_files.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/src/print_files.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/smight/Desktop/ft_ls/src/print_files.c > CMakeFiles/ft_ls.dir/src/print_files.c.i

CMakeFiles/ft_ls.dir/src/print_files.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/src/print_files.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/smight/Desktop/ft_ls/src/print_files.c -o CMakeFiles/ft_ls.dir/src/print_files.c.s

# Object files for target ft_ls
ft_ls_OBJECTS = \
"CMakeFiles/ft_ls.dir/src/main.c.o" \
"CMakeFiles/ft_ls.dir/src/handle_error.c.o" \
"CMakeFiles/ft_ls.dir/src/files.c.o" \
"CMakeFiles/ft_ls.dir/src/print_files.c.o"

# External object files for target ft_ls
ft_ls_EXTERNAL_OBJECTS =

ft_ls: CMakeFiles/ft_ls.dir/src/main.c.o
ft_ls: CMakeFiles/ft_ls.dir/src/handle_error.c.o
ft_ls: CMakeFiles/ft_ls.dir/src/files.c.o
ft_ls: CMakeFiles/ft_ls.dir/src/print_files.c.o
ft_ls: CMakeFiles/ft_ls.dir/build.make
ft_ls: ../libft/libft.a
ft_ls: ../libft/libftprintf.a
ft_ls: CMakeFiles/ft_ls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/smight/Desktop/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ft_ls"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ft_ls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ft_ls.dir/build: ft_ls

.PHONY : CMakeFiles/ft_ls.dir/build

CMakeFiles/ft_ls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ft_ls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ft_ls.dir/clean

CMakeFiles/ft_ls.dir/depend:
	cd /Users/smight/Desktop/ft_ls/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/smight/Desktop/ft_ls /Users/smight/Desktop/ft_ls /Users/smight/Desktop/ft_ls/cmake-build-debug /Users/smight/Desktop/ft_ls/cmake-build-debug /Users/smight/Desktop/ft_ls/cmake-build-debug/CMakeFiles/ft_ls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ft_ls.dir/depend
