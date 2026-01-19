#include "Task1.h"
#include <iostream>

namespace algebra
{
    size_t findMaxElementIndex(const Matrix<int>& matrix)
    {
        size_t max_index = 0;
        for (size_t i = 1; i < matrix.size(); i++)
        {
            if (matrix[i] > matrix[max_index])
            {
                max_index = i;
            }
        }
        return max_index;
    }

    void Task1::execute()
    {
        Matrix<int> result = matrix;
        size_t max_index = findMaxElementIndex(matrix);

        if (max_index < matrix.size())
        {
            int max_value = result[max_index];
            result[max_index] = -max_value;
            std::cout << "Task 1 result: " << result.to_string() << std::endl;
            std::cout << "Replaced element at position " << max_index + 1
                << " (value: " << max_value << ") with " << -max_value << std::endl;
        }
        else
        {
            std::cout << "Task 1 result: " << result.to_string() << std::endl;
            std::cout << "Array is empty" << std::endl;
        }
    }
}