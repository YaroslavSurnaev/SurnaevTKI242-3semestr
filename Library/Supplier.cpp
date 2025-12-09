#include "Supplier.h"
#include <iostream>
using namespace std;

Supplier::Supplier(string n) : name(n) {}

void Supplier::addProduct(Product* p) {
    products.push_back(p);
}

void Supplier::showProducts() const {
    cout << "Поставщик " << name << " поставляет:" << endl;
    for (Product* p : products) {
        cout << "  - ";
        p->show();
    }
}