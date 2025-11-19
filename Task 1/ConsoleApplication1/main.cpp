#include <iostream>
#include "Variant7.h"

using namespace algebra;

int main()
{
    std::cout << "=== ВАРИАНТ 7 (3 класса) ===" << std::endl;

    // Задание 1
    std::cout << "\n--- Задание 1 ---" << std::endl;
    Variant7Task1 task1(8, new RandomGenerator());
    std::cout << "Исходный массив: ";
    task1.print_matrix();
    task1.Task();
    std::cout << "После задания 1: ";
    task1.print_matrix();

    // Задание 2
    std::cout << "\n--- Задание 2 ---" << std::endl;
    Variant7Task2 task2(8, new RandomGenerator());
    std::cout << "Исходный массив: ";
    task2.print_matrix();
    task2.Task();
    std::cout << "После задания 2: ";
    task2.print_matrix();

    // Задание 3
    std::cout << "\n--- Задание 3 ---" << std::endl;
    Variant7Task3 task3;
    Matrix D(5);
    D.fill_with(*new RandomGenerator());
    Matrix A = task3.execute(D);
    std::cout << "Массив D: " << D.to_string() << std::endl;
    std::cout << "Массив A: " << A.to_string() << std::endl;

    return 0;
}