cmake_minimum_required(VERSION 3.3)
project(MameUIsen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCE_FILES src/main.cpp src/RomManagement/Rom.h src/RomManagement/RomList.h src/RomManagement/RomListManager.cpp src/RomManagement/RomListManager.h src/Configuration/Configuration.cpp src/Configuration/Configuration.h src/lib/EasyConfigurationFileReadingApi/ConfigDirectiveToFunction.h src/MameUIsenWindow.cpp src/MameUIsenWindow.h src/lib/EasyConfigurationFileReadingApi/AbstactConfiguration.h src/Configuration/Theme.cpp src/Configuration/Theme.h src/lib/EasyConfigurationFileReadingApi/ConfigDirectiveToFunctionBase.h src/lib/EasyConfigurationFileReadingApi/ConfigDirectiveToFunctionBase.cpp src/lib/EasyConfigurationFileReadingApi/AbstactConfiguration.tpp src/lib/EasyConfigurationFileReadingApi/ConfigDirectiveToFunction.tpp)
add_executable(MameUIsen ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(MameUIsen ${SFML_LIBRARIES})
endif()
