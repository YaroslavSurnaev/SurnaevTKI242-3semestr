#include "ConstantGenerator.h"

namespace algebra
{
    ConstantGenerator::ConstantGenerator(int constant_value)
        : value(constant_value)
    {
    }

    int ConstantGenerator::generate()
    {
        return value;
    }
}