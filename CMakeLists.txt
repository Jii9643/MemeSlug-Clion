cmake_minimum_required(VERSION 3.10)
project(MemeSlug)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Test)

set(SOURCE_FILES Game.cpp Game.h Player.cpp Player.h Bullet.cpp Bullet.h Achievement.cpp Achievement.h Enemy.cpp Enemy.h Platform.cpp Platform.h
        Pickup.cpp Pickup.h StrategyL.h StrategyMove.h StrategyR.h Subject.h DisplayElement.h dArr.h Observer.h Main.cpp)

add_executable(MemeSlug ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries( MemeSlug core)

set(EXECUTABLE_NAME ${PROJECT_NAME})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()