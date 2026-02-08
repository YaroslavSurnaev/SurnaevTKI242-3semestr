#include <iostream>
#include <cassert>
#include <sstream>
#include "../Library/Product.h"
#include "../Library/Cake.h"
#include "../Library/Cookie.h"
#include "../Library/Chocolate.h"
#include "../Library/Department.h"
#include "../Library/Store.h"

class TestRunner {
public:
    void runAllTests() {
        testProduct();
        testCake();
        testCookie();
        testChocolate();
        testDepartment();
        testStore();
        std::cout << "All tests passed!" << std::endl;
    }

private:
    void testProduct() {
        std::cout << "Running Product tests..." << std::endl;

        ConfectioneryFactory::Product product("Test Cake", 500.0, 20, "Cakes");
        assert(product.getName() == "Test Cake");
        assert(product.getPrice() == 500.0);
        assert(product.getQuantity() == 20);
        assert(product.getDepartment() == "Cakes");

        bool exceptionThrown = false;
        try {
            ConfectioneryFactory::Product badProduct("Bad", -100.0, 5, "Cakes");
        }
        catch (const std::invalid_argument&) {
            exceptionThrown = true;
        }
        assert(exceptionThrown);

        double price1 = product.getDiscountPrice(5000.0, false);
        assert(price1 == 500.0); 

        double price2 = product.getDiscountPrice(5000.0, true);
        assert(price2 == 440.0); 

        double price3 = product.getDiscountPrice(12000.0, false);
        assert(price3 == 460.0); 

        double price4 = product.getDiscountPrice(12000.0, true);
        assert(price4 == 400.0); 

        product.setPrice(600.0);
        assert(product.getPrice() == 600.0);

        product.setQuantity(10);
        assert(product.getQuantity() == 10);

        std::string desc = product.getDescription();
        assert(desc.find("Test Cake") != std::string::npos);
        assert(desc.find("600") != std::string::npos);

        std::cout << "Product tests passed!" << std::endl;
    }

    void testCake() {
        std::cout << "Running Cake tests..." << std::endl;

        ConfectioneryFactory::Cake cake("Red Velvet", 1100.0, 8, "Vanilla-Cherry", 2, true);
        assert(cake.getName() == "Red Velvet");
        assert(cake.getPrice() == 1100.0);
        assert(cake.getQuantity() == 8);
        assert(cake.getDepartment() == "Cakes");
        assert(cake.getFlavor() == "Vanilla-Cherry");
        assert(cake.getLayers() == 2);
        assert(cake.getHasFrosting() == true);

        assert(cake.hasFlavorLayersFrosting("Vanilla-Cherry", 2, true) == true);
        assert(cake.hasFlavorLayersFrosting("Chocolate", 2, true) == false);
        assert(cake.hasFlavorLayersFrosting("", 2, true) == true); 
        assert(cake.hasFlavorLayersFrosting("Vanilla-Cherry", -1, true) == true); 
        assert(cake.hasFlavorLayersFrosting("Vanilla-Cherry", 2, false) == false);

        ConfectioneryFactory::Cake outOfStock("Carrot", 900.0, 0, "Carrot-Walnut", 2, false);
        assert(outOfStock.hasFlavorLayersFrosting("Carrot-Walnut", 2, false) == false);

        std::string desc = cake.getDescription();
        assert(desc.find("Red Velvet") != std::string::npos);
        assert(desc.find("Vanilla-Cherry") != std::string::npos);
        assert(desc.find("2") != std::string::npos);
        assert(desc.find("Yes") != std::string::npos);

        std::cout << "Cake tests passed!" << std::endl;
    }

    void testCookie() {
        std::cout << "Running Cookie tests..." << std::endl;

        ConfectioneryFactory::Cookie cookie("Almond", 80.0, 50, "Round", true);
        assert(cookie.getName() == "Almond");
        assert(cookie.getPrice() == 80.0);
        assert(cookie.getQuantity() == 50);
        assert(cookie.getDepartment() == "Cookies");
        assert(cookie.getShape() == "Round");
        assert(cookie.getIsGlazed() == true);

        assert(cookie.hasShapeGlaze("Round", true) == true);
        assert(cookie.hasShapeGlaze("Square", true) == false);
        assert(cookie.hasShapeGlaze("Round", false) == false);
        assert(cookie.hasShapeGlaze("", true) == true); 
        assert(cookie.hasShapeGlaze("Round", false) == false);

        ConfectioneryFactory::Cookie plain("Shortbread", 60.0, 0, "Star", false);
        assert(plain.hasShapeGlaze("Star", false) == false);

        std::string desc = cookie.getDescription();
        assert(desc.find("Almond") != std::string::npos);
        assert(desc.find("Round") != std::string::npos);
        assert(desc.find("Yes") != std::string::npos);

        std::cout << "Cookie tests passed!" << std::endl;
    }

    void testChocolate() {
        std::cout << "Running Chocolate tests..." << std::endl;

        ConfectioneryFactory::Chocolate chocolate("Dark Hazelnut", 280.0, 30, "70", "Hazelnut");
        assert(chocolate.getName() == "Dark Hazelnut");
        assert(chocolate.getPrice() == 280.0);
        assert(chocolate.getQuantity() == 30);
        assert(chocolate.getDepartment() == "Chocolates");
        assert(chocolate.getCocoaPercent() == "70");
        assert(chocolate.getFilling() == "Hazelnut");

        assert(chocolate.hasCocoaFilling("70", "Hazelnut") == true);
        assert(chocolate.hasCocoaFilling("85", "Hazelnut") == false);
        assert(chocolate.hasCocoaFilling("70", "") == true); 
        assert(chocolate.hasCocoaFilling("", "Hazelnut") == true); 
        assert(chocolate.hasCocoaFilling("70", "Caramel") == false);

        ConfectioneryFactory::Chocolate milk("Milk Caramel", 200.0, 0, "35", "Caramel");
        assert(milk.hasCocoaFilling("35", "Caramel") == false);

        std::string desc = chocolate.getDescription();
        assert(desc.find("Dark Hazelnut") != std::string::npos);
        assert(desc.find("70%") != std::string::npos);
        assert(desc.find("Hazelnut") != std::string::npos);

        std::cout << "Chocolate tests passed!" << std::endl;
    }

    void testDepartment() {
        std::cout << "Running Department tests..." << std::endl;

        ConfectioneryFactory::Department dept("Cakes");
        assert(dept.getName() == "Cakes");
        assert(dept.getAllProducts().empty());
        assert(dept.getTotalValue() == 0.0);

        auto cake1 = std::make_unique<ConfectioneryFactory::Cake>("Cheesecake", 950.0, 10, "Berry", 1, true);
        auto cake2 = std::make_unique<ConfectioneryFactory::Cake>("Napoleon", 850.0, 5, "Vanilla", 3, true);

        dept.addProduct(std::move(cake1));
        dept.addProduct(std::move(cake2));

        assert(dept.getAllProducts().size() == 2);
        assert(dept.getTotalValue() == 950.0 * 10 + 850.0 * 5);

        auto found1 = dept.findProduct("Cheesecake");
        assert(!found1.empty());
        assert(found1[0]->getName() == "Cheesecake");

        auto found2 = dept.findProduct("cake"); 
        assert(found2.size() == 2);

        auto notFound = dept.findProduct("Bread");
        assert(notFound.empty());

        std::cout << "Department tests passed!" << std::endl;
    }

    void testStore() {
        std::cout << "Running Store tests..." << std::endl;

        ConfectioneryFactory::Store factory;

        auto* cakesDept = factory.getDepartment("Cakes");
        assert(cakesDept != nullptr);
        assert(cakesDept->getName() == "Cakes");

        auto* notFoundDept = factory.getDepartment("Bakery");
        assert(notFoundDept == nullptr);

        auto cake = std::make_unique<ConfectioneryFactory::Cake>("Black Forest", 1200.0, 6, "Chocolate-Cherry", 3, true);
        cakesDept->addProduct(std::move(cake));

        auto result = factory.findProductDepartment("Forest");
        assert(result.first != nullptr);
        assert(result.second != nullptr);
        assert(result.first->getName() == "Black Forest");
        assert(result.second->getName() == "Cakes");

        auto notFoundResult = factory.findProductDepartment("Pie");
        assert(notFoundResult.first == nullptr);
        assert(notFoundResult.second == nullptr);

        auto products = factory.getDepartmentProducts("Cakes");
        assert(!products.empty());

        auto emptyProducts = factory.getDepartmentProducts("Pastries");
        assert(emptyProducts.empty());

        bool hasCake = factory.checkCake("Black Forest", "Chocolate-Cherry", 3, true);
        assert(hasCake == true);

        bool wrongFlavor = factory.checkCake("Black Forest", "Vanilla", 3, true);
        assert(wrongFlavor == false);

        bool wrongLayers = factory.checkCake("Black Forest", "Chocolate-Cherry", 2, true);
        assert(wrongLayers == false);

        bool notCake = factory.checkCake("Nonexistent", "Chocolate", 3, true);
        assert(notCake == false);

        auto* cookiesDept = factory.getDepartment("Cookies");
        auto cookie = std::make_unique<ConfectioneryFactory::Cookie>("Oatmeal", 75.0, 40, "Round", true);
        cookiesDept->addProduct(std::move(cookie));

        bool hasCookie = factory.checkCookie("Oatmeal", "Round", true);
        assert(hasCookie == true);

        bool wrongShape = factory.checkCookie("Oatmeal", "Square", true);
        assert(wrongShape == false);

        auto* chocolatesDept = factory.getDepartment("Chocolates");
        auto chocolate = std::make_unique<ConfectioneryFactory::Chocolate>("Milk", 180.0, 25, "35", "Caramel");
        chocolatesDept->addProduct(std::move(chocolate));

        bool hasChocolate = factory.checkChocolate("Milk", "35", "Caramel");
        assert(hasChocolate == true);

        factory.addSale("Cakes", 7200.0);
        factory.addSale("Cakes", 2400.0);

        double sales = factory.getDepartmentSales("Cakes");
        assert(sales == 9600.0);

        double noSales = factory.getDepartmentSales("Hygiene");
        assert(noSales == 0.0);

        std::vector<std::pair<ConfectioneryFactory::Product*, int>> purchase;
        auto foundCakes = cakesDept->findProduct("Black Forest");
        if (!foundCakes.empty()) {
            purchase.push_back({ foundCakes[0], 2 });
        }

        double regularPrice = factory.calculatePurchase(purchase, false);
        assert(regularPrice > 0);

        double wholesalePrice = factory.calculatePurchase(purchase, true);
        assert(wholesalePrice < regularPrice);

        std::cout << "Store tests passed!" << std::endl;
    }
};

int main() {
    try {
        TestRunner runner;
        runner.runAllTests();
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}