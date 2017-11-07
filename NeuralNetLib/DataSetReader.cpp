//
// Created by James Brown
// Github: brojam
//

#include "DataSetReader.h"

#include "boost/lexical_cast.hpp"

#include <iterator>

namespace NeuralNet
{
    namespace
    {
        const int FEATURE_COUNT = 4;
        const int OUTPUT_COUNT = 3;

        long numberOfDataSetEntries(std::ifstream & file)
        {
            return std::count(
                std::istream_iterator<char>(file),
                std::istream_iterator<char>(),
                '\n'
            );
        }

        double convertToDouble(const std::string & string)
        {
            std::ostringstream ss;

        }
    } // anonymous namespace

    std::unique_ptr<DataSet> DataSetReader::read(
        const std::string & trainingFile,
        const std::string & validationFile,
        const std::string & testFile
    ) const
    {
        auto dataSet = std::unique_ptr<DataSet>(new DataSet{});
        readSet(trainingFile, dataSet->trainingSet_);
        readSet(validationFile, dataSet->validationSet_);
        readSet(testFile, dataSet->testSet_);

        return dataSet;
    }

    void DataSetReader::readSet(const std::string & file, DataSet::DataClass & dataClass) const
    {
        std::ifstream ifstream {file, std::ios::in};
        ifstream.unsetf(std::ios_base::skipws);

        if(!ifstream.is_open())
        {
            std::stringstream ss;
            ss << "There was a problem opening the " << file << " data file!\n";
            std::cerr << ss.str();
            throw std::runtime_error(ss.str());
        }

        auto numOfEntries = numberOfDataSetEntries(ifstream);

        dataClass.inputs_ = arma::Mat<float>(numOfEntries, FEATURE_COUNT);
        dataClass.outputs_ = arma::Mat<int>(numOfEntries, OUTPUT_COUNT);
        dataClass.count_ = boost::numeric_cast<unsigned long>(numOfEntries);

        ifstream.clear();
        ifstream.seekg(0, std::ios::beg);

        for(int i = 0; i < numOfEntries; ++i)
        {
            std::string str;
            std::getline(ifstream, str);

            std::istringstream iss{str};
            std::string value;

            for (int j = 0; j < FEATURE_COUNT; ++j)
            {
                std::getline(iss, value, '\t');
                dataClass.inputs_.row(i)(j) = boost::lexical_cast<float>(value);
            }

            for (int j = 0; j < OUTPUT_COUNT; ++j)
            {
                std::getline(iss, value, '\t');
                dataClass.outputs_.row(i)(j) = boost::lexical_cast<int>(value);
            }
        }

        ifstream.close();
    }
}
