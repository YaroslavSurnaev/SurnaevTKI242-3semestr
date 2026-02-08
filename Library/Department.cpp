#include "Department.h"
#include <algorithm>

namespace ConfectioneryFactory {
    Department::Department(const std::string& name) : name(name) {}

    std::string Department::getName() const { return name; }

    void Department::addProduct(std::unique_ptr<Product> product) {
        products.push_back(std::move(product));
    }

    std::vector<Product*> Department::findProduct(const std::string& productName) const {
        std::vector<Product*> result;
        for (const auto& product : products) {
            if (product->getName().find(productName) != std::string::npos) {
                result.push_back(product.get());
            }
        }
        return result;
    }

    double Department::getTotalValue() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product->getPrice() * product->getQuantity();
        }
        return total;
    }

    std::vector<std::string> Department::getAllProducts() const {
        std::vector<std::string> list;
        for (const auto& product : products) {
            list.push_back(product->getDescription());
        }
        return list;
    }
}