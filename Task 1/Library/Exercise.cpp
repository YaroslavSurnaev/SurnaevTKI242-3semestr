#include "Exercise.h"

namespace algebra
{
    Exercise::Exercise(const Matrix<int>& m, Generator* gen) : matrix(m), generator(gen)
    {
    }


    Matrix<int> Exercise::getMatrix() const
    {
        return matrix;
    }
}