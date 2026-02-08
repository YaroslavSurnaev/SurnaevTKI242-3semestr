#include "Cake.h"

namespace ConfectioneryFactory {
    Cake::Cake(const std::string& name, double price, int quantity,
        const std::string& flavor, int layers, bool hasFrosting)
        : Product(name, price, quantity, "Cakes"),
        flavor(flavor), layers(layers), hasFrosting(hasFrosting) {
    }

    std::string Cake::getFlavor() const { return flavor; }
    int Cake::getLayers() const { return layers; }
    bool Cake::getHasFrosting() const { return hasFrosting; }

    bool Cake::hasFlavorLayersFrosting(const std::string& checkFlavor,
        int checkLayers,
        bool checkFrosting) const {
        if (quantity == 0) return false;

        bool flavorOk = checkFlavor.empty() || flavor == checkFlavor;
        bool layersOk = (checkLayers == -1) || layers == checkLayers;
        bool frostingOk = !checkFrosting || hasFrosting;

        return flavorOk && layersOk && frostingOk;
    }

    std::string Cake::getDescription() const {
        return "Cake: " + name + ", Flavor: " + flavor +
            ", Layers: " + std::to_string(layers) +
            ", Frosting: " + (hasFrosting ? "Yes" : "No") +
            ", Price: " + std::to_string(price) + " RUB";
    }
}