cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES Test.cpp TestPlayer.cpp TestEnemy.cpp TestPlatform.cpp)
add_executable(runAllTest ${SOURCE_FILES})
target_link_libraries(runAllTest ${GTEST_BOTH_LIBRARIES} core pthread)

set(CMAKE_MODULE_PATH "/home/jii/CLionProjects/MemeSlug/Test/cmakemod" ${CMAKE_MODULE_PATH}})
find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(runAllTest ${SFML_LIBRARIES})
endif()