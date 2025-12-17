#include "Task1.h"
#include <stdexcept>

namespace algebra
{
    void Task1::Task1()
    {
        Matrix& matrix = access_matrix();

        if (matrix.get_size() == 0) return;

        size_t max_index = find_max_index();
        matrix[max_index] = -matrix[max_index];
    }

    size_t Task1::find_max_index() const
    {
        const Matrix& matrix = access_matrix();

        if (matrix.get_size() == 0)
            throw std::runtime_error("Matrix is empty");

        size_t max_index = 0;
        for (size_t i = 1; i < matrix.get_size(); i++)
        {
            if (matrix[i] > matrix[max_index])
            {
                max_index = i;
            }
        }
        return max_index;
    }
}