CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
# Set the name and the supported language of the project
PROJECT(MiniCypher C)
# Set the minimum version of cmake required to build this project

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS} include)
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# Add an executable compiled from MiniCypher.c
file(GLOB SOURCE_FILES src/*.c)

ADD_EXECUTABLE(MiniCypher ${SOURCE_FILES})

# Link the target to the GTK+ libraries and the math library
TARGET_LINK_LIBRARIES(MiniCypher ${GTK3_LIBRARIES} m)

# copy glade data to build
add_custom_target(glade ALL
	COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/glade ${CMAKE_BINARY_DIR}/glade
	DEPENDS ${MY_TARGET}
)
