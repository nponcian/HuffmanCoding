HuffmanCoding

## PURPOSE
This progam aims to implement the compression that Huffman Coding does by performing different algorithms that will process the target message and produce the Huffman codes accordingly.

## REQUIREMENTS
1. GNU/Linux environment
    * Either:
        1. Full operating system
        2. Virtual machine (as a guest OS)
        3. Cygwin
        4. etc.
2. Git (optional if you just prefer to do a download and extract from GitHub)
    ~~~
    sudo apt install git
    ~~~
3. GNU Toolchain
    ~~~
    sudo apt install build-essential
    ~~~
4. CMake
    ~~~
    sudo apt install cmake
    ~~~

## BUILDING
~~~
git clone https://github.com/nponcian/HuffmanCoding.git
cd HuffmanCoding
mkdir -p build && cd build
cmake ..
~~~

## RUNNING
~~~
cd HuffmanCoding/build
cmake ..
make
src/huffman_src --help

# Command format
# src/huffman_src [../Path/To/File/Containing/Message]
src/huffman_src ../message.txt
~~~

## TESTING
~~~
cd HuffmanCoding/build
cmake ..
make
test/huffman_test
~~~

## EXAMPLE
* ../message.txt
~~~
shesells seashells bythe seashore
~~~

* Compress the message
~~~
src/huffman_src ../message.txt
~~~

* output
~~~
[ParenthesisString] Character                    Frequency / Code
[ParenthesisString] b                            1
[ParenthesisString] y                            1
[ParenthesisString] t                            1
[ParenthesisString] o                            1
[ParenthesisString] r                            1
[ParenthesisString] a                            2
[ParenthesisString]                              3
[ParenthesisString] h                            4
[ParenthesisString] l                            4
[ParenthesisString] e                            7
[ParenthesisString] s                            8
[ParenthesisString]
[ParenthesisString] Character                    Frequency / Code
[ParenthesisString] ((e(((by)a)h))(s(l((r(to)) )))) 33
[ParenthesisString]
[ParenthesisString] Character                    Frequency / Code
[ParenthesisString]                              1111
[ParenthesisString] a                            0101
[ParenthesisString] b                            01000
[ParenthesisString] e                            00
[ParenthesisString] h                            011
[ParenthesisString] l                            110
[ParenthesisString] o                            111011
[ParenthesisString] r                            11100
[ParenthesisString] s                            10
[ParenthesisString] t                            111010
[ParenthesisString] y                            01001
~~~
