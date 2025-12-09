#pragma once
#include "Product.h"
#include <vector>
using namespace std;

class Supplier {
    string name;
    vector<Product*> products;
public:
    Supplier(string n = "");
    void addProduct(Product* p);
    void showProducts() const;
    string getName() const { return name; }
    const vector<Product*>& getProducts() const { return products; }
};