#pragma once
#include "Matrix.h"
#include <memory>

namespace algebra
{
    class Exercise
    {
    protected:
        Matrix matrix;
        std::unique_ptr<Generator> generator;

    public:
        explicit Exercise(size_t size, Generator* gen = nullptr);
        virtual ~Exercise() = default;

        Exercise(const Exercise&) = delete;
        Exercise& operator=(const Exercise&) = delete;
        Exercise(Exercise&&) = default;
        Exercise& operator=(Exercise&&) = default;

        virtual void Task1() = 0;
        virtual void Task2() = 0;
        virtual Matrix Task3(const Matrix& D) = 0;

        void print() const;
        Matrix get() const;

    protected:
        Matrix& access_matrix();
        const Matrix& access_matrix() const;
    };
}