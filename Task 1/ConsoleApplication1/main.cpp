#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Library/Matrix.h"
#include "../Library/ConstantGenerator.h"
#include "../Library/Task1.h"
#include "../Library/Task2.h"
#include "../Library/Task3.h"

int main()
{
    srand(time(0));

    std::cout << "Enter array size: ";
    size_t size;
    std::cin >> size;

    if (size <= 0)
    {
        std::cout << "Size must be greater than 0" << std::endl;
        return 1;
    }

    algebra::Matrix<int> array(size);
    algebra::Generator* generator = nullptr;

    enum FillMethod { MANUAL = 0, RANDOM = 1 };

    std::cout << "Choose fill method (" << MANUAL << " - manual, " << RANDOM << " - random):";
    int choice;
    std::cin >> choice;

    switch ((FillMethod)choice)
    {
    case MANUAL:
    {
        std::cout << "Enter " << size << " numbers:" << std::endl;
        algebra::ConstantGenerator manual_gen(algebra::MANUAL);
        array.fill(manual_gen);
        generator = new algebra::ConstantGenerator(algebra::MANUAL);
        break;
    }
    case RANDOM:
    {
        std::cout << "Enter min value: ";
        int min;
        std::cin >> min;

        std::cout << "Enter max value: ";
        int max;
        std::cin >> max;

        if (min > max)
        {
            std::cout << "Invalid range" << std::endl;
            return 1;
        }

        algebra::ConstantGenerator random_gen(algebra::RANDOM, min, max);
        array.fill(random_gen);
        generator = new algebra::ConstantGenerator(algebra::RANDOM, min, max);
        break;
    }
    default:
    {
        std::cout << "Invalid choice" << std::endl;
        return 1;
    }
    }

    std::cout << "Original array: " << array.to_string() << std::endl;

    algebra::Task1 task1(array, generator);
    task1.execute();

    algebra::Task2 task2(array, generator);
    task2.execute();

    algebra::Task3 task3(array, generator);
    task3.execute();

    delete generator;
    return 0;
}