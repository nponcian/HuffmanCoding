file(GLOB huffman_test_algorithm_cpp
    "*.cpp")

set(parent_huffman_test_algorithm_cpp
    ${parent_huffman_test_algorithm_cpp}
    ${huffman_test_algorithm_cpp}
    PARENT_SCOPE)
