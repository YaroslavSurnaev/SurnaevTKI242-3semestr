#pragma once
#include "Exercise.h"

namespace algebra
{
    // Первый класс - задание 1
    class Variant7Task1 : public Exercise
    {
    public:
        Variant7Task1(size_t size, Generator* gen);
        void Task() override;
    };

    // Второй класс - задание 2
    class Variant7Task2 : public Exercise
    {
    public:
        Variant7Task2(size_t size, Generator* gen);
        void Task() override;

    private:
        bool contains_digit_1(int number);
        int find_max_element();
    };

    // Третий класс - задание 3
    class Variant7Task3
    {
    public:
        Matrix execute(const Matrix& D);
    };
}