#pragma once

#include <boost/lexical_cast.hpp>

#include <armadillo>

namespace NeuralNetLib
{
    template <typename T>
    arma::Col<T> outputMatrixToClassNumberVector(const arma::Mat<T> & outputMatix) noexcept
    {
        arma::Col<T> classNumberVector(static_cast<arma::s32>(outputMatix.n_rows));
        classNumberVector.ones();

        for(auto i = 0; i < static_cast<int>(outputMatix.n_rows); ++i)
        {
            for(auto j = 0; j < static_cast<int>(outputMatix.n_cols); ++j)
            {
                if(outputMatix.at(i, j) == 1)
                {
                    classNumberVector.at(i) = j + 1;
                }
            }
        }

        return classNumberVector;
    }

    template <typename T>
    arma::Mat<T> classNumberVectorToOutputMatrix(const arma::Col<T> & classNumberVector) noexcept
    {
        if(classNumberVector.is_empty())
        {
            return  arma::Mat<T>{};
        }

        arma::Mat<T> outputMatrix = arma::Mat<T> (classNumberVector.size(), classNumberVector.max());
        outputMatrix.zeros();

        for(auto i = 0; i < static_cast<int>(classNumberVector.size()); ++i)
        {
            auto classColumn = classNumberVector.at(i) - 1;
            outputMatrix.at(i, classColumn) = 1;
        }

        return outputMatrix;
    }

    template <typename T>
    arma::Mat<T> applyActivationFunction(const arma::Mat<T> & inputMatrix)
    {
        const auto activationFunction = [](T value) -> T
        {
            return (tanh(value) + 1) / 2;
        };

        auto resultMatrix = inputMatrix;

        for(int i = 0; i < resultMatrix.n_cols; ++i)
        {
            for(int j = 0; j < resultMatrix.n_rows; ++j)
            {
                resultMatrix[j, i] = activationFunction(inputMatrix[j, i]);
            }
        }

        return resultMatrix;
    }

    template <typename T>
    arma::Mat<T> applyActivationFunctionDerivative(const arma::Mat<T> & inputMatrix)
    {
        const auto activationFunction = [](T value) -> T
        {
            return (1 - atanh(value)) / 2;
        };

        auto resultMatrix = inputMatrix;

        for(int i = 0; i < resultMatrix.n_cols; ++i)
        {
            for(int j = 0; j < resultMatrix.n_rows; ++j)
            {
                resultMatrix[j, i] = activationFunction(inputMatrix[j, i]);
            }
        }

        return resultMatrix;
    }

}