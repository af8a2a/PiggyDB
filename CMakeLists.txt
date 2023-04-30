cmake_minimum_required(VERSION 3.24)
project(PiggyDB)

set(CMAKE_CXX_STANDARD 23)

add_executable(PiggyDB main.cpp src/include/def.h src/include/storage/Page/Page.h src/storage/DiskManager.cpp src/include/storage/DiskManager.h src/include/RWLock.h src/include/exception.h src/buffer/BufferPool.cpp src/include/BufferPool.h src/include/Replacer.h src/buffer/LRUReplacer.cpp src/include/LRUReplacer.h src/include/DBInstance.cpp src/include/DBInstance.h src/catalog/DataBase.cpp src/include/catalog/DataBase.h src/include/Table.cpp src/include/catalog/Table.h src/catalog/Colum.cpp src/include/catalog/Colum.h src/common/shell.cpp src/include/common/shell.h)
