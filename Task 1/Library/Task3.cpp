#include "Task3.h"

namespace algebra
{
    Matrix Task3::Task3(const Matrix& D)
    {
        Matrix A(D.get_size());

        for (size_t i = 0; i < D.get_size(); i++)
        {
            A[i] = calculate_value(D[i], i);
        }

        return A;
    }

    int Task3::calculate_value(int value, size_t index) const
    {
        if (index % 2 == 0)
            return value + static_cast<int>(index);
        else
            return value - static_cast<int>(index);
    }
}