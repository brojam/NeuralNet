// NeuralNetLibTests.cpp : Defines the entry point for the console application.
//

#include "NeuralNetLib/Utils.h"

#include <armadillo>

#include <gtest/gtest.h>

namespace NeuralNetLibTests
{
    using namespace arma;

    namespace
    {
//        class UtilsFixture
//        {
//        public:
//
//        };
    }

    TEST(UtilsFixture, outputMatrixToClassNumberVectorEmptyMatrixResultsInEmptyClassVector)
    {
        auto classNumberVector = NeuralNetLib::outputMatrixToClassNumberVector<int>({});
        EXPECT_EQ(0, classNumberVector.size());
    }

    TEST(UtilsFixture, outputMatrixToClassNumberVectorSingleValueToSingleValue)
    {
        arma::Mat<int> m(1, 1);
        m.ones();

        auto classNumberVector = NeuralNetLib::outputMatrixToClassNumberVector(m);

        EXPECT_EQ(1, classNumberVector.size());
        EXPECT_EQ(1, classNumberVector.at(0));
    }

    TEST(UtilsFixture, outputMatrixToClassNumberVectorMutlipleValueToMultipleClasses)
    {
        arma::Mat<int> m(3, 3);
        m.zeros();
        m.at(0, 1) = 1;
        m.at(1, 2) = 1;
        m.at(2, 0) = 1;

        auto classNumberVector = NeuralNetLib::outputMatrixToClassNumberVector(m);

        EXPECT_EQ(3, classNumberVector.size());
        EXPECT_EQ(2, classNumberVector.at(0));
        EXPECT_EQ(3, classNumberVector.at(1));
        EXPECT_EQ(1, classNumberVector.at(2));
    }

    TEST(UtilsFixture, classNumberVectorToOutputMatrixEmptyVectorResultsInEmptyMatrix)
    {
        auto outputMatrix = NeuralNetLib::classNumberVectorToOutputMatrix<int>({});
        EXPECT_EQ(0, outputMatrix.size());
    }

    TEST(UtilsFixture, classNumberVectorToOutputMatrixSingleValueResultsInSingleValue)
    {
        auto classNumberVector = arma::Col<int>(1);
        classNumberVector.ones();

        auto outputMatrix = NeuralNetLib::classNumberVectorToOutputMatrix(classNumberVector);
        EXPECT_EQ(1, outputMatrix.size());
        EXPECT_EQ(1, outputMatrix.at(0, 0));
    }

    TEST(UtilsFixture, classNumberVectorToOutputMatrixMultipleClassesToMultipleValues)
    {
        auto classNumberVector = arma::Col<int>(3);
        classNumberVector.at(0) = 2;
        classNumberVector.at(1) = 3;
        classNumberVector.at(2) = 1;

        auto outputMatrix = NeuralNetLib::classNumberVectorToOutputMatrix(classNumberVector);
        EXPECT_EQ(9, outputMatrix.size());
        EXPECT_EQ(0, outputMatrix.at(0, 0));
        EXPECT_EQ(1, outputMatrix.at(0, 1));
        EXPECT_EQ(1, outputMatrix.at(1, 2));
        EXPECT_EQ(1, outputMatrix.at(2, 0));
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}