include_directories(/home/joe/projects/boost_1_48_0)
file(GLOB SOURCES *.cpp)

add_library(logging ${SOURCES})
