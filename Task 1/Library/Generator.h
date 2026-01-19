#pragma once

namespace algebra
{
    class Generator
    {
    public:
        Generator() {}
        virtual ~Generator() = default;
        virtual int generate() = 0;
    };
}