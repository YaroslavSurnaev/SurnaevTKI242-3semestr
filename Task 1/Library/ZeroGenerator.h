#pragma once
#include "Generator.h"

namespace algebra
{
    class ZeroGenerator : public Generator
    {
    public:
        ZeroGenerator() = default;
        ZeroGenerator(const ZeroGenerator&) = delete;
        ZeroGenerator& operator=(const ZeroGenerator&) = delete;
        ZeroGenerator(ZeroGenerator&&) noexcept = default;
        ZeroGenerator& operator=(ZeroGenerator&&) noexcept = default;

        int generate() override;
    };
}