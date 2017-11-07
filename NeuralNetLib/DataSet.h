//
// Created by James Brown
// Github: brojam
//

#include <armadillo>

namespace NeuralNet
{
    struct DataSet
    {
        long inputCount_;
        long outputCout_;

        struct DataClass
        {
            arma::Mat<float> inputs_;
            arma::Mat<int> outputs_;
            arma::Col<int> classes_;
            unsigned long count_;
            arma::Col<double> bias_;

        };

        DataClass trainingSet_;
        DataClass validationSet_;
        DataClass testSet_;
    };
}

