#pragma once
#include "IncomingInvoice.h"
#include <vector>
#include <string>
using namespace std;

class Supplier {
    string name;
    vector<IncomingInvoice*> invoices;
public:
    Supplier(string n = "");
    ~Supplier();
    void addIncomingInvoice(IncomingInvoice* invoice);
    void showInvoices() const;
    string getName() const;
};