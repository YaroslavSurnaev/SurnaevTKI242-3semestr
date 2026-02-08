#include "Cookie.h"

namespace ConfectioneryFactory {
    Cookie::Cookie(const std::string& name, double price, int quantity,
        const std::string& shape, bool isGlazed)
        : Product(name, price, quantity, "Cookies"),
        shape(shape), isGlazed(isGlazed) {
    }

    std::string Cookie::getShape() const { return shape; }
    bool Cookie::getIsGlazed() const { return isGlazed; }

    bool Cookie::hasShapeGlaze(const std::string& checkShape, bool checkGlaze) const {
        if (quantity == 0) return false;

        bool shapeOk = checkShape.empty() || shape == checkShape;
        bool glazeOk = !checkGlaze || isGlazed;

        return shapeOk && glazeOk;
    }

    std::string Cookie::getDescription() const {
        return "Cookie: " + name + ", Shape: " + shape +
            ", Glazed: " + (isGlazed ? "Yes" : "No") +
            ", Price: " + std::to_string(price) + " RUB";
    }
}