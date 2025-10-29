#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Variant7 : public Exercise
    {
    public:
        Variant7(size_t size, Generator* gen);
        void Task1() override;
        void Task2() override;
        Matrix<int> Task3(const Matrix<int>& D);

    private:
        bool contains_digit_1(int number);
        int find_max_element();
    };
}
