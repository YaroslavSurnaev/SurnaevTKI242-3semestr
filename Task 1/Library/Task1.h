#pragma once
#include "Exercise.h"
namespace algebra
{
    class Task1 : public Exercise
    {
    public:
        Task1(const Matrix<int>& m, Generator* gen) : Exercise(m, gen) {}
        void execute() override;
    };
}