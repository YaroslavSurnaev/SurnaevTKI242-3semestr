#pragma once
#include "Product.h"
#include <string>

namespace ConfectioneryFactory {
    class Chocolate : public Product {
    private:
        std::string cocoaPercent;
        std::string filling;

    public:
        Chocolate(const std::string& name, double price, int quantity,
            const std::string& cocoaPercent, const std::string& filling = "");

        std::string getCocoaPercent() const;
        std::string getFilling() const;

        bool hasCocoaFilling(const std::string& checkCocoa, const std::string& checkFilling) const;

        std::string getDescription() const override;
    };
}