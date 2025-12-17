#pragma once
#include "Generator.h"

namespace algebra
{
    class ConstantGenerator : public Generator
    {
    private:
        const int value;

    public:
        explicit ConstantGenerator(int constant_value);
        ConstantGenerator(const ConstantGenerator&) = delete;
        ConstantGenerator& operator=(const ConstantGenerator&) = delete;
        ConstantGenerator(ConstantGenerator&&) noexcept = default;
        ConstantGenerator& operator=(ConstantGenerator&&) noexcept = default;

        int generate() override;
    };
}
