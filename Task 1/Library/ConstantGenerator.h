#pragma once
#include "Generator.h"
#include <iostream>
#include <cstdlib>

namespace algebra
{
    enum FillType { MANUAL, RANDOM };

    class ConstantGenerator : public Generator
    {
    private:
        FillType type;
        int constant_value;
        int min_val;
        int max_val;

    public:
        ConstantGenerator(FillType t, int val1 = 0, int val2 = 0)
            : type(t), constant_value(val1), min_val(val1), max_val(val2) {}

        int generate() override;
    };
}