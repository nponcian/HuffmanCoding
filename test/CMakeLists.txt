cmake_minimum_required(VERSION 3.10.2)
project(huffman_test)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
# if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
# endif()
include_directories(../src)

add_definitions(-DDONT_PRINT_TO_SCREEN)

set(parent_huffman_test_algorithm_cpp "")

add_subdirectory(Algorithm)

file(GLOB huffman_test_cpp "*.cpp")

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(
    huffman_test
    ${huffman_test_cpp}
    ${parent_huffman_test_algorithm_cpp})
target_link_libraries(huffman_test gtest_main)
target_link_libraries(huffman_test huffman_src_algorithm_FOR_TESTING)
add_test(NAME example_test COMMAND example)
