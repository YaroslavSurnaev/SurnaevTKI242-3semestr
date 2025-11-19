#pragma once
#include "Generator.h"
#include <random>

namespace algebra
{
    class RandomGenerator : public Generator
    {
    private:
        const int MIN_VALUE = -1000;  //  онстанта дл€ минимального значени€
        const int MAX_VALUE = 1000;   //  онстанта дл€ максимального значени€
        std::mt19937 gen;

    public:
        RandomGenerator();
        int generate() override;
    };
}
