#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixLib/Variant7.h"
#include "../MatrixLib/Matrix.h"
#include "../MatrixLib/RandomGenerator.h"
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace MatrixLibTests
{
    // “естовый генератор с фиксированными значени€ми
    class TestGenerator : public Generator
    {
    private:
        std::vector<int> values;
        size_t current;

    public:
        TestGenerator(std::initializer_list<int> init) : values(init), current(0) {}

        int generate() override
        {
            if (current >= values.size())
                current = 0;
            return values[current++];
        }
    };

    TEST_CLASS(Task1Test)
    {
    public:
        TEST_METHOD(ReplacesMaxElementWithOpposite)
        {
            TestGenerator* gen = new TestGenerator({ 10, 5, 20, 15 });
            Variant7Task1 task1(4, gen);

            task1.Task();
            Matrix result = task1.get_matrix();

            bool found = false;
            for (size_t i = 0; i < result.get_size(); i++)
            {
                if (result[i] == -20)
                {
                    found = true;
                    break;
                }
            }
            Assert::IsTrue(found);
        }

        TEST_METHOD(SingleElementArray)
        {
            TestGenerator* gen = new TestGenerator({ 8 });
            Variant7Task1 task1(1, gen);

            task1.Task();
            Assert::AreEqual(-8, task1.get_matrix()[0]);
        }

        TEST_METHOD(AllNegativeElements)
        {
            TestGenerator* gen = new TestGenerator({ -5, -10, -3 });
            Variant7Task1 task1(3, gen);

            task1.Task();
            bool found = false;
            for (size_t i = 0; i < task1.get_matrix().get_size(); i++)
            {
                if (task1.get_matrix()[i] == 3)
                {
                    found = true;
                    break;
                }
            }
            Assert::IsTrue(found);
        }
    };

    TEST_CLASS(Task2Test)
    {
    public:
        TEST_METHOD(InsertsMaxAfterElementsWithDigit1)
        {
            TestGenerator* gen = new TestGenerator({ 15, 21, 30, 41 });
            Variant7Task2 task2(4, gen);

            task2.Task();
            Matrix result = task2.get_matrix();

            Assert::AreEqual((size_t)6, result.get_size());
            Assert::AreEqual(15, result[0]);
            Assert::AreEqual(21, result[1]);
            Assert::AreEqual(41, result[2]);
            Assert::AreEqual(30, result[3]);
            Assert::AreEqual(41, result[4]);
            Assert::AreEqual(41, result[5]);
        }

        TEST_METHOD(NoElementsWithDigit1)
        {
            TestGenerator* gen = new TestGenerator({ 25, 30, 45 });
            Variant7Task2 task2(3, gen);

            task2.Task();
            Matrix result = task2.get_matrix();

            Assert::AreEqual((size_t)3, result.get_size());
        }

        TEST_METHOD(AllElementsWithDigit1)
        {
            TestGenerator* gen = new TestGenerator({ 1, 11, 111 });
            Variant7Task2 task2(3, gen);

            task2.Task();
            Matrix result = task2.get_matrix();

            Assert::AreEqual((size_t)6, result.get_size());
        }

        TEST_METHOD(ContainsDigit1Method)
        {
            TestGenerator* gen = new TestGenerator({ 0 });
            Variant7Task2 task2(1, gen);

            Assert::IsTrue(task2.contains_digit_1(1));
            Assert::IsTrue(task2.contains_digit_1(10));
            Assert::IsTrue(task2.contains_digit_1(21));
            Assert::IsTrue(task2.contains_digit_1(1001));
            Assert::IsTrue(task2.contains_digit_1(-15));
            Assert::IsFalse(task2.contains_digit_1(2));
            Assert::IsFalse(task2.contains_digit_1(200));
            Assert::IsFalse(task2.contains_digit_1(0));
        }
    };

    TEST_CLASS(Task3Test)
    {
    public:
        TEST_METHOD(CreatesArrayByRule)
        {
            Variant7Task3 task3;

            Matrix D(4);
            D[0] = 5;
            D[1] = 10;
            D[2] = 15;
            D[3] = 20;

            Matrix A = task3.execute(D);

            Assert::AreEqual(5 + 0, A[0]);
            Assert::AreEqual(10 - 1, A[1]);
            Assert::AreEqual(15 + 2, A[2]);
            Assert::AreEqual(20 - 3, A[3]);
        }

        TEST_METHOD(EmptyArray)
        {
            Variant7Task3 task3;
            Matrix empty(0);

            Matrix result = task3.execute(empty);
            Assert::AreEqual((size_t)0, result.get_size());
        }

        TEST_METHOD(SingleElement)
        {
            Variant7Task3 task3;

            Matrix D(1);
            D[0] = 100;

            Matrix A = task3.execute(D);
            Assert::AreEqual(100 + 0, A[0]);
        }
    };

    TEST_CLASS(MatrixTest)
    {
    public:
        TEST_METHOD(BasicOperations)
        {
            Matrix mat(3);
            Assert::AreEqual((size_t)3, mat.get_size());

            mat[0] = 10;
            mat[1] = 20;
            mat[2] = 30;

            Assert::AreEqual(10, mat[0]);
            Assert::AreEqual(20, mat[1]);
            Assert::AreEqual(30, mat[2]);
        }

        TEST_METHOD(CopyConstructor)
        {
            Matrix original(2);
            original[0] = 5;
            original[1] = 10;

            Matrix copy(original);
            Assert::AreEqual((size_t)2, copy.get_size());
            Assert::AreEqual(5, copy[0]);
            Assert::AreEqual(10, copy[1]);
        }

        TEST_METHOD(AssignmentOperator)
        {
            Matrix original(2);
            original[0] = 5;
            original[1] = 10;

            Matrix assigned(1);
            assigned = original;
            Assert::AreEqual((size_t)2, assigned.get_size());
            Assert::AreEqual(5, assigned[0]);
            Assert::AreEqual(10, assigned[1]);
        }

        TEST_METHOD(ToString)
        {
            Matrix mat(3);
            mat[0] = 1;
            mat[1] = 2;
            mat[2] = 3;

            std::string expected = "[1, 2, 3]";
            Assert::AreEqual(expected, mat.to_string());
        }

        TEST_METHOD(FillWithGenerator)
        {
            TestGenerator* gen = new TestGenerator({ 7, 8, 9 });
            Matrix mat(3);

            mat.fill_with(*gen);

            Assert::AreEqual(7, mat[0]);
            Assert::AreEqual(8, mat[1]);
            Assert::AreEqual(9, mat[2]);
        }
    };

    TEST_CLASS(GeneratorTest)
    {
    public:
        TEST_METHOD(RandomGeneratorRange)
        {
            RandomGenerator gen;

            for (int i = 0; i < 100; i++)
            {
                int value = gen.generate();
                Assert::IsTrue(value >= -1000 && value <= 1000);
            }
        }
    };
}