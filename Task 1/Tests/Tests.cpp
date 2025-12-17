#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixLib/Matrix.h"
#include "../MatrixLib/RandomGenerator.h"
#include "../MatrixLib/IStreamGenerator.h"
#include "../MatrixLib/ConstantGenerator.h"
#include "../MatrixLib/ZeroGenerator.h"
#include "../MatrixLib/Task1.h"
#include "../MatrixLib/Task2.h"
#include "../MatrixLib/Task3.h"
#include "../MatrixLib/Variant7.h"
#include <sstream>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace algebra;

namespace MatrixLibTests
{
    class TestGenerator : public Generator
    {
    private:
        std::vector<int> values;
        size_t index;

    public:
        TestGenerator(std::initializer_list<int> init) : values(init), index(0) {}

        int generate() override
        {
            if (index >= values.size()) index = 0;
            return values[index++];
        }
    };

    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(DefaultConstructorCreatesEmptyMatrix)
        {
            Matrix mat;
            Assert::AreEqual((size_t)0, mat.get_size());
        }

        TEST_METHOD(ParameterizedConstructorCreatesMatrixWithSize)
        {
            Matrix mat(5);
            Assert::AreEqual((size_t)5, mat.get_size());
        }

        TEST_METHOD(MatrixInitializedWithZeros)
        {
            Matrix mat(3);
            Assert::AreEqual(0, mat[0]);
            Assert::AreEqual(0, mat[1]);
            Assert::AreEqual(0, mat[2]);
        }

        TEST_METHOD(MatrixElementAssignment)
        {
            Matrix mat(3);
            mat[0] = 10;
            mat[1] = 20;
            mat[2] = 30;

            Assert::AreEqual(10, mat[0]);
            Assert::AreEqual(20, mat[1]);
            Assert::AreEqual(30, mat[2]);
        }

        TEST_METHOD(MatrixCopyConstructor)
        {
            Matrix original(2);
            original[0] = 5;
            original[1] = 10;

            Matrix copy(original);

            Assert::AreEqual((size_t)2, copy.get_size());
            Assert::AreEqual(5, copy[0]);
            Assert::AreEqual(10, copy[1]);
        }

        TEST_METHOD(MatrixMoveConstructor)
        {
            Matrix original(2);
            original[0] = 5;
            original[1] = 10;

            Matrix moved(std::move(original));

            Assert::AreEqual((size_t)2, moved.get_size());
            Assert::AreEqual(5, moved[0]);
            Assert::AreEqual(10, moved[1]);
            Assert::AreEqual((size_t)0, original.get_size());
        }

        TEST_METHOD(MatrixAssignmentOperator)
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

        TEST_METHOD(MatrixToString)
        {
            Matrix mat(3);
            mat[0] = 1;
            mat[1] = 2;
            mat[2] = 3;

            std::string expected = "[1, 2, 3]";
            Assert::AreEqual(expected, mat.to_string());
        }

        TEST_METHOD(MatrixFillWithGenerator)
        {
            TestGenerator gen({ 7, 8, 9 });
            Matrix mat(3);

            mat.fill(gen);

            Assert::AreEqual(7, mat[0]);
            Assert::AreEqual(8, mat[1]);
            Assert::AreEqual(9, mat[2]);
        }

        TEST_METHOD(MatrixIndexOutOfRangeThrows)
        {
            Matrix mat(3);

            auto func = [&]() { mat[5]; };
            Assert::ExpectException<std::out_of_range>(func);
        }
    };

    TEST_CLASS(GeneratorTests)
    {
    public:
        TEST_METHOD(RandomGeneratorGeneratesInRange)
        {
            RandomGenerator gen;

            for (int i = 0; i < 100; i++)
            {
                int value = gen.generate();
                Assert::IsTrue(value >= -1000 && value <= 1000);
            }
        }

        TEST_METHOD(ConstantGeneratorAlwaysReturnsSameValue)
        {
            ConstantGenerator gen(42);

            for (int i = 0; i < 10; i++)
            {
                Assert::AreEqual(42, gen.generate());
            }
        }

        TEST_METHOD(ZeroGeneratorAlwaysReturnsZero)
        {
            ZeroGenerator gen;

            for (int i = 0; i < 10; i++)
            {
                Assert::AreEqual(0, gen.generate());
            }
        }

        TEST_METHOD(IStreamGeneratorReadsFromStream)
        {
            std::istringstream input("10 20 30");
            IStreamGenerator gen(input);

            Assert::AreEqual(10, gen.generate());
            Assert::AreEqual(20, gen.generate());
            Assert::AreEqual(30, gen.generate());
        }
    };

    TEST_CLASS(Task1Tests)
    {
    public:
        TEST_METHOD(Task1_ReplacesMaxElementWithOpposite)
        {
            TestGenerator* gen = new TestGenerator({ 10, 5, 20, 15 });
            Task1 task(4, gen);

            task.Task1();
            Matrix result = task.get();

            bool found_negative_20 = false;
            for (size_t i = 0; i < result.get_size(); i++)
            {
                if (result[i] == -20) found_negative_20 = true;
            }
            Assert::IsTrue(found_negative_20);
        }

        TEST_METHOD(Task1_SingleElementArray)
        {
            TestGenerator* gen = new TestGenerator({ 8 });
            Task1 task(1, gen);

            task.Task1();
            Assert::AreEqual(-8, task.get()[0]);
        }

        TEST_METHOD(Task1_AllNegativeElements)
        {
            TestGenerator* gen = new TestGenerator({ -5, -10, -3 });
            Task1 task(3, gen);

            task.Task1();
            bool found_positive_3 = false;
            for (size_t i = 0; i < task.get().get_size(); i++)
            {
                if (task.get()[i] == 3) found_positive_3 = true;
            }
            Assert::IsTrue(found_positive_3);
        }

        TEST_METHOD(Task1_EmptyArrayDoesNothing)
        {
            TestGenerator* gen = new TestGenerator({});
            Task1 task(0, gen);

            task.Task1();
            Assert::AreEqual((size_t)0, task.get().get_size());
        }

        TEST_METHOD(Task1_MultipleMaxElements)
        {
            TestGenerator* gen = new TestGenerator({ 5, 10, 10, 3 });
            Task1 task(4, gen);

            task.Task1();
            Matrix result = task.get();

            int negative_count = 0;
            for (size_t i = 0; i < result.get_size(); i++)
            {
                if (result[i] == -10) negative_count++;
            }
            Assert::AreEqual(1, negative_count);
        }
    };

    TEST_CLASS(Task2Tests)
    {
    public:
        TEST_METHOD(Task2_InsertsMaxAfterElementsWithDigit1)
        {
            TestGenerator* gen = new TestGenerator({ 15, 21, 30, 41 });
            Task2 task(4, gen);

            task.Task2();
            Matrix result = task.get();

            Assert::AreEqual((size_t)6, result.get_size());
            Assert::AreEqual(15, result[0]);
            Assert::AreEqual(21, result[1]);
            Assert::AreEqual(41, result[2]);
            Assert::AreEqual(30, result[3]);
            Assert::AreEqual(41, result[4]);
            Assert::AreEqual(41, result[5]);
        }

        TEST_METHOD(Task2_NoElementsWithDigit1)
        {
            TestGenerator* gen = new TestGenerator({ 25, 30, 45 });
            Task2 task(3, gen);

            task.Task2();
            Matrix result = task.get();

            Assert::AreEqual((size_t)3, result.get_size());
            Assert::AreEqual(25, result[0]);
            Assert::AreEqual(30, result[1]);
            Assert::AreEqual(45, result[2]);
        }

        TEST_METHOD(Task2_AllElementsWithDigit1)
        {
            TestGenerator* gen = new TestGenerator({ 1, 11, 111 });
            Task2 task(3, gen);

            task.Task2();
            Matrix result = task.get();

            Assert::AreEqual((size_t)6, result.get_size());
            Assert::AreEqual(1, result[0]);
            Assert::AreEqual(111, result[1]);
            Assert::AreEqual(11, result[2]);
            Assert::AreEqual(111, result[3]);
            Assert::AreEqual(111, result[4]);
            Assert::AreEqual(111, result[5]);
        }

        TEST_METHOD(Task2_ContainsDigit1Method)
        {
            TestGenerator* gen = new TestGenerator({ 0 });
            Task2 task(1, gen);

            Assert::IsTrue(task.contains_digit_1(1));
            Assert::IsTrue(task.contains_digit_1(10));
            Assert::IsTrue(task.contains_digit_1(21));
            Assert::IsTrue(task.contains_digit_1(1001));
            Assert::IsTrue(task.contains_digit_1(-15));
            Assert::IsFalse(task.contains_digit_1(2));
            Assert::IsFalse(task.contains_digit_1(200));
            Assert::IsFalse(task.contains_digit_1(0));
        }

        TEST_METHOD(Task2_EmptyArray)
        {
            TestGenerator* gen = new TestGenerator({});
            Task2 task(0, gen);

            task.Task2();
            Assert::AreEqual((size_t)0, task.get().get_size());
        }

        TEST_METHOD(Task2_FindMaxElementMethod)
        {
            TestGenerator* gen = new TestGenerator({ 5, 10, 3 });
            Task2 task(3, gen);

            task.Task2();
            Matrix result = task.get();
            bool found_10 = false;
            for (size_t i = 0; i < result.get_size(); i++)
            {
                if (result[i] == 10) found_10 = true;
            }
            Assert::IsTrue(found_10);
        }
    };

    TEST_CLASS(Task3Tests)
    {
    public:
        TEST_METHOD(Task3_CreatesArrayByRule)
        {
            Matrix D(4);
            D[0] = 5;
            D[1] = 10;
            D[2] = 15;
            D[3] = 20;

            TestGenerator* gen = new TestGenerator({ 0 });
            Task3 task(1, gen);

            Matrix A = task.Task3(D);

            Assert::AreEqual(5 + 0, A[0]);  
            Assert::AreEqual(10 - 1, A[1]); 
            Assert::AreEqual(15 + 2, A[2]);
            Assert::AreEqual(20 - 3, A[3]);
        }

        TEST_METHOD(Task3_EmptyArray)
        {
            Matrix empty(0);

            TestGenerator* gen = new TestGenerator({ 0 });
            Task3 task(1, gen);

            Matrix result = task.Task3(empty);
            Assert::AreEqual((size_t)0, result.get_size());
        }

        TEST_METHOD(Task3_SingleElement)
        {
            Matrix D(1);
            D[0] = 100;

            TestGenerator* gen = new TestGenerator({ 0 });
            Task3 task(1, gen);

            Matrix A = task.Task3(D);
            Assert::AreEqual(100 + 0, A[0]);
        }

        TEST_METHOD(Task3_NegativeValues)
        {
            Matrix D(3);
            D[0] = -5;
            D[1] = -10;
            D[2] = -15;

            TestGenerator* gen = new TestGenerator({ 0 });
            Task3 task(1, gen);

            Matrix A = task.Task3(D);

            Assert::AreEqual(-5 + 0, A[0]);
            Assert::AreEqual(-10 - 1, A[1]);
            Assert::AreEqual(-15 + 2, A[2]);
        }

        TEST_METHOD(Task3_CalculateValueMethodTest)
        {
            Matrix D(2);
            D[0] = 5;
            D[1] = 10;

            TestGenerator* gen = new TestGenerator({ 0 });
            Task3 task(1, gen);

            Matrix A = task.Task3(D);

            Assert::AreEqual(5 + 0, A[0]); 
            Assert::AreEqual(10 - 1, A[1]);
        }
    };

    TEST_CLASS(Variant7Tests)
    {
    public:
        TEST_METHOD(Variant7_ConstructorAndBasicMethods)
        {
            TestGenerator* gen = new TestGenerator({ 1, 2, 3, 4 });
            Variant7 variant(4, gen);

            Matrix original = variant.get_original();
            Assert::AreEqual((size_t)4, original.get_size());
        }

        TEST_METHOD(Variant7_ExecuteTask1)
        {
            TestGenerator* gen = new TestGenerator({ 10, 5, 20, 15 });
            Variant7 variant(4, gen);

            Matrix result = variant.execute_task1();

            bool found_negative_20 = false;
            for (size_t i = 0; i < result.get_size(); i++)
            {
                if (result[i] == -20) found_negative_20 = true;
            }
            Assert::IsTrue(found_negative_20);
        }

        TEST_METHOD(Variant7_ExecuteTask2)
        {
            TestGenerator* gen = new TestGenerator({ 15, 21, 30, 41 });
            Variant7 variant(4, gen);

            Matrix result = variant.execute_task2();

            Assert::AreEqual((size_t)6, result.get_size());
            Assert::AreEqual(15, result[0]);
            Assert::AreEqual(21, result[1]);
            Assert::AreEqual(41, result[2]);
            Assert::AreEqual(30, result[3]);
            Assert::AreEqual(41, result[4]);
            Assert::AreEqual(41, result[5]);
        }

        TEST_METHOD(Variant7_ExecuteTask3)
        {
            TestGenerator* gen = new TestGenerator({ 0 });
            Variant7 variant(1, gen);

            Matrix D(3);
            D[0] = 5;
            D[1] = 10;
            D[2] = 15;

            Matrix A = variant.execute_task3(D);

            Assert::AreEqual(5 + 0, A[0]);
            Assert::AreEqual(10 - 1, A[1]);
            Assert::AreEqual(15 + 2, A[2]);
        }

        TEST_METHOD(Variant7_PrintAllDoesNotThrow)
        {
            TestGenerator* gen = new TestGenerator({ 1, 2, 3 });
            Variant7 variant(3, gen);

            try
            {
                variant.print_all();
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail(L"print_all() threw an exception");
            }
        }

        TEST_METHOD(Variant7_WithDifferentGenerators)
        {
            ConstantGenerator* const_gen = new ConstantGenerator(5);
            Variant7 variant_const(3, const_gen);
            Assert::AreEqual((size_t)3, variant_const.get_original().get_size());

            ZeroGenerator* zero_gen = new ZeroGenerator();
            Variant7 variant_zero(3, zero_gen);
            Matrix zero_result = variant_zero.execute_task1();
            for (size_t i = 0; i < zero_result.get_size(); i++)
            {
                Assert::AreEqual(0, zero_result[i]);
            }
        }
    };

    TEST_CLASS(IntegrationTests)
    {
    public:
        TEST_METHOD(FullIntegrationTest)
        {
            TestGenerator* gen = new TestGenerator({ 10, 15, 21, 30, 41 });
            Variant7 variant(5, gen);

            Matrix result1 = variant.execute_task1();
            Assert::AreEqual((size_t)5, result1.get_size());

            Matrix result2 = variant.execute_task2();
            Assert::AreEqual((size_t)8, result2.get_size());

            Matrix D(3);
            D[0] = 1;
            D[1] = 2;
            D[2] = 3;

            Matrix result3 = variant.execute_task3(D);
            Assert::AreEqual((size_t)3, result3.get_size());
            Assert::AreEqual(1 + 0, result3[0]);
            Assert::AreEqual(2 - 1, result3[1]);
            Assert::AreEqual(3 + 2, result3[2]);
        }

        TEST_METHOD(ExerciseInheritanceTest)
        {
            TestGenerator* gen = new TestGenerator({ 1, 2, 3 });

            Task1 task1(3, gen);
            Task2 task2(3, new TestGenerator({ 1, 2, 3 }));
            Task3 task3(3, new TestGenerator({ 1, 2, 3 }));

            Assert::AreEqual((size_t)3, task1.get().get_size());
            Assert::AreEqual((size_t)3, task2.get().get_size());
            Assert::AreEqual((size_t)3, task3.get().get_size());

            task1.Task1();
            task2.Task2();

            Matrix D(2);
            D[0] = 1;
            D[1] = 2;
            Matrix result = task3.Task3(D);

            Assert::AreEqual((size_t)2, result.get_size());
        }
    };
}