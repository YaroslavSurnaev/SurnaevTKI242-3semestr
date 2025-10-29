#include "pch.h"
#include "Variant7.h"
#include <cmath>
#include <sstream>

namespace miit::algebra
{
    Variant7::Variant7(size_t size, Generator* gen) : Exercise(size, gen) {}

    void Variant7::Task1()
    {
        // 1. Заменить максимальный элемент массива на противоположный по знаку
        int max_index = 0;
        int max_value = matrix[0];

        // Находим максимальный элемент
        for (size_t i = 1; i < matrix.get_size(); i++)
        {
            if (matrix[i] > max_value)
            {
                max_value = matrix[i];
                max_index = i;
            }
        }

        // Заменяем на противоположный по знаку
        matrix[max_index] = -matrix[max_index];
    }

    void Variant7::Task2()
    {
        // 2. Вставить максимальный элемент массива после всех элементов, в которых есть цифра 1
        int max_element = find_max_element();
        size_t original_size = matrix.get_size();

        // Считаем сколько элементов содержат цифру 1
        size_t count_with_1 = 0;
        for (size_t i = 0; i < original_size; i++)
        {
            if (contains_digit_1(matrix[i]))
            {
                count_with_1++;
            }
        }

        // Создаем новый массив увеличенного размера
        Matrix<int> new_matrix(original_size + count_with_1);
        size_t new_index = 0;

        // Копируем элементы и вставляем максимальный после элементов с цифрой 1
        for (size_t i = 0; i < original_size; i++)
        {
            new_matrix[new_index++] = matrix[i];
            if (contains_digit_1(matrix[i]))
            {
                new_matrix[new_index++] = max_element;
            }
        }

        matrix = new_matrix;
    }

    Matrix<int> Variant7::Task3(const Matrix<int>& D)
    {
        // 3. Создать массив A по правилу из массива C
        size_t size = D.get_size();
        Matrix<int> A(size);

        for (size_t i = 0; i < size; i++)
        {
            if (i < 10)
            {
                // Для первых 10 элементов
                if (i % 2 == 0) // четный индекс
                    A[i] = D[i] + static_cast<int>(i);
                else // нечетный индекс
                    A[i] = D[i] - static_cast<int>(i);
            }
            else
            {
                // Для остальных элементов
                if (i % 2 == 0) // четный индекс
                    A[i] = D[i] + static_cast<int>(i);
                else // нечетный индекс
                    A[i] = D[i] - static_cast<int>(i);
            }
        }

        return A;
    }

    bool Variant7::contains_digit_1(int number)
    {
        // Проверяем содержит ли число цифру 1
        int num = std::abs(number);

        if (num == 0) return false;

        while (num > 0)
        {
            if (num % 10 == 1) return true;
            num /= 10;
        }
        return false;
    }

    int Variant7::find_max_element()
    {
        int max_value = matrix[0];
        for (size_t i = 1; i < matrix.get_size(); i++)
        {
            if (matrix[i] > max_value)
            {
                max_value = matrix[i];
            }
        }
        return max_value;
    }
}