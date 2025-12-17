#pragma once
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"

namespace algebra
{
    class Variant7
    {
    private:
        Task1 task1;
        Task2 task2;
        Task3 task3;
        Matrix original_matrix;

    public:
        Variant7(size_t size, Generator* gen = nullptr);

        Matrix execute_task1();
        Matrix execute_task2();
        Matrix execute_task3(const Matrix& D);

        void print_all() const;
        Matrix get_original() const;
    };
}