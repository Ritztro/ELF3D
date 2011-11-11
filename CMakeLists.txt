#*******************************************************************
# This file is part of the CMake build system for ELF3D
#     (Elegant, Lightweight and Fast)
# For the latest info, see https://github.com/Ritztro/ELF3D
#*******************************************************************
CMAKE_MINIMUM_REQUIRED (VERSION 2.8.4)
PROJECT(ELF3D)
SET (ELF3D_VERSION_MAJOR 1)
SET (ELF3D_VERSION_MINOR 0)

# Set build type if not set.
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF()

# Add ELF3D header path
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)
SET(SRC_ROOT ${CMAKE_SOURCE_DIR}/src/ELF3D)
SET(INC_ROOT ${CMAKE_SOURCE_DIR}/include/ELF3D)

# Build the project as shared lib or not. This is not supported yet!
#OPTION(BUILD_SHARED_LIBS "TRUE if ELF3D should be build as shared lib and false if static lib." OFF)
#OPTION(BUILD_DOC "TRUE if the ELF3D API documentation should be build." OFF)

CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/include/ELF3D/Utilities/BuildSettings.hpp.cmake ${CMAKE_SOURCE_DIR}/include/ELF3D/Utilities/BuildSettings.hpp)

# Build doc if user want
IF(BUILD_DOC)
	# This is not supported yet!
	#ADD_SUBDIRECTORY(doc)
ENDIF()

ADD_SUBDIRECTORY(src/ELF3D)