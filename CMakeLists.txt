### Generic native Skirmish AI config
#

set(mySourceDirRel         "src") # Common values are "" or "src"
set(additionalSources      "")
set(additionalCompileFlags "-Ierl_interface/include")
set(additionalLibraries    ${Cpp_AIWRAPPER_TARGET} CUtils "-L${CMAKE_SOURCE_DIR}/AI/Skirmish/NullErlangAI/erl_interface/lib" "erl_interface" "ei" "nsl")


if    (BUILD_Cpp_AIWRAPPER)
	include_directories(BEFORE ${CMAKE_BINARY_DIR}) # for src-generated wrapper files
	include_directories(BEFORE ${CMAKE_SOURCE_DIR})
	include_directories(BEFORE ${Cpp_AIWRAPPER_INCLUDE_DIRS})
	if(NOT WIN32)
		add_definitions(-DLUA_USE_POSIX)
	endif()
	ConfigureNativeSkirmishAI(mySourceDirRel additionalSources additionalCompileFlags additionalLibraries)
else  (BUILD_Cpp_AIWRAPPER)
    message ("warning: NullErlangAI will not be built! (missing Cpp Wrapper)")
endif (BUILD_Cpp_AIWRAPPER)
