cmake_minimum_required(VERSION 3.0)

project(raycaster)

# Libraries
find_package(SDL2 REQUIRED)
Message("")
Message( STATUS "FINDING SDL2" )
IF (${SDL2_FOUND})
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
ELSE()
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( FATAL_ERROR "SDL2 NOT FOUND" )
ENDIF()


# Source files
set (PROJECT_HEADERS
    src/headers/player.hpp
    src/headers/entity.hpp
    src/headers/map.hpp
    src/headers/game.hpp
    )
set (PROJECT_SRC
    src/player.cpp
    src/entity.cpp
    src/map.cpp
    src/game.cpp
    src/main.cpp
    )

include_directories(${SDL2_INCLUDE_DIRS} ${PROJECT_HEADERS} ${PROJECT_SRC}})

# Create executable and link libraries
add_executable(raycaster ${PROJECT_SRC})

target_link_libraries(raycaster ${SDL2_LIBRARIES})
