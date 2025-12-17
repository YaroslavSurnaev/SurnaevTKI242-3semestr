#include "Matrix.h"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

namespace algebra
{
    Matrix::Matrix() : data(nullptr), size(0) {}

    Matrix::Matrix(size_t arr_size) : size(arr_size)
    {
        data = std::make_unique<int[]>(size);
        std::fill(data.get(), data.get() + size, 0);
    }

    Matrix::Matrix(const Matrix& other) : size(other.size)
    {
        data = std::make_unique<int[]>(size);
        std::copy(other.data.get(), other.data.get() + size, data.get());
    }

    Matrix::Matrix(Matrix&& other) noexcept
        : data(std::move(other.data)), size(other.size)
    {
        other.size = 0;
    }

    Matrix& Matrix::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            data = std::make_unique<int[]>(other.size);
            size = other.size;
            std::copy(other.data.get(), other.data.get() + size, data.get());
        }
        return *this;
    }

    Matrix& Matrix::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            data = std::move(other.data);
            size = other.size;
            other.size = 0;
        }
        return *this;
    }

    int& Matrix::operator[](size_t index)
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const int& Matrix::operator[](size_t index) const
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t Matrix::get_size() const
    {
        return size;
    }

    std::string Matrix::to_string() const
    {
        std::stringstream ss;
        ss << "[";
        for (size_t i = 0; i < size; i++)
        {
            ss << data[i];
            if (i < size - 1) ss << ", ";
        }
        ss << "]";
        return ss.str();
    }

    void Matrix::fill(Generator& generator)
    {
        for (size_t i = 0; i < size; i++)
        {
            data[i] = generator.generate();
        }
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        os << matrix.to_string();
        return os;
    }
}