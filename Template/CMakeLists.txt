project(Template)

file(GLOB_RECURSE src ${CMAKE_CURENT_SOURCE_DIRS}/Template/*.hpp)

add_executable(test_node ./test.cpp ${src})