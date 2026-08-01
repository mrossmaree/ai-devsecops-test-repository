cmake_minimum_required(VERSION 3.16)

project(ai_devsecops_test_repository LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    test_application
    src/main.cpp
    src/account.cpp
    src/customer.cpp
    src/logger.cpp
)

target_include_directories(
    test_application
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(
    test_application
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)