project(Blacksun)
cmake_minimum_required(VERSION 2.8)

SET(LIBRARY_OUTPUT_DIRECTORY lib) 
SET(RUNTIME_OUTPUT_DIRECTORY bin)

add_subdirectory(logging)
add_subdirectory(utils)
add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(main)
