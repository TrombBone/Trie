cmake_minimum_required(VERSION 3.20)
project(Trie C)

set(CMAKE_C_STANDARD 99)

add_library(libTrie STATIC Trie.c)

add_executable(Trie main.c)
add_executable(testExec Tests.c)

target_link_libraries(Trie libTrie)
target_link_libraries(testExec libTrie)