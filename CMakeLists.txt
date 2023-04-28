cmake_minimum_required(VERSION 3.24)
project(PiggyDB)

set(CMAKE_CXX_STANDARD 23)

add_executable(PiggyDB main.cpp src/include/def.h src/include/Page.h src/storage/DiskManager.cpp src/include/DiskManager.h src/include/RWLock.h src/include/exception.h src/buffer/BufferPool.cpp src/include/BufferPool.h src/include/Replacer.h src/include/LRUReplacer.cpp src/include/LRUReplacer.h)
