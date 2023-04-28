cmake_minimum_required(VERSION 3.24)
project(PiggyDB)

set(CMAKE_CXX_STANDARD 23)

add_executable(PiggyDB main.cpp src/include/def.h src/include/Page.h src/DiskManager.cpp src/include/DiskManager.h src/include/RWLock.h src/include/exception.h)
