#pragma once
#include "Product.h"
#include <string>
using namespace std;

class OutgoingInvoice {
    Product* product;
    int quantity;
    string storeName;
    time_t date;
public:
    OutgoingInvoice(Product* p, int q, const string& storeName);
    void show() const;
    Product* getProduct() const;
    int getQuantity() const;
    string getStoreName() const;
};