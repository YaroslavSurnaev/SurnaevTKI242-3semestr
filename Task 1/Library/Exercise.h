#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace algebra
{
    class Exercise
    {
    protected:
        Matrix<int> matrix;
        Generator* generator;

    public:
        Exercise(const Matrix<int>& m, Generator* gen);
        virtual ~Exercise() = default;

        virtual void execute() = 0;

        Matrix<int> getMatrix() const;
    };
}