#include <iostream>
#include <memory>
#include "../MatrixLib/Variant7.h"

using namespace miit::algebra;

int main()
{
    std::cout << "=== Демонстрация работы с массивом (Вариант 7) ===" << std::endl;

    // Создаем генератор случайных чисел для интервала [-1000; 1000]
    Generator* gen = new RandomGenerator(-1000, 1000);

    // Создаем объект для варианта 7 с массивом из 10 элементов
    Variant7 exercise(10, gen);

    std::cout << "\nИсходный массив:" << std::endl;
    exercise.print_matrix();

    // Задание 1
    std::cout << "\n--- Задание 1 ---" << std::endl;
    std::cout << "Заменяем максимальный элемент на противоположный по знаку" << std::endl;
    exercise.Task1();
    exercise.print_matrix();

    // Задание 2
    std::cout << "\n--- Задание 2 ---" << std::endl;
    std::cout << "Вставляем максимальный элемент после элементов с цифрой 1" << std::endl;
    exercise.Task2();
    exercise.print_matrix();

    // Задание 3
    std::cout << "\n--- Задание 3 ---" << std::endl;
    std::cout << "Создаем новый массив по правилу из исходного" << std::endl;

    // Создаем исходный массив D для задания 3
    Generator* gen2 = new RandomGenerator(-1000, 1000);
    Matrix<int> D(15);
    D.fill_with(*gen2);

    std::cout << "Исходный массив D: " << D.to_string() << std::endl;

    Matrix<int> A = exercise.Task3(D);
    std::cout << "Результирующий массив A: " << A.to_string() << std::endl;

    delete gen2;

    std::cout << "\n=== Программа завершена ===" << std::endl;

    return 0;
}