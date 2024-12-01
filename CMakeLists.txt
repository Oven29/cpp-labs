cmake_minimum_required(VERSION 3.20)

project(Caesar cipher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add directory include for header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Inlcuding .cpp files in directory src (and subdirectories)
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
# Inlcuding .h files in directory include (and subdirectories)
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})

# Add compile options
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Iinclude -Wall -Wextra -Werror -Wpedantic)

# Добавляем флаг для использования Clang-Tidy
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

# Enable debug symbols if flag is set ENABLE_DEBUG (`cmake -DENABLE_DEBUG=True ..`)
if(ENABLE_DEBUG)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
endif()

# Add targets for clang-format and clang-tidy
# Run custom target: `cmake --build . --target <custom target>`
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
    COMMAND clang-tidy ${SOURCES}
    COMMAND clang-format --dry-run -Werror ${SOURCES} ${HEADERS}
)
