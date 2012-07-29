include_directories(
../logging
../utils
../server
../client
/home/joe/projects/boost_1_48_0
)

file(GLOB SOURCES src/*.cpp)

add_executable(blacksun ${SOURCES})

target_link_libraries(
blacksun
utils
logging
server
client
pthread
/home/joe/projects/boost_1_48_0/bin.v2/libs/system/build/gcc-4.6.1/release/link-static/threading-multi/libboost_system.a
/home/joe/projects/boost_1_48_0/bin.v2/libs/filesystem/build/gcc-4.6.1/release/link-static/threading-multi/libboost_filesystem.a
)
