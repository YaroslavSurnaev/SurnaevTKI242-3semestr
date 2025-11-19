#include "Matrix.h"
#include <sstream>
#include <stdexcept>

namespace algebra
{
    Matrix::Matrix() : data(nullptr), size(0) {}

    Matrix::Matrix(size_t arr_size) : size(arr_size)
    {
        data = new int[size] {};
    }

    Matrix::Matrix(const Matrix& other) : size(other.size)
    {
        data = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    Matrix::~Matrix()
    {
        delete[] data;
    }

    Matrix& Matrix::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
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

    void Matrix::fill_with(Generator& generator)
    {
        for (size_t i = 0; i < size; i++)
        {
            data[i] = generator.generate();
        }
    }
}