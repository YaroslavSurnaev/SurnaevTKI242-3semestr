#include "Chocolate.h"

namespace ConfectioneryFactory {
    Chocolate::Chocolate(const std::string& name, double price, int quantity,
        const std::string& cocoaPercent, const std::string& filling)
        : Product(name, price, quantity, "Chocolates"),
        cocoaPercent(cocoaPercent), filling(filling) {
    }

    std::string Chocolate::getCocoaPercent() const { return cocoaPercent; }
    std::string Chocolate::getFilling() const { return filling; }

    bool Chocolate::hasCocoaFilling(const std::string& checkCocoa, const std::string& checkFilling) const {
        if (quantity == 0) return false;

        bool cocoaOk = checkCocoa.empty() || cocoaPercent == checkCocoa;
        bool fillingOk = checkFilling.empty() || filling == checkFilling;

        return cocoaOk && fillingOk;
    }

    std::string Chocolate::getDescription() const {
        return "Chocolate: " + name + ", Cocoa: " + cocoaPercent + "%" +
            (filling.empty() ? "" : ", Filling: " + filling) +
            ", Price: " + std::to_string(price) + " RUB";
    }
}