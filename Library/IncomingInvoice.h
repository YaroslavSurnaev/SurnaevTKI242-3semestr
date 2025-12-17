#pragma once
#include "Product.h"
#include <string>
using namespace std;

class IncomingInvoice {
    Product* product;
    int quantity;
    string supplierName;
    time_t date;
public:
    IncomingInvoice(Product* p, int q, const string& supName);
    void show() const;
    Product* getProduct() const;
    int getQuantity() const;
    string getSupplierName() const;
};