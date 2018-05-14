cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11)

set(NAME "myHashTable")
project(${NAME})

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_MODULE_PATH ${PROJECT_ROOT}/cmake/Modules/)

set(myList_ROOT /usr/local/myList)
find_package(myList)

include_directories(${mylist_INCLUDE_DIRS})

file(GLOB ${NAME}_HEADERS *.hpp)
file(GLOB ${NAME}_SOURCES *.cpp)

add_library(${NAME} ${${NAME}_HEADERS})
target_link_libraries(${NAME} ${mylist_LIBRARIES})
set_target_properties(${NAME} PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS ${NAME} DESTINATION ${NAME}/lib)
install(FILES ${${NAME}_HEADERS} DESTINATION ${NAME}/include) 
