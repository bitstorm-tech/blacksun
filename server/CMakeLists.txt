include_directories(../logging /home/joe/projects/boost_1_48_0)
file(GLOB SOURCES *.cpp)

add_library(server ${SOURCES})
