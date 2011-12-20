#*******************************************************************
# This file is part of the CMake build system for ELF3D
# For the latest info, see https://github.com/Ritztro/ELF3D
#*******************************************************************
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)

SET(UTIL_SOURCE
	${SRC_ROOT}/Utilities/List.cpp
	${INC_ROOT}/Utilities/List.hpp
	${SRC_ROOT}/Utilities/ListElement.cpp
	${INC_ROOT}/Utilities/ListElement.hpp
	${SRC_ROOT}/Utilities/File.cpp
	${INC_ROOT}/Utilities/File.hpp
	${SRC_ROOT}/Utilities/String.cpp
	${INC_ROOT}/Utilities/String.hpp
)

SET(SYS_SOURCE 
	${INC_ROOT}/System/BuildSettings.hpp
	${INC_ROOT}/System/Prerequisites.hpp
)

SET(GRAPH_SOURCE
	${INC_ROOT}/Graphics/OpenGL.h
)

SET(PHYS_SOURCE
)

# Creates sub folder for the project, also called filters in Visual Studio
SOURCE_GROUP("Utilities" FILES ${UTIL_SOURCE})
SOURCE_GROUP("System" FILES ${SYS_SOURCE})
SOURCE_GROUP("Graphics" FILES ${GRAPH_SOURCE})
SOURCE_GROUP("Physics" FILES ${PHYS_SOURCE})
SOURCE_GROUP("" FILES ${INC_ROOT}/ELF3D.hpp)

ADD_LIBRARY(ELF3D ${UTIL_SOURCE} ${SYS_SOURCE} ${GRAPH_SOURCE} ${PHYS_SOURCE} ${INC_ROOT}/ELF3D.hpp)
