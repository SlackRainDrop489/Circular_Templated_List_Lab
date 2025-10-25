cmake_minimum_required(VERSION 4.0)
project(CircularTemplatedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(CircularTemplatedList main.cpp
        Media.cpp
        Media.h
        Song.cpp
        Song.h
        Podcast.cpp
        Podcast.h
        LinkedList.cpp
        LinkedList.h)
