#include "CppUnitTest.h"
#include "..\Library\Matrix.h"
#include "..\Library\ConstantGenerator.h"
#include "..\Library\Task1.h"
#include "..\Library\Task2.h"
#include "..\Library\Task3.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace algebra;

namespace MatrixLibraryTests
{
    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(TestMatrixConstructor)
        {
            Matrix<int> matrix(5);
            Assert::AreEqual((size_t)5, matrix.size());
        }

        TEST_METHOD(TestMatrixAccess)
        {
            Matrix<int> matrix(3);
            matrix[0] = 10;
            matrix[1] = 20;
            matrix[2] = 30;

            Assert::AreEqual(10, matrix[0]);
            Assert::AreEqual(20, matrix[1]);
            Assert::AreEqual(30, matrix[2]);
        }
    };

    TEST_CLASS(Task1Tests)
    {
    public:
        TEST_METHOD(TestTask1Basic)
        {
            Matrix<int> matrix(5);
            matrix[0] = 5;
            matrix[1] = 10;
            matrix[2] = 3;
            matrix[3] = 15;
            matrix[4] = 7;

            ConstantGenerator generator(RANDOM, 1, 100);
            Task1 task(matrix, &generator);

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            task.execute();
            std::cout.rdbuf(old);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("Replaced element") != std::string::npos);
        }

        TEST_METHOD(TestTask1NegativeNumbers)
        {
            Matrix<int> matrix(4);
            matrix[0] = -10;
            matrix[1] = -5;
            matrix[2] = -20;
            matrix[3] = -3;

            ConstantGenerator generator(RANDOM, 1, 100);
            Task1 task(matrix, &generator);

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            task.execute();
            std::cout.rdbuf(old);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("Replaced element") != std::string::npos);
        }
    };

    TEST_CLASS(Task2Tests)
    {
    public:
        TEST_METHOD(TestTask2Basic)
        {
            Matrix<int> matrix(5);
            matrix[0] = 15;
            matrix[1] = 23;
            matrix[2] = 11;
            matrix[3] = 7;
            matrix[4] = 19;

            ConstantGenerator generator(RANDOM, 1, 100);
            Task2 task(matrix, &generator);

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            task.execute();
            std::cout.rdbuf(old);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("Task 2 result") != std::string::npos);
        }

        TEST_METHOD(TestTask2WithDigit1)
        {
            Matrix<int> matrix(4);
            matrix[0] = 10;
            matrix[1] = 21;
            matrix[2] = 31;
            matrix[3] = 40;

            ConstantGenerator generator(RANDOM, 1, 100);
            Task2 task(matrix, &generator);

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            task.execute();
            std::cout.rdbuf(old);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("Task 2 result") != std::string::npos);
        }
    };

    TEST_CLASS(Task3Tests)
    {
    public:
        TEST_METHOD(TestTask3Basic)
        {
            Matrix<int> matrix(12);
            for (int i = 0; i < 12; i++)
            {
                matrix[i] = (i + 1) * 10;
            }

            ConstantGenerator generator(RANDOM, 1, 100);
            Task3 task(matrix, &generator);

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            task.execute();
            std::cout.rdbuf(old);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("Task 3 result") != std::string::npos);
        }

        TEST_METHOD(TestTask3LessThan10)
        {
            Matrix<int> matrix(5);
            matrix[0] = 1;
            matrix[1] = 2;
            matrix[2] = 3;
            matrix[3] = 4;
            matrix[4] = 5;

            ConstantGenerator generator(RANDOM, 1, 100);
            Task3 task(matrix, &generator);

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
            task.execute();
            std::cout.rdbuf(old);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("Task 3 result") != std::string::npos);
        }
    };
}