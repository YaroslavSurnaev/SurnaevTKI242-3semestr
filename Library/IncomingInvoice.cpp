#include "IncomingInvoice.h"
#include <iostream>
#include <ctime>
using namespace std;

IncomingInvoice::IncomingInvoice(Product* p, int q, const string& supName)
    : product(p), quantity(q), supplierName(supName) {
    date = time(0);
}

void IncomingInvoice::show() const {
    cout << "Приходная накладная" << endl;
    cout << "  Товар: " << product->getName() << endl;
    cout << "  Количество: " << quantity << endl;
    cout << "  Поставщик: " << supplierName << endl;
    cout << "  Стоимость партии: " << product->getPrice() * quantity << " руб." << endl;
    cout << "  Дата: " << ctime(&date);
}

Product* IncomingInvoice::getProduct() const {
    return product;
}

int IncomingInvoice::getQuantity() const {
    return quantity;
}

string IncomingInvoice::getSupplierName() const {
    return supplierName;
}