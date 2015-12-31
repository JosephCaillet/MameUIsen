cmake_minimum_required(VERSION 3.3)
project(MameUIsen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCE_FILES src/main.cpp src/Rom.h src/RomList.h src/RomListManager.cpp src/RomListManager.h src/Configuration.cpp src/Configuration.h src/ConfigDirectiveToFunction.h src/MameUIsenWindow.cpp src/MameUIsenWindow.h src/AbstactConfiguration.h src/Theme.cpp src/Theme.h src/ConfigDirectiveToFunctionBase.h src/ConfigDirectiveToFunctionBase.cpp src/AbstactConfiguration.tpp src/ConfigDirectiveToFunction.tpp)
add_executable(MameUIsen ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(MameUIsen ${SFML_LIBRARIES})
endif()
