project(Blacksun)
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib) 
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/conf DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory(utils)
add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(main)
