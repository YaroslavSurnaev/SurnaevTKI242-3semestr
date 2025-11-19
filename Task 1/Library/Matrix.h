#pragma once
#include <string>
#include "Generator.h"

namespace algebra
{
    class Matrix
    {
    private:
        int* data;
        size_t size;

    public:
        Matrix();
        Matrix(size_t size);
        Matrix(const Matrix& other);
        ~Matrix();

        Matrix& operator=(const Matrix& other);
        int& operator[](size_t index);
        const int& operator[](size_t index) const;

        size_t get_size() const;
        std::string to_string() const;
        void fill_with(Generator& generator);
    };
}