#include "ProductionRecord.h"
#include <iostream>
using namespace std;

ProductionRecord::ProductionRecord(Product* p, int q) : product(p), quantity(q) {
    date = time(0);
}

double ProductionRecord::getTotalCost() const {
    return product->getPrice() * quantity;
}

void ProductionRecord::show() const {
    cout << "Произведено: ";
    product->show();
    cout << "  Количество: " << quantity << ", Стоимость: " << getTotalCost() << " руб." << endl;
}