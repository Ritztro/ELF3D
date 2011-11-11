#*******************************************************************
# This file is part of the CMake build system for ELF3D
# For the latest info, see https://github.com/Ritztro/ELF3D
#*******************************************************************
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)

SET(SOURCE 
	${SRC_ROOT}/Utilities/List.cpp
	${INC_ROOT}/Utilities/List.hpp
	${SRC_ROOT}/Utilities/ListElement.cpp
	${INC_ROOT}/Utilities/ListElement.hpp
	${INC_ROOT}/Utilities/BuildSettings.hpp
)

ADD_LIBRARY(ELF3D ${SOURCE})

#FILE(GLOB util "${INC_ROOT}/Utilities/*.hpp")

#INSTALL(TARGETS ELF3D DESTINATION bin)
#INSTALL(FILES util DESTINATION include/ELF3D/Utilities)
