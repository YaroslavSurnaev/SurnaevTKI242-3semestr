#include "IStreamGenerator.h"

namespace algebra
{
    IStreamGenerator::IStreamGenerator(std::istream& input_stream)
        : in(input_stream)
    {
    }

    int IStreamGenerator::generate()
    {
        int value;
        in >> value;
        return value;
    }
}