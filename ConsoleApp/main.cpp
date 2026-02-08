#include <iostream>
#include <vector>
#include <memory>
#include "..\Library\Product.h"
#include "..\Library\Cake.h"
#include "..\Library\Cookie.h"
#include "..\Library\Chocolate.h"
#include "..\Library\Store.h"

using namespace ConfectioneryFactory;

int main() {
    std::cout << "Confectionery Factory\n\n";

    Store factory;

    auto* cakesDept = factory.getDepartment("Cakes");
    auto* cookiesDept = factory.getDepartment("Cookies");
    auto* chocolatesDept = factory.getDepartment("Chocolates");

    cakesDept->addProduct(std::make_unique<Cake>("Black Forest", 1200, 8, "Chocolate-Cherry", 3, true));
    cakesDept->addProduct(std::make_unique<Cake>("Carrot Cake", 950, 12, "Carrot-Walnut", 2, true));

    cookiesDept->addProduct(std::make_unique<Cookie>("Oatmeal", 75, 50, "Round", true));
    cookiesDept->addProduct(std::make_unique<Cookie>("Shortbread", 60, 60, "Star", false));

    chocolatesDept->addProduct(std::make_unique<Chocolate>("Dark 70%", 250, 30, "70", "Hazelnut"));
    chocolatesDept->addProduct(std::make_unique<Chocolate>("Milk", 180, 40, "35", "Caramel"));

    std::cout << "Search product 'forest':\n";
    auto result = factory.findProductDepartment("forest");
    if (result.first && result.second) {
        std::cout << "Found: " << result.first->getName()
            << " in " << result.second->getName() << "\n";
    }
    std::cout << "\n";

    std::cout << "Cakes available:\n";
    auto cakesList = factory.getDepartmentProducts("Cakes");
    for (const auto& cake : cakesList) {
        std::cout << cake << "\n";
    }
    std::cout << "\n";

    factory.addSale("Cakes", 9600);
    factory.addSale("Cookies", 4500);
    std::cout << "Sales: Cakes = " << factory.getDepartmentSales("Cakes") << " RUB\n\n";

    std::vector<std::pair<Product*, int>> order;
    auto cakes = cakesDept->findProduct("Black Forest");
    if (!cakes.empty()) {
        order.push_back({ cakes[0], 2 });
    }

    std::cout << "Order cost:\n";
    std::cout << "Retail: " << factory.calculatePurchase(order, false) << " RUB\n";
    std::cout << "Wholesale: " << factory.calculatePurchase(order, true) << " RUB\n\n";

    std::cout << "Availability checks:\n";
    bool cakeAvail = factory.checkCake("Black Forest", "Chocolate-Cherry", 3, true);
    std::cout << "Black Forest (3 layers, frosting): " << (cakeAvail ? "Yes" : "No") << "\n";

    bool cookieAvail = factory.checkCookie("Oatmeal", "Round", true);
    std::cout << "Oatmeal cookie (round, glazed): " << (cookieAvail ? "Yes" : "No") << "\n";

    return 0;
}