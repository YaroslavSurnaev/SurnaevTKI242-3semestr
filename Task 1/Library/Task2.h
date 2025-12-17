#pragma once
#include "Exercise.h"

namespace algebra
{
    class Task2 : public Exercise
    {
    public:
        using Exercise::Exercise;

        void Task2() override;

    private:
        bool contains_digit_1(int number) const;
        int find_max_element() const;
    };
}