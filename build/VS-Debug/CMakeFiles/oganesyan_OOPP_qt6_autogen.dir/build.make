# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles JOM" Generator, CMake Version 3.29

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
CMAKE_COMMAND = C:\QT\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = C:\QT\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\egiaz\Documents\GitHub\Oganesyan_OOPP_qt6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\egiaz\Documents\GitHub\Oganesyan_OOPP_qt6\build\VS-debug

# Utility rule file for oganesyan_OOPP_qt6_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\progress.make

CMakeFiles\oganesyan_OOPP_qt6_autogen: oganesyan_OOPP_qt6_autogen\timestamp

oganesyan_OOPP_qt6_autogen\timestamp: C:\QT\6.8.0\msvc2022_64\bin\moc.exe
oganesyan_OOPP_qt6_autogen\timestamp: C:\QT\6.8.0\msvc2022_64\bin\uic.exe
oganesyan_OOPP_qt6_autogen\timestamp: CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\egiaz\Documents\GitHub\Oganesyan_OOPP_qt6\build\VS-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target oganesyan_OOPP_qt6"
	C:\QT\Tools\CMake_64\bin\cmake.exe -E cmake_autogen C:/Users/egiaz/Documents/GitHub/Oganesyan_OOPP_qt6/build/VS-debug/CMakeFiles/oganesyan_OOPP_qt6_autogen.dir/AutogenInfo.json Debug
	C:\QT\Tools\CMake_64\bin\cmake.exe -E touch C:/Users/egiaz/Documents/GitHub/Oganesyan_OOPP_qt6/build/VS-debug/oganesyan_OOPP_qt6_autogen/timestamp

oganesyan_OOPP_qt6_autogen: CMakeFiles\oganesyan_OOPP_qt6_autogen
oganesyan_OOPP_qt6_autogen: oganesyan_OOPP_qt6_autogen\timestamp
oganesyan_OOPP_qt6_autogen: CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\build.make
.PHONY : oganesyan_OOPP_qt6_autogen

# Rule to build all files generated by this target.
CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\build: oganesyan_OOPP_qt6_autogen
.PHONY : CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\build

CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\clean

CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles JOM" C:\Users\egiaz\Documents\GitHub\Oganesyan_OOPP_qt6 C:\Users\egiaz\Documents\GitHub\Oganesyan_OOPP_qt6 C:\Users\egiaz\Documents\GitHub\Oganesyan_OOPP_qt6\build\VS-debug C:\Users\egiaz\Documents\GitHub\Oganesyan_OOPP_qt6\build\VS-debug C:\Users\egiaz\Documents\GitHub\Oganesyan_OOPP_qt6\build\VS-debug\CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles\oganesyan_OOPP_qt6_autogen.dir\depend

