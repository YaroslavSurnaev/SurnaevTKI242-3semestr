#include "Variant7.h"
#include <cmath>

namespace algebra
{
    // Реализация задания 1
    Variant7Task1::Variant7Task1(size_t size, Generator* gen) : Exercise(size, gen) {}

    void Variant7Task1::Task()
    {
        int max_index = 0;
        for (size_t i = 1; i < matrix.get_size(); i++)
        {
            if (matrix[i] > matrix[max_index])
            {
                max_index = i;
            }
        }
        matrix[max_index] = -matrix[max_index];
    }

    // Реализация задания 2
    Variant7Task2::Variant7Task2(size_t size, Generator* gen) : Exercise(size, gen) {}

    void Variant7Task2::Task()
    {
        int max_elem = find_max_element();
        size_t old_size = matrix.get_size();

        int count = 0;
        for (size_t i = 0; i < old_size; i++)
        {
            if (contains_digit_1(matrix[i])) count++;
        }

        Matrix new_matrix(old_size + count);
        int new_index = 0;

        for (size_t i = 0; i < old_size; i++)
        {
            new_matrix[new_index++] = matrix[i];
            if (contains_digit_1(matrix[i]))
            {
                new_matrix[new_index++] = max_elem;
            }
        }

        matrix = new_matrix;
    }

    bool Variant7Task2::contains_digit_1(int number)
    {
        int n = std::abs(number);
        while (n > 0)
        {
            if (n % 10 == 1) return true;
            n /= 10;
        }
        return false;
    }

    int Variant7Task2::find_max_element()
    {
        int max_val = matrix[0];
        for (size_t i = 1; i < matrix.get_size(); i++)
        {
            if (matrix[i] > max_val) max_val = matrix[i];
        }
        return max_val;
    }

    // Реализация задания 3
    Matrix Variant7Task3::execute(const Matrix& D)
    {
        Matrix A(D.get_size());

        for (size_t i = 0; i < D.get_size(); i++)
        {
            if (i % 2 == 0)
                A[i] = D[i] + (int)i;
            else
                A[i] = D[i] - (int)i;
        }
        return A;
    }
}