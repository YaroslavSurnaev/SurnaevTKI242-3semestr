#pragma once
#include "Product.h"
#include <string>

namespace ConfectioneryFactory {
    class Cookie : public Product {
    private:
        std::string shape;
        bool isGlazed;

    public:
        Cookie(const std::string& name, double price, int quantity,
            const std::string& shape, bool isGlazed);

        std::string getShape() const;
        bool getIsGlazed() const;

        bool hasShapeGlaze(const std::string& checkShape, bool checkGlaze) const;

        std::string getDescription() const override;
    };
}