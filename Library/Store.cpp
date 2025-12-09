#include "Store.h"
#include <iostream>
using namespace std;

Store::Store(string n) : name(n) {}

void Store::addOrder(Product* p) {
    orders.push_back(p);
}

bool Store::hasProduct(const string& productName) const {
    for (Product* p : orders) {
        if (p->getName() == productName)
            return true;
    }
    return false;
}

void Store::showOrders() const {
    cout << "Магазин " << name << " заказал:" << endl;
    for (Product* p : orders) {
        cout << "  - ";
        p->show();
    }
}