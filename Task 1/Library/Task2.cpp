#include "Task2.h"
#include <cmath>
#include <stdexcept>

namespace algebra
{
    void Task2::Task2()
    {
        Matrix& matrix = access_matrix();

        if (matrix.get_size() == 0) return;

        int max_element = find_max_element();
        size_t old_size = matrix.get_size();

        size_t count = 0;
        for (size_t i = 0; i < old_size; i++)
        {
            if (contains_digit_1(matrix[i])) count++;
        }

        Matrix new_matrix(old_size + count);
        size_t new_index = 0;

        for (size_t i = 0; i < old_size; i++)
        {
            new_matrix[new_index++] = matrix[i];
            if (contains_digit_1(matrix[i]))
            {
                new_matrix[new_index++] = max_element;
            }
        }

        matrix = std::move(new_matrix);
    }

    bool Task2::contains_digit_1(int number) const
    {
        int n = std::abs(number);
        while (n > 0)
        {
            if (n % 10 == 1) return true;
            n /= 10;
        }
        return false;
    }

    int Task2::find_max_element() const
    {
        const Matrix& matrix = access_matrix();

        if (matrix.get_size() == 0)
            throw std::runtime_error("Matrix is empty");

        int max_val = matrix[0];
        for (size_t i = 1; i < matrix.get_size(); i++)
        {
            if (matrix[i] > max_val) max_val = matrix[i];
        }
        return max_val;
    }
}