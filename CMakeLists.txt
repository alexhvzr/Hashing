cmake_minimum_required(VERSION 3.12)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment4 main.cpp BarcodeBSTScanner.cpp BarcodeArrayScanner.cpp BinarySearchTree.h Item.h ClientProgram.h HashNode.h LinkedList.h HashMap.cpp)