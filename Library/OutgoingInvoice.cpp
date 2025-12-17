#include "OutgoingInvoice.h"
#include <iostream>
#include <ctime>
using namespace std;

OutgoingInvoice::OutgoingInvoice(Product* p, int q, const string& storeName)
    : product(p), quantity(q), storeName(storeName) {
    date = time(0);
}

void OutgoingInvoice::show() const {
    cout << "Расходная накладная" << endl;
    cout << "  Товар: " << product->getName() << endl;
    cout << "  Количество: " << quantity << endl;
    cout << "  Магазин: " << storeName << endl;
    cout << "  Стоимость партии: " << product->getPrice() * quantity << " руб." << endl;
    cout << "  Дата: " << ctime(&date);
}

Product* OutgoingInvoice::getProduct() const {
    return product;
}

int OutgoingInvoice::getQuantity() const {
    return quantity;
}

string OutgoingInvoice::getStoreName() const {
    return storeName;
}