cmake_minimum_required (VERSION 2.6)
project (ArgumentManager)
set (ProjectName ArgumentManager)

add_library(${ProjectName} STATIC
  src/CArgumentManager.cpp
	)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/modules/")

install(FILES
  src/CArgumentManager.hpp
	DESTINATION include/${ProjectName}
	)

install(TARGETS ${ProjectName}
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	)
