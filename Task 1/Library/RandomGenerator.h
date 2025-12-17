#pragma once
#include "Generator.h"
#include <random>

namespace algebra
{
    class RandomGenerator : public Generator
    {
    private:
        static const int MIN_VALUE = -1000;
        static const int MAX_VALUE = 1000;
        std::mt19937 gen;

    public:
        RandomGenerator();
        RandomGenerator(const RandomGenerator&) = delete;
        RandomGenerator& operator=(const RandomGenerator&) = delete;
        RandomGenerator(RandomGenerator&&) noexcept = default;
        RandomGenerator& operator=(RandomGenerator&&) noexcept = default;

        int generate() override;
    };
}