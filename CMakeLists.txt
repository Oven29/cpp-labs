cmake_minimum_required(VERSION 3.20)

project(MatrixPrint)

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

# Add source files
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic -Iinclude)

# Enable debug symbols if flag is set ENABLE_DEBUG (`cd build && cmake -ENABLE_DEBUG=True ..`)
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
    COMMAND clang-tidy -extra-arg=-Iinclude ${SOURCES}
)
