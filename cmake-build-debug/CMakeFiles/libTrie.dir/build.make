# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kruch\CLionProjects\Trie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kruch\CLionProjects\Trie\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\libTrie.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\libTrie.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\libTrie.dir\flags.make

CMakeFiles\libTrie.dir\Trie.c.obj: CMakeFiles\libTrie.dir\flags.make
CMakeFiles\libTrie.dir\Trie.c.obj: ..\Trie.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kruch\CLionProjects\Trie\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/libTrie.dir/Trie.c.obj"
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\libTrie.dir\Trie.c.obj /FdCMakeFiles\libTrie.dir\libTrie.pdb /FS -c C:\Users\kruch\CLionProjects\Trie\Trie.c
<<

CMakeFiles\libTrie.dir\Trie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libTrie.dir/Trie.c.i"
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx86\x86\cl.exe > CMakeFiles\libTrie.dir\Trie.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\kruch\CLionProjects\Trie\Trie.c
<<

CMakeFiles\libTrie.dir\Trie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libTrie.dir/Trie.c.s"
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\libTrie.dir\Trie.c.s /c C:\Users\kruch\CLionProjects\Trie\Trie.c
<<

# Object files for target libTrie
libTrie_OBJECTS = \
"CMakeFiles\libTrie.dir\Trie.c.obj"

# External object files for target libTrie
libTrie_EXTERNAL_OBJECTS =

libTrie.lib: CMakeFiles\libTrie.dir\Trie.c.obj
libTrie.lib: CMakeFiles\libTrie.dir\build.make
libTrie.lib: CMakeFiles\libTrie.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kruch\CLionProjects\Trie\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libTrie.lib"
	$(CMAKE_COMMAND) -P CMakeFiles\libTrie.dir\cmake_clean_target.cmake
	C:\PROGRA~1\MIB055~1\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx86\x86\lib.exe /nologo /machine:X86 /out:libTrie.lib @CMakeFiles\libTrie.dir\objects1.rsp 

# Rule to build all files generated by this target.
CMakeFiles\libTrie.dir\build: libTrie.lib
.PHONY : CMakeFiles\libTrie.dir\build

CMakeFiles\libTrie.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\libTrie.dir\cmake_clean.cmake
.PHONY : CMakeFiles\libTrie.dir\clean

CMakeFiles\libTrie.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\kruch\CLionProjects\Trie C:\Users\kruch\CLionProjects\Trie C:\Users\kruch\CLionProjects\Trie\cmake-build-debug C:\Users\kruch\CLionProjects\Trie\cmake-build-debug C:\Users\kruch\CLionProjects\Trie\cmake-build-debug\CMakeFiles\libTrie.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\libTrie.dir\depend

