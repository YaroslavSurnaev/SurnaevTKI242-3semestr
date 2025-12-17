#include "ProductionRecord.h"
#include <iostream>
using namespace std;

ProductionRecord::ProductionRecord(Product* p) : product(p) {
    date = time(0);
}

double ProductionRecord::getTotalCost() const {
    return product->getPrice();
}

void ProductionRecord::show() const {
    cout << "Произведено: ";
    product->show();
    cout << "  Стоимость: " << getTotalCost() << " руб." << endl;
}

Product* ProductionRecord::getProduct() const {
    return product;
}