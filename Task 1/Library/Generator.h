#pragma once

namespace algebra
{
    class Generator
    {
    public:
        virtual ~Generator() = default;
        virtual int generate() = 0;
    };
}
