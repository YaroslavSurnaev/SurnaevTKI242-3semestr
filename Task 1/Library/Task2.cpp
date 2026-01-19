#include "Task2.h"
#include <iostream>
#include <string>

namespace algebra
{
    void Task2::execute()
    {
        int max_val = matrix[0];
        for (size_t i = 1; i < matrix.size(); i++)
        {
            if (matrix[i] > max_val)
            {
                max_val = matrix[i];
            }
        }

        int count_contains_one = 0;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            std::string num_str = std::to_string(abs(matrix[i]));
            if (num_str.find('1') != std::string::npos)
            {
                count_contains_one++;
            }
        }

        Matrix<int> result(matrix.size() + count_contains_one);

        size_t j = 0;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            result[j] = matrix[i];
            j++;

            std::string num_str = std::to_string(abs(matrix[i]));
            if (num_str.find('1') != std::string::npos)
            {
                result[j] = max_val;
                j++;
            }
        }

        std::cout << "Task 2 result: " << result.to_string() << std::endl;
    }
}