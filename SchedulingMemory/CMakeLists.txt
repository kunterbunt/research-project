cmake_minimum_required(VERSION 3.6)
project(SchedulingMemory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cc SchedulingMemory.cc SchedulingMemory.hpp SchedulingMemoryTest.cc)

include_directories(./)
include_directories(/usr/include)

#add_executable(SchedulingMemory ${SOURCE_FILES})
add_custom_target(SchedulingMemory COMMAND $(MAKE) -C ${SchedulingMemory_SOURCE_DIR} CLION_EXE_DIR=${PROJECT_BINARY_DIR})
add_executable(dontuse ${SOURCE_FILES} ${HEADER_FILES})