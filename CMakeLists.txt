cmake_minimum_required(VERSION 3.20)

project(Dict)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/args_parser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/collections/mdict.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/app.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/args_parser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/collections/mdict.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)

add_custom_target(
    clang-format
    COMMAND clang-format
    --dry-run
    -Werror
    ${SOURCES}
    ${HEADERS}
)
