#pragma once
#include "Product.h"
#include <ctime>
using namespace std;

class ProductionRecord {
    Product* product;
    time_t date;
public:
    ProductionRecord(Product* p);
    double getTotalCost() const;
    void show() const;
    Product* getProduct() const;
};