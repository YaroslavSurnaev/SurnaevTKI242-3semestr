#include "Supplier.h"
#include <iostream>
using namespace std;

Supplier::Supplier(string n) : name(n) {}

Supplier::~Supplier() {
    for (auto* inv : invoices) {
        delete inv;
    }
}

void Supplier::addIncomingInvoice(IncomingInvoice* invoice) {
    invoices.push_back(invoice);
}

void Supplier::showInvoices() const {
    cout << "Поставщик " << name << " — приходные накладные:" << endl;
    for (auto* inv : invoices) {
        inv->show();
    }
}

string Supplier::getName() const {
    return name;
}