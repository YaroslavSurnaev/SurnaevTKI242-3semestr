#pragma once
#include "Product.h"
#include <string>

namespace ConfectioneryFactory {
    class Cake : public Product {
    private:
        std::string flavor;
        int layers;
        bool hasFrosting;

    public:
        Cake(const std::string& name, double price, int quantity,
            const std::string& flavor, int layers, bool hasFrosting);

        std::string getFlavor() const;
        int getLayers() const;
        bool getHasFrosting() const;

        bool hasFlavorLayersFrosting(const std::string& checkFlavor,
            int checkLayers,
            bool checkFrosting) const;

        std::string getDescription() const override;
    };
}