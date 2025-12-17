#pragma once
#include "OutgoingInvoice.h"
#include <vector>
#include <string>
using namespace std;

class Store {
    string name;
    vector<OutgoingInvoice*> invoices;
public:
    Store(string n = "");
    ~Store();
    void addOutgoingInvoice(OutgoingInvoice* invoice);
    void showInvoices() const;
    string getName() const;
};