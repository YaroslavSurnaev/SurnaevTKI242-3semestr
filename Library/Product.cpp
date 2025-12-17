#include "Product.h"

Product::Product(string n, double p) : name(n), price(p) {}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}