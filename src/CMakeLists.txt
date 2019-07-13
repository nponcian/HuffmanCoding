cmake_minimum_required(VERSION 3.10.2)
project(huffman_src)

include_directories(.)

add_subdirectory(Algorithm)
add_subdirectory(File)

file(GLOB huffman_src_cpp
    "*.cpp")

add_executable(huffman_src ${huffman_src_cpp})
target_link_libraries(huffman_src huffman_src_algorithm)
target_link_libraries(huffman_src huffman_src_file)
