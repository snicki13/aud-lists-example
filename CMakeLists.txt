cmake_minimum_required(VERSION 3.19)
project(AuD-Listen C)

set(CMAKE_C_STANDARD 11)

add_executable(ReverseLinkedList ReverseLinkedList.c lib/LinkedList.c lib/LinkedList.h)
add_executable(DeleteArrayListElement DeleteArrayListElement.c lib/ArrayList.c lib/ArrayList.h)