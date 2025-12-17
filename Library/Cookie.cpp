#include "Cookie.h"
#include <iostream>
using namespace std;

Cookie::Cookie(string n, double p, string f, bool glazed, int pop)
    : Product(n, p), flavor(f), isGlazed(glazed), popularity(pop) {
}

void Cookie::show() const {
    cout << "ѕеченье: " << name << ", вкус: " << flavor
        << ", глазированное: " << (isGlazed ? "да" : "нет")
        << ", цена: " << getPrice() << " руб., попул€рность: " << popularity << "/100" << endl;
}

string Cookie::getFlavor() const {
    return flavor;
}

int Cookie::getPopularity() const {
    return popularity;
}