//
// Created by James Brown
// Github: brojam
//

#include <armadillo>

struct DataSet
{
    long inputCount_;
    long outputCout_;

    struct DataClass
    {
        arma::Mat<> inputs_;
        arma::Mat<> outputs_;
        classes_;
        count_;
        bias_;

    };

    DataClass trainingSet_;
    DataClass validationSet_;
    DataClass testSet_;
};

