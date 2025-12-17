#include <gtest/gtest.h>
#include "Cake.h"
#include "Cookie.h"
#include "IncomingInvoice.h"
#include "OutgoingInvoice.h"
#include "ProductionRecord.h"
#include "Store.h"
#include "Supplier.h"

TEST(CakeTest, InitializationAndShow) {
    Cake cake("Торт", 300.0, "шоколад", "круглый", 98);
    EXPECT_EQ(cake.getName(), "Торт");
    EXPECT_DOUBLE_EQ(cake.getPrice(), 300.0);
    EXPECT_EQ(cake.getFlavor(), "шоколад");
    EXPECT_EQ(cake.getPopularity(), 98);
}

TEST(CookieTest, Initialization) {
    Cookie cookie("Печенье", 45.0, "овсянка", true, 85);
    EXPECT_EQ(cookie.getName(), "Печенье");
    EXPECT_DOUBLE_EQ(cookie.getPrice(), 45.0);
    EXPECT_EQ(cookie.getFlavor(), "овсянка");
    EXPECT_EQ(cookie.getPopularity(), 85);
    EXPECT_TRUE(cookie.getIsGlazed());
}

TEST(IncomingInvoiceTest, TotalCostCalculation) {
    Cake cake("Торт", 300.0, "шоколад", "круглый", 98);
    IncomingInvoice invoice(&cake, 5, "Поставщик A");
    EXPECT_EQ(invoice.getQuantity(), 5);
    EXPECT_EQ(invoice.getSupplierName(), "Поставщик A");
    EXPECT_DOUBLE_EQ(invoice.getProduct()->getPrice() * 5, 1500.0);
}

TEST(OutgoingInvoiceTest, StoreNameAndQuantity) {
    Cookie cookie("Печенье", 40.0, "ваниль", false, 80);
    OutgoingInvoice invoice(&cookie, 10, "Магазин 1");
    EXPECT_EQ(invoice.getStoreName(), "Магазин 1");
    EXPECT_EQ(invoice.getQuantity(), 10);
    EXPECT_DOUBLE_EQ(invoice.getProduct()->getPrice() * 10, 400.0);
}

TEST(ProductionRecordTest, SingleItemCost) {
    Cookie cookie("Печенье", 40.0, "ваниль", false, 80);
    ProductionRecord record(&cookie);
    EXPECT_DOUBLE_EQ(record.getTotalCost(), 40.0);
}

TEST(SupplierTest, AddAndShowInvoices) {
    Cake cake("Торт", 250.0, "клубника", "квадратный", 90);
    Supplier sup("Поставщик X");
    sup.addIncomingInvoice(new IncomingInvoice(&cake, 3, "Поставщик X"));

    EXPECT_NO_THROW(sup.showInvoices());
}

TEST(StoreTest, AddOutgoingInvoice) {
    Cookie cookie("Печенье", 50.0, "шоколад", true, 90);
    Store shop("Магазин Y");
    shop.addOutgoingInvoice(new OutgoingInvoice(&cookie, 7, "Магазин Y"));
    EXPECT_NO_THROW(shop.showInvoices());
}

TEST(PolymorphismTest, VirtualShow) {
    Cake* cake = new Cake("Торт", 300.0, "шоколад", "круглый", 98);
    Cookie* cookie = new Cookie("Печенье", 45.0, "овсянка", true, 85);

    Product* p1 = cake;
    Product* p2 = cookie;

    EXPECT_EQ(p1->getName(), "Торт");
    EXPECT_EQ(p2->getName(), "Печенье");
    EXPECT_DOUBLE_EQ(p1->getPrice(), 300.0);
    EXPECT_DOUBLE_EQ(p2->getPrice(), 45.0);

    delete cake;
    delete cookie;
}