cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11)

set(NAME "mytest")
project(${NAME})
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_MODULE_PATH ${PROJECT_ROOT}/cmake/Modules/)

set(myList_ROOT /usr/local/myList)
find_package(myList)

file(GLOB ${NAME}_HEADERS *.hpp)
file(GLOB ${NAME}_SOURCES *.cpp)

include_directories(${myList_INCLUDE_DIRS})
include_directories(${PROJECT_ROOT}/lib/)

add_executable(${NAME} ${${NAME}_HEADERS} ${${NAME}_SOURCES})

target_link_libraries(${NAME} ${myList_LIBRARIES})
target_link_libraries(${NAME} myHashTable)
