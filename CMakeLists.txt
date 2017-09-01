cmake_minimum_required (VERSION 2.6)
project (sample)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./build/)
set(CMAKE_CXX_FLAGS "-std=c++11")
aux_source_directory(./src/ DIR_SRC)

add_executable(sample ${DIR_SRC})

target_link_libraries (sample event)


