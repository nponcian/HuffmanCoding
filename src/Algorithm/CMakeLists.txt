file(GLOB huffman_src_algorithm_cpp
    "*.cpp")

add_library(huffman_src_algorithm ${huffman_src_algorithm_cpp})

add_library(huffman_src_algorithm_FOR_TESTING ${huffman_src_algorithm_cpp})
target_compile_definitions(huffman_src_algorithm_FOR_TESTING PUBLIC DONT_PRINT_TO_SCREEN)
