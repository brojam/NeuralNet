cmake_minimum_required(VERSION 3.8)
project(NeuralNet)

set(CMAKE_CXX_STANDARD 17)

add_library(NeuralNetLib
        Utils.h
        Utils.cpp
        DataSet.h
        IDataSetReader.h
        DataSetReader.h
        DataSetReader.cpp)

target_link_libraries(NeuralNetLib armadillo)