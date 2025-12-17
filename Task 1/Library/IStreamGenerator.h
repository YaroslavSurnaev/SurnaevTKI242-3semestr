#pragma once
#include "Generator.h"
#include <iostream>

namespace algebra
{
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        explicit IStreamGenerator(std::istream& input_stream = std::cin);
        IStreamGenerator(const IStreamGenerator&) = delete;
        IStreamGenerator& operator=(const IStreamGenerator&) = delete;
        IStreamGenerator(IStreamGenerator&&) noexcept = default;
        IStreamGenerator& operator=(IStreamGenerator&&) noexcept = default;

        int generate() override;
    };
}