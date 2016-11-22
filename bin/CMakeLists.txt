cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11)

set(NAME "mytest")
project(${NAME})
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_MODULE_PATH ${PROJECT_ROOT}/cmake/Modules/)

set(mylist_ROOT /usr/local/mylist)
set(myHashTable_ROOT /usr/local/myHashTable)
find_package(Threads)
find_package(mylist)
find_package(myHashTable)

file(GLOB ${NAME}_HEADERS *.hpp)
file(GLOB ${NAME}_SOURCES *.cpp)

include_directories(${mylist_INCLUDE_DIRS})
include_directories(${myHashTable_INCLUDE_DIRS})

add_executable(${NAME} ${${NAME}_HEADERS} ${${NAME}_SOURCES})

target_link_libraries(${NAME} pthread)
target_linK_libraries(${NAME} ${mylist_LIBRARIES})
target_linK_libraries(${NAME} ${myHashTable_LIBRARIES})
