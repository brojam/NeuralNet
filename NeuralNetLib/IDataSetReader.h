//
// Created by James Brown
// Github: brojam
//

#include "DataSet.h"

#include <memory>
#include <string>

namespace NeuralNet
{
    class IDataSetReader
    {
    public:
        virtual std::unique_ptr<DataSet> read(
            const std::string & trainingFile,
            const std::string & validationFile,
            const std::string & testFile
        ) const = 0;
    };
}
