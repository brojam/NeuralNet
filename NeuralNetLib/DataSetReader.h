//
// Created by James Brown
// Github: brojam
//

#pragma once

#include "IDataSetReader.h"

namespace NeuralNet
{
    class DataSetReader
        : public IDataSetReader
    {
    public:
        std::unique_ptr<DataSet> read(
            const std::string & trainingFile,
            const std::string & validationFile,
            const std::string & testFile
        ) const override;

    private:
        void readSet(const std::string & file, DataSet::DataClass & dataClass) const;
    };
}

