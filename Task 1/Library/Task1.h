#pragma once
#include "Exercise.h"

namespace algebra
{
    class Task1 : public Exercise
    {
    public:
        using Exercise::Exercise;

        void Task1() override;

    private:
        size_t find_max_index() const;
    };
}
