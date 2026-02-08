#pragma once
#include "Product.h"
#include <vector>
#include <memory>

namespace ConfectioneryFactory {
    class Department {
    private:
        std::string name;
        std::vector<std::unique_ptr<Product>> products;

    public:
        Department(const std::string& name);

        std::string getName() const;

        void addProduct(std::unique_ptr<Product> product);

        std::vector<Product*> findProduct(const std::string& productName) const;

        double getTotalValue() const;

        std::vector<std::string> getAllProducts() const;
    };
}