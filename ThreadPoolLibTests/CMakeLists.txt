cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(runThreadPoolLibTests
        BlockingQueueTests.cpp
        )

target_link_libraries(runThreadPoolLibTests ThreadPoolLib)
target_link_libraries(runThreadPoolLibTests gmock gmock_main)
target_link_libraries(runThreadPoolLibTests gtest gtest_main)