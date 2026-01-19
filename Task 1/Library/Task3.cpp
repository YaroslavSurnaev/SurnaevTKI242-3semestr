#include "Task3.h"
#include <iostream>

namespace algebra
{
    void Task3::execute()
    {
        Matrix<int> result(matrix.size());

        for (size_t i = 0; i < matrix.size(); i++)
        {
            if (i < 10) 
            {
                if ((i + 1) % 2 != 0) 
                {
                    result[i] = matrix[i] - (i + 1);
                }
                else 
                {
                    result[i] = matrix[i] + (i + 1);
                }
            }
            else 
            {
                result[i] = matrix[i]; 
            }
        }

        std::cout << "Task 3 result: " << result.to_string() << std::endl;
    }
}