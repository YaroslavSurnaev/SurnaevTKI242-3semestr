#include "ConfectioneryItem.h"
#include <iostream>
using namespace std;

ConfectioneryItem::ConfectioneryItem(string n, double p, string f, int pop)
    : Product(n, p), flavor(f), popularity(pop) {
}

void ConfectioneryItem::show() const {
    cout << " ондитерское: " << name << ", вкус: " << flavor
        << ", цена: " << price << " руб., попул¤рность: " << popularity << "/100" << endl;
}