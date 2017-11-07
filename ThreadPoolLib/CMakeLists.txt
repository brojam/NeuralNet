cmake_minimum_required(VERSION 3.8)
project(NeuralNet C CXX)

set(CMAKE_CXX_STANDARD 17)

#find_package(Boost 1.62.0 COMPONENTS program_options REQUIRED)
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIR})
#    add_definitions("-dhas-boost")
#endif()

add_library(ThreadPoolLib
        IBlockingQueue.h
        BlockingQueue.h
        BlockingQueue.cpp
        IRunner.h
        Runner.h
        Runnable.cpp
        IThreadPool.h
        ThreadPool.cpp
        ThreadPool.h
        )

set_target_properties(ThreadPoolLib PROPERTIES LINKER_LANGUAGE CXX)
#TARGET_LINK_LIBRARIES(ThreadPoolLib LINK_PUBLIC ${Boost_LIBRARIES})