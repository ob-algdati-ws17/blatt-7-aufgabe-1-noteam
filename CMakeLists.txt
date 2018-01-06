cmake_minimum_required(VERSION 3.10)
project(blatt_7_aufgabe_1_noteam)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        avlTree/avlTree.cpp
        avlTree/avlTree.h
        test/CMakeLists.txt
        test/main.cpp
        test/testList.cpp
        test/testList.h
        .gitignore
        .travis.yml
        CMakeLists.txt
        CMakeLists.txt.in
        README.md)

add_executable(blatt_7_aufgabe_1_noteam ${SOURCE_FILES})