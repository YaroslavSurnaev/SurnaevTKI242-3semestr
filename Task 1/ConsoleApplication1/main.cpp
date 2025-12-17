#include <iostream>
#include <memory>
#include "Variant7.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ZeroGenerator.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

int main()
{
    try
    {
        std::cout << "Выберите способ заполнения массива:" << std::endl;
        std::cout << "1 - случайные числа [-1000; 1000]" << std::endl;
        std::cout << "2 - ввод с клавиатуры" << std::endl;
        std::cout << "3 - заполнение нулями" << std::endl;
        std::cout << "4 - заполнение константой" << std::endl;

        int choice;
        std::cin >> choice;

        std::unique_ptr<Generator> generator;

        switch (choice)
        {
        case 1:
            generator = std::make_unique<RandomGenerator>();
            std::cout << "Используется случайный генератор" << std::endl;
            break;

        case 2:
            generator = std::make_unique<IStreamGenerator>();
            std::cout << "Введите 8 чисел:" << std::endl;
            break;

        case 3:
            generator = std::make_unique<ZeroGenerator>();
            std::cout << "Используется генератор нулей" << std::endl;
            break;

        case 4:
            int constant_value;
            std::cout << "Введите константное значение: ";
            std::cin >> constant_value;
            generator = std::make_unique<ConstantGenerator>(constant_value);
            std::cout << "Используется константный генератор" << std::endl;
            break;

        default:
            generator = std::make_unique<RandomGenerator>();
            std::cout << "Неверный выбор, используется случайный генератор" << std::endl;
            break;
        }

        Variant7 variant(8, generator.get());

        std::cout << "\nИсходный массив: ";
        variant.print_all();

        std::cout << "\nЗадание 1" << std::endl;
        std::cout << "Замена максимального элемента на противоположный" << std::endl;
        Matrix result1 = variant.execute_task1();
        std::cout << "Результат: " << result1 << std::endl;

        std::cout << "\nЗадание 2" << std::endl;
        std::cout << "Вставка максимального элемента после чисел с цифрой 1" << std::endl;
        Matrix result2 = variant.execute_task2();
        std::cout << "Результат: " << result2 << std::endl;

        std::cout << "\nЗадание 3" << std::endl;
        std::cout << "Создание нового массива по формуле A[i] = D[i] ± i" << std::endl;

        std::cout << "\nМассив D (случайные числа):" << std::endl;
        RandomGenerator random_gen;
        Matrix D1(5);
        D1.fill(random_gen);
        std::cout << "D1: " << D1 << std::endl;

        std::cout << "\nМассив D (нули):" << std::endl;
        ZeroGenerator zero_gen;
        Matrix D2(5);
        D2.fill(zero_gen);
        std::cout << "D2: " << D2 << std::endl;

        std::cout << "\nМассив D (константа 10):" << std::endl;
        ConstantGenerator const_gen(10);
        Matrix D3(5);
        D3.fill(const_gen);
        std::cout << "D3: " << D3 << std::endl;

        std::cout << "\nРезультаты Task3:" << std::endl;
        Matrix A1 = variant.execute_task3(D1);
        std::cout << "Для D1: " << A1 << std::endl;

        Matrix A2 = variant.execute_task3(D2);
        std::cout << "Для D2: " << A2 << std::endl;

        Matrix A3 = variant.execute_task3(D3);
        std::cout << "Для D3: " << A3 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}