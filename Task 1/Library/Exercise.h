#pragma once
#include "Matrix.h"
#include "Generator.h"

namespace algebra
{
    class Exercise
    {
    protected:
        Matrix matrix;
        Generator* generator;

    public:
        Exercise(size_t size, Generator* gen);
        virtual ~Exercise();

        virtual void Task() = 0; 

        Matrix get_matrix() const;
        void print_matrix() const;
    };
}