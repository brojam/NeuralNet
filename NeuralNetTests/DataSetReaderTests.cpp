//
// Created by James Brown
// Github: brojam
//

#include "NeuralNetLib/DataSetReader.h"
#include "NeuralNetLib/Utils.h"

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

        auto data = reader.read(
            "../../Data/iris_data_files/iris_training.dat",
            "../../Data/iris_data_files/iris_test.dat",
            "../../Data/iris_data_files/iris_validation.dat"
        );

        data.get()->trainingSet_.inputs_.raw_print();

        auto activatedMatrix = NeuralNetLib::applyActivationFunction(data.get()->trainingSet_.inputs_);

        std::cout << std::endl << std::endl;

        activatedMatrix.raw_print();
    }
}

