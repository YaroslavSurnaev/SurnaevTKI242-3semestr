#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(string n, double p) : name(n), price(p) {}

void Product::show() const {
    cout << "Товар: " << name << ", цена: " << price << " руб." << endl;
}