cmake_minimum_required(VERSION 3.10)
project(Project)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# BUSINESS LOGIC
set(LOGIC_SOURCES classes/math.cpp)
add_library(businessLogic ${LOGIC_SOURCES})

# PROGRAM
set(SOURCES main.cpp)
add_executable(program ${SOURCES})

target_include_directories(program PUBLIC include)

file(GLOB SFML_LIBS ${CMAKE_SOURCE_DIR}/lib/sfml/*)
target_link_libraries(program ${SFML_LIBS})
target_link_libraries(program businessLogic)

# TESTS
set(TEST_SOURCES tests/main.cpp tests/math.cpp)
add_executable(tests ${TEST_SOURCES})

target_include_directories(tests PUBLIC include)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR})

set(GTEST_LIBS ${CMAKE_SOURCE_DIR}/lib/gtest/libgtest.a)
target_link_libraries(tests ${SFML_LIBS} ${GTEST_LIBS})
target_link_libraries(tests businessLogic)

add_custom_target(NAME run_tests COMMAND tests)