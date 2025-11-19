#include "Exercise.h"
#include <iostream>

namespace algebra
{
    Exercise::Exercise(size_t size, Generator* gen)
        : matrix(size), generator(gen)
    {
        matrix.fill_with(*gen);
    }

    Exercise::~Exercise()
    {
        delete generator;
    }

    Matrix Exercise::get_matrix() const
    {
        return matrix;
    }

    void Exercise::print_matrix() const
    {
        std::cout << matrix.to_string() << std::endl;
    }
}