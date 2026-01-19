#include "ConstantGenerator.h"

namespace algebra
{
    int ConstantGenerator::generate()
    {
        switch (type)
        {
        case MANUAL:
        {
            int value;
            std::cin >> value;
            return value;
        }
        case RANDOM:
            return min_val + rand() % (max_val - min_val + 1);
        }
    }
}