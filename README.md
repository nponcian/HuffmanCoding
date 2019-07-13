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
~~~

## EXAMPLE
* ../message.txt
~~~
"beepboopbeer!"
~~~

* Compress the message
~~~
src/huffman_src ../message.txt
~~~

* output
~~~
Character   Frequency
"           2
b           3
e           4
p           2
o           2
r           1
!           1

Character               Frequency
((b(o"))(((r!)p)e))     15

Character   Code
b           00
o           010
"           011
r           1000
!           1001
p           101
e           11
~~~
