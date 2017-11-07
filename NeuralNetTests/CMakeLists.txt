cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

include_directories(${CMAKE_SOURCE_DIR})

add_executable(runNeuralNetLibTests
        NeuralNetLibTests.cpp
        DataSetReaderTests.cpp)

target_link_libraries(runNeuralNetLibTests NeuralNetLib)
target_link_libraries(runNeuralNetLibTests armadillo)
target_link_libraries(runNeuralNetLibTests blas)
target_link_libraries(runNeuralNetLibTests lapack)
target_link_libraries(runNeuralNetLibTests gmock gmock_main)
target_link_libraries(runNeuralNetLibTests gtest gtest_main)