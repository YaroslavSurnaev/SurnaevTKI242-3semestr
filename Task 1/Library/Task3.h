#pragma once
#include "Exercise.h"

namespace algebra
{
    class Task3 : public Exercise
    {
    public:
        using Exercise::Exercise;

        Matrix Task3(const Matrix& D) override;

    private:
        int calculate_value(int value, size_t index) const;
    };
}
