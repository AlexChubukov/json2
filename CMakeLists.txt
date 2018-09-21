cmake_minimum_required (VERSION 2.8)

include(gtest.cmake)
include_directories(
    json/include
    )

include_directories(SYSTEM
    ./
)

# if(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fsanitize=address -O1 -Wall -Wextra -Wno-unused-command-line-argument -Wshadow -Wnon-virtual-dtor -pedantic")
# endif(CMAKE_COMPILER_IS_GNUCXX)

# enum your files
add_library(json_lib STATIC json.cpp json.hpp)
add_executable(test
  test.cpp
)
add_executable(main
  main.cpp
)
find_package (Threads)
target_link_libraries(test -fsanitize=address gtest ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test json_lib)
target_link_libraries(main json_lib)
