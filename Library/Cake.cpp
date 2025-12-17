#include "Cake.h"
#include <iostream>
using namespace std;

Cake::Cake(string n, double p, string f, string s, int pop)
    : Product(n, p), flavor(f), shape(s), popularity(pop) {
}

void Cake::show() const {
    cout << "Торт: " << name << ", вкус: " << flavor
        << ", форма: " << shape
        << ", цена: " << getPrice() << " руб., популярность: " << popularity << "/100" << endl;
}

string Cake::getFlavor() const {
    return flavor;
}

int Cake::getPopularity() const {
    return popularity;
}