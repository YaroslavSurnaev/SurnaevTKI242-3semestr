#include "RandomGenerator.h"

namespace algebra
{
    RandomGenerator::RandomGenerator() : gen(std::random_device{}())
    {
    }

    int RandomGenerator::generate()
    {
        std::uniform_int_distribution<int> dist(MIN_VALUE, MAX_VALUE);
        return dist(gen);
    }
}