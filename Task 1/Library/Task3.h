#pragma once
#include "Exercise.h"
namespace algebra
{
    class Task3 : public Exercise
    {
    public:
        Task3(const Matrix<int>& m, Generator* gen) : Exercise(m, gen) {}
        void execute() override;
    };
}