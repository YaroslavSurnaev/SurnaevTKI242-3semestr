#include "Store.h"
#include <iostream>
using namespace std;

Store::Store(string n) : name(n) {}

Store::~Store() {
    for (auto* inv : invoices) {
        delete inv;
    }
}

void Store::addOutgoingInvoice(OutgoingInvoice* invoice) {
    invoices.push_back(invoice);
}

void Store::showInvoices() const {
    cout << "Магазин " << name << " — расходные накладные:" << endl;
    for (auto* inv : invoices) {
        inv->show();
    }
}

string Store::getName() const {
    return name;
}