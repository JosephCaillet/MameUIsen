cmake_minimum_required(VERSION 3.3)
project(MameUIsen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCE_FILES src/main.cpp src/Rom.h src/RomList.h src/RomSetManager.cpp src/RomSetManager.h)
add_executable(MameUIsen ${SOURCE_FILES})