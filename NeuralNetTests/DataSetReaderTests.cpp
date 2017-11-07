//
// Created by James Brown
// Github: brojam
//

#include "NeuralNetLib/DataSetReader.h"

#include <gtest/gtest.h>

namespace Test
{
    using namespace NeuralNet;

    TEST(DataSetReaderTests, happyPath)
    {
        auto reader = DataSetReader {};
        ASSERT_NO_THROW(
            reader.read(
                "../../Data/iris_data_files/iris_training.dat",
                "../../Data/iris_data_files/iris_test.dat",
                "../../Data/iris_data_files/iris_validation.dat"
            )
        );

    }
}

