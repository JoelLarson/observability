cmake_minimum_required(VERSION 4.0)

project(observability LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(core_lib
        src/LogEntry.cpp
        src/LogEntry.h
)
target_sources(core_lib PRIVATE src/LogStorage.cpp)
target_include_directories(core_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Catch2 3 REQUIRED)
add_executable(tests
        tests/LogStorageTest.cpp
        tests/LogEntryTest.cpp
)
target_link_libraries(tests PRIVATE core_lib Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)

add_executable(observability src/main.cpp)
target_link_libraries(observability PRIVATE core_lib)