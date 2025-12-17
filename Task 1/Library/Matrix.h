#pragma once
#include <string>
#include <memory>
#include "Generator.h"

namespace algebra
{
    class Matrix
    {
    private:
        std::unique_ptr<int[]> data;
        size_t size;

    public:
        Matrix();
        explicit Matrix(size_t size);

        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;
        ~Matrix() = default;

        int& operator[](size_t index);
        const int& operator[](size_t index) const;

        size_t get_size() const;

        std::string to_string() const;
        void fill(Generator& generator);

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    };
}