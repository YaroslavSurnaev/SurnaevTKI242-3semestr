#include "Variant7.h"
#include <iostream>

namespace algebra
{
    Variant7::Variant7(size_t size, Generator* gen)
        : task1(size, gen),
        task2(size, gen),
        task3(size, gen),
        original_matrix(task1.get())
    {
    }

    Matrix Variant7::execute_task1()
    {
        task1.Task1();
        return task1.get();
    }

    Matrix Variant7::execute_task2()
    {
        task2.Task2();
        return task2.get();
    }

    Matrix Variant7::execute_task3(const Matrix& D)
    {
        return task3.Task3(D);
    }

    void Variant7::print_all() const
    {
        std::cout << "Исходная матрица: " << original_matrix << std::endl;
        std::cout << "После Task1: " << task1.get() << std::endl;
        std::cout << "После Task2: " << task2.get() << std::endl;
    }

    Matrix Variant7::get_original() const
    {
        return original_matrix;
    }
}