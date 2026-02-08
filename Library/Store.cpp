#include "Store.h"
#include <algorithm>
#include "Cake.h"
#include "Cookie.h"
#include "Chocolate.h"

namespace ConfectioneryFactory {
    Store::Store() {
        addDepartment(std::make_unique<Department>("Cakes"));
        addDepartment(std::make_unique<Department>("Cookies"));
        addDepartment(std::make_unique<Department>("Chocolates"));
        addDepartment(std::make_unique<Department>("Pastries"));
    }

    void Store::addDepartment(std::unique_ptr<Department> department) {
        departments.push_back(std::move(department));
    }

    Department* Store::getDepartment(const std::string& name) const {
        for (const auto& dept : departments) {
            if (dept->getName() == name) {
                return dept.get();
            }
        }
        return nullptr;
    }

    std::pair<Product*, Department*> Store::findProductDepartment(const std::string& productName) const {
        for (const auto& department : departments) {
            auto products = department->findProduct(productName);
            if (!products.empty()) {
                return { products[0], department.get() };
            }
        }
        return { nullptr, nullptr };
    }

    std::vector<std::string> Store::getDepartmentProducts(const std::string& departmentName) const {
        auto* dept = getDepartment(departmentName);
        if (dept) {
            return dept->getAllProducts();
        }
        return {};
    }

    double Store::getDepartmentSales(const std::string& departmentName) const {
        auto it = sales.find(departmentName);
        if (it != sales.end()) {
            return it->second;
        }
        return 0.0;
    }

    double Store::calculatePurchase(const std::vector<std::pair<Product*, int>>& items,
        bool isWholesaleCustomer) const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.first->getPrice() * item.second;
        }

        double finalTotal = 0.0;
        for (const auto& item : items) {
            double priceWithDiscount = item.first->getDiscountPrice(total, isWholesaleCustomer);
            finalTotal += priceWithDiscount * item.second;
        }
        return finalTotal;
    }

    bool Store::checkCake(const std::string& productName,
        const std::string& flavor,
        int layers,
        bool hasFrosting) const {
        auto result = findProductDepartment(productName);
        if (result.first && result.second && result.second->getName() == "Cakes") {
            auto* cake = dynamic_cast<Cake*>(result.first);
            if (cake) {
                return cake->hasFlavorLayersFrosting(flavor, layers, hasFrosting);
            }
        }
        return false;
    }

    bool Store::checkCookie(const std::string& productName,
        const std::string& shape,
        bool isGlazed) const {
        auto result = findProductDepartment(productName);
        if (result.first && result.second && result.second->getName() == "Cookies") {
            auto* cookie = dynamic_cast<Cookie*>(result.first);
            if (cookie) {
                return cookie->hasShapeGlaze(shape, isGlazed);
            }
        }
        return false;
    }

    bool Store::checkChocolate(const std::string& productName,
        const std::string& cocoaPercent,
        const std::string& filling) const {
        auto result = findProductDepartment(productName);
        if (result.first && result.second && result.second->getName() == "Chocolates") {
            auto* chocolate = dynamic_cast<Chocolate*>(result.first);
            if (chocolate) {
                return chocolate->hasCocoaFilling(cocoaPercent, filling);
            }
        }
        return false;
    }

    void Store::addSale(const std::string& departmentName, double amount) {
        sales[departmentName] += amount;
    }
}