#pragma once
#include "Product.h"
#include <vector>
using namespace std;

class Store {
    string name;
    vector<Product*> orders;
public:
    Store(string n = "");
    void addOrder(Product* p);
    bool hasProduct(const string& productName) const;
    void showOrders() const;
    string getName() const { return name; }
};