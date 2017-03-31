cmake_minimum_required(VERSION 3.6)
project(scheduler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        scheduler.cpp MaxDatarateSorter.cpp MaxDatarateSorter.hpp)

include_directories(./)
include_directories(/usr/include)

add_custom_target(scheduler COMMAND $(MAKE) -C ${scheduler_SOURCE_DIR} CLION_EXE_DIR=${PROJECT_BINARY_DIR})
add_executable(dontuse ${SOURCE_FILES} ${HEADER_FILES})