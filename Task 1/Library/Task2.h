#pragma once
#include "Exercise.h"
namespace algebra
{
    class Task2 : public Exercise
    {
    public:
        Task2(const Matrix<int>& m, Generator* gen) : Exercise(m, gen) {}
        void execute() override;
    };
}