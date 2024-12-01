cmake_minimum_required(VERSION 3.20)

project(CaesarCipher)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

# Add source files
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

# Add main file
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Iinclude -Wall -Wextra -Werror -Wpedantic)

# Enable debug symbols if flag is set ENABLE_DEBUG (`cmake -DENABLE_DEBUG=True ..`)
if(ENABLE_DEBUG)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
endif()

# Add custom targets for clang-format and clang-tidy
add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${SOURCES} ${HEADERS}
)

add_custom_target(
    clang-tidy
    COMMAND clang-tidy ${SOURCES}
)

add_custom_target(
    check
    COMMAND clang-format --dry-run -Werror ${SOURCES} ${HEADERS}
    COMMAND clang-tidy ${SOURCES}
)
