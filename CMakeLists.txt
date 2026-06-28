cmake_minimum_required(VERSION 3.25)

project(
    GeoCore
    VERSION 0.1.0
    DESCRIPTION "Making geofencing simple."
    LANGUAGES CXX
)

include(FetchContent)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Build options
#

option(GEOCORE_BUILD_DEMO "Build GeoCore demo" ON)
option(GEOCORE_BUILD_TESTS "Build GeoCore tests" ON)

#
# Engine
#

add_subdirectory(Engine)

#
# Demo
#

if(GEOCORE_BUILD_DEMO)
    add_subdirectory(Demo)
endif()

#
# Tests
#

if(GEOCORE_BUILD_TESTS)

    enable_testing()

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
    )

    FetchContent_MakeAvailable(Catch2)

    add_subdirectory(Tests)

endif()