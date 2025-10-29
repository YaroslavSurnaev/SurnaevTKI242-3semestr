#include "pch.h"
#include "Matrix.h"
#include <sstream>
#include <stdexcept>

namespace miit::algebra
{
    template<typename T>
    Matrix<T>::Matrix() : data(nullptr), size(0) {}

    template<typename T>
    Matrix<T>::Matrix(size_t size) : size(size)
    {
        data = new T[size]{};
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) : size(other.size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    template<typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }

    template<typename T>
    Matrix<T>::~Matrix()
    {
        delete[] data;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator<<(int shift) const
    {
        Matrix result(size);
        for (size_t i = 0; i < size; i++)
        {
            size_t new_index = (i + shift) % size;
            result.data[new_index] = data[i];
        }
        return result;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator>>(int shift) const
    {
        Matrix result(size);
        for (size_t i = 0; i < size; i++)
        {
            size_t new_index = (i - shift + size) % size;
            result.data[new_index] = data[i];
        }
        return result;
    }

    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template<typename T>
    size_t Matrix<T>::get_size() const
    {
        return size;
    }

    template<typename T>
    std::string Matrix<T>::to_string() const
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

    template<typename T>
    void Matrix<T>::fill_with(Generator& generator)
    {
        for (size_t i = 0; i < size; i++)
        {
            data[i] = static_cast<T>(generator.generate());
        }
    }

    template<typename T>
    void Matrix<T>::resize(size_t new_size)
    {
        T* new_data = new T[new_size]{};
        size_t min_size = (size < new_size) ? size : new_size;

        for (size_t i = 0; i < min_size; i++)
        {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        size = new_size;
    }

    // явное инстанцирование дл€ int
    template class Matrix<int>;
}