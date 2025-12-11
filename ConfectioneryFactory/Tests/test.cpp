#include <gtest/gtest.h>
#include "Product.h"
#include "ConfectioneryItem.h"
#include "Store.h"
#include "Supplier.h"
#include "ProductionRecord.h"

TEST(ProductTest, PriceIsStoredCorrectly) {
    Product p("Шоколад", 50.0);
    EXPECT_DOUBLE_EQ(p.getPrice(), 50.0);
    EXPECT_EQ(p.getName(), "Шоколад");
}

TEST(ConfectioneryItemTest, FlavorAndPopularity) {
    ConfectioneryItem cake("Торт", 250.0, "клубника", 95);
    EXPECT_EQ(cake.getFlavor(), "клубника");
    EXPECT_EQ(cake.getPopularity(), 95);
    EXPECT_DOUBLE_EQ(cake.getPrice(), 250.0);
}

TEST(StoreTest, StoreOrdersProduct) {
    Store shop("Магазин 1");
    Product chocolate("Шоколад", 50.0);
    shop.addOrder(&chocolate);

    EXPECT_TRUE(shop.hasProduct("Шоколад"));
    EXPECT_FALSE(shop.hasProduct("Печенье"));
}

TEST(SupplierTest, SupplierProvidesProduct) {
    Supplier sup("Поставщик А");
    Product candies("Конфеты", 30.0);
    sup.addProduct(&candies);

    const auto& products = sup.getProducts();
    ASSERT_EQ(products.size(), 1);
    EXPECT_EQ(products[0]->getName(), "Конфеты");
}

TEST(ProductionRecordTest, TotalCostCalculation) {
    Product cake("Торт", 250.0);
    ProductionRecord record(&cake, 3);

    EXPECT_DOUBLE_EQ(record.getTotalCost(), 750.0);
}

TEST(PolymorphismTest, VirtualShowWorks) {
    Product* p1 = new Product("Обычный", 10.0);
    Product* p2 = new ConfectioneryItem("Торт", 250.0, "шоколад", 90);

    EXPECT_EQ(p1->getName(), "Обычный");
    EXPECT_EQ(p2->getName(), "Торт");
    EXPECT_DOUBLE_EQ(p2->getPrice(), 250.0);

    delete p1;
    delete p2;
}