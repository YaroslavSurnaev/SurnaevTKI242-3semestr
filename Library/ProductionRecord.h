#pragma once
#include "Product.h"
#include <ctime>
using namespace std;

class ProductionRecord {
    Product* product;
    int quantity;
    time_t date; // простая дата
public:
    ProductionRecord(Product* p, int q);
    double getTotalCost() const;
    void show() const;
    time_t getDate() const { return date; }
    Product* getProduct() const { return product; }
};