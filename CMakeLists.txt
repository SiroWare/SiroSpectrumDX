# CMake entry point
cmake_minimum_required (VERSION 3.12)
project (SiroSpectrumDX)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")
	# -Wall -Werror -pedantic 
	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

add_definitions( # g++ -Dxxx
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-D_CRT_SECURE_NO_WARNINGS
)

# Compile external dependencies
add_subdirectory (external)

include_directories( # g++ -Ipath/to/headerfiles
	external/glfw-3.3.8/include/
	external/glad-3.3/include/
	.
)

link_directories( # g++ -Lpath/to/library
)

set(ALL_GRAPHICS_LIBS
	glfw
	SiroSpectrumDX
)

# SiroSpectrumDX (libSiroSpectrumDX.a)
add_library(SiroSpectrumDX # ar rcs libSiroSpectrumDX.a
	external/glad-3.3/src/glad.c
	SiroSpectrumDX/Internal/renderer.cpp
	SiroSpectrumDX/Internal/renderer.h
	SiroSpectrumDX/core.cpp
	SiroSpectrumDX/core.h
	SiroSpectrumDX/game.cpp
	SiroSpectrumDX/game.h
	SiroSpectrumDX/sprite.cpp
	SiroSpectrumDX/sprite.h
	SiroSpectrumDX/input.cpp
	SiroSpectrumDX/input.h
	SiroSpectrumDX/pencil.cpp
	SiroSpectrumDX/pencil.h
	SiroSpectrumDX/vector.h
)

# Frogger
add_executable(Frogger # g++ Frogger/main.cpp -o Frogger
	Frogger/main.cpp
)
target_link_libraries(Frogger # g++ -lSiroSpectrumDX
	${ALL_GRAPHICS_LIBS}
)
	target_link_libraries(Frogger
		${ALL_GRAPHICS_LIBS}
	)