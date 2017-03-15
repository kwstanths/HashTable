cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11)

set(NAME "myHashTable")
project(${NAME})
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_MODULE_PATH ${PROJECT_ROOT}/cmake/Modules/)

set(myList_ROOT /usr/local/myList)
find_package(myList)

file(GLOB ${NAME}_HEADERS *.hpp)
file(GLOB ${NAME}_SOURCES *.cpp)

include_directories(${myList_INCLUDE_DIRS})

add_library(${NAME} ${${NAME}_HEADERS})
set_target_properties(${NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${NAME} pthread)
target_linK_libraries(${NAME} ${myList_LIBRARIES})

install(TARGETS ${NAME} DESTINATION ${NAME}/lib)
install(FILES ${${NAME}_HEADERS} DESTINATION ${NAME}/include) 
