cmake_minimum_required(VERSION 3.10)

project(STL_Library VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# =====================================================
# Main Application
# =====================================================

add_executable(STL_Library
    main.cpp
)

target_include_directories(STL_Library PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# =====================================================
# GoogleTest
# =====================================================

add_subdirectory(external/googletest)

enable_testing()

# =====================================================
# DynamicArray Tests
# =====================================================

add_executable(DynamicArrayTests
    tests/main.cpp
    tests/DynamicArray/RemoveTests.cpp
    tests/DynamicArray/InsertTests.cpp
    tests/DynamicArray/PushBackTests.cpp
    tests/DynamicArray/PopBackTests.cpp
    tests/DynamicArray/SizeTests.cpp
    tests/DynamicArray/CapacityTests.cpp
    tests/DynamicArray/ClearTests.cpp
)

target_include_directories(DynamicArrayTests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(DynamicArrayTests
    PRIVATE
    gtest
    gtest_main
)

include(GoogleTest)

gtest_discover_tests(DynamicArrayTests)