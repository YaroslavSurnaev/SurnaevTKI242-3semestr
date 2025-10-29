#include <gtest/gtest.h>
#include "../MatrixLib/Variant7.h"

using namespace miit::algebra;

class TestGenerator : public Generator
{
private:
    int value;
public:
    TestGenerator(int val) : value(val) {}
    int generate() override { return value; }
};

TEST(MatrixTest, BasicOperations)
{
    Matrix<int> mat(5);
    EXPECT_EQ(mat.get_size(), 5);
}

TEST(Variant7Test, Task1ReplacesMaxElement)
{
    TestGenerator* gen = new TestGenerator(5);
    Variant7 exercise(3, gen);

    // Устанавливаем конкретные значения
    exercise.get_matrix()[0] = 1;
    exercise.get_matrix()[1] = 10; // максимальный
    exercise.get_matrix()[2] = 3;

    exercise.Task1();

    EXPECT_EQ(exercise.get_matrix()[1], -10); // должен быть заменен на -10
}

TEST(Variant7Test, ContainsDigit1)
{
    Variant7 exercise(1, new TestGenerator(0));

    EXPECT_TRUE(exercise.contains_digit_1(1));
    EXPECT_TRUE(exercise.contains_digit_1(10));
    EXPECT_TRUE(exercise.contains_digit_1(21));
    EXPECT_TRUE(exercise.contains_digit_1(1001));
    EXPECT_FALSE(exercise.contains_digit_1(2));
    EXPECT_FALSE(exercise.contains_digit_1(200));
}