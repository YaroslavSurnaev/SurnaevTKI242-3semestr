#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra
{
    class Exercise
    {
    private:
        Matrix<int> matrix;
        Generator* generator;

    public:
        Exercise(size_t size, Generator* gen);
        virtual ~Exercise();

        virtual void Task1() = 0;
        virtual void Task2() = 0;

        Matrix<int> get_matrix() const;
        void print_matrix() const;
    };
}
