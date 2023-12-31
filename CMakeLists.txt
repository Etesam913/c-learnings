# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(C++Playground VERSION 1.0)

find_package(GTest REQUIRED)
find_package(Boost REQUIRED)


# Include Boost headers
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif ()


# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optionally, set a variable for sources for clarity
set(SOURCES
        src/main.cpp
        src/trie.cpp
        src/binary-search-tree.cpp
)

set(TEST_SOURCES
        test/trie-tests.cpp
        src/trie.cpp
        test/binary-search-tree-tests.cpp
        src/binary-search-tree.cpp
)

# Add include directories
include_directories(include)

# Add an executable based on the source files
add_executable(C++Playground ${SOURCES})
add_executable(unit_tests ${TEST_SOURCES})

# Link against libraries (if any)
target_link_libraries(unit_tests GTest::gtest GTest::gtest_main)

# If using any third-party libraries stored in 'libs', add them
# add_subdirectory(libs/SomeLibrary)

# Install rules (optional)
install(TARGETS C++Playground DESTINATION bin)
install(FILES include/trie.hpp DESTINATION include)

# CPack packaging (optional, requires including CPack module)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
