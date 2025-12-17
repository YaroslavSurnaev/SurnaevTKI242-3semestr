#include "Exercise.h"
#include <iostream>
#include "RandomGenerator.h"
#include "ZeroGenerator.h"
#include "ConstantGenerator.h"

namespace algebra
{
    Exercise::Exercise(size_t size, Generator* gen) : matrix(size)
    {
        if (gen)
        {
            generator.reset(gen);
            matrix.fill(*generator);
        }
        else
        {
            generator = std::make_unique<RandomGenerator>();
            matrix.fill(*generator);
        }
    }

    void Exercise::print() const
    {
        std::cout << matrix << std::endl;
    }

    Matrix Exercise::get() const
    {
        return matrix;
    }

    Matrix& Exercise::access_matrix()
    {
        return matrix;
    }

    const Matrix& Exercise::access_matrix() const
    {
        return matrix;
    }
}