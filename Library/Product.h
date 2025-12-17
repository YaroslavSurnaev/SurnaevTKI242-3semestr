#pragma once
#include <string>
using namespace std;

class Product {
protected:
    string name;
    double price;
public:
    Product(string n = "", double p = 0.0);
    virtual ~Product() = default;
    string getName() const;
    double getPrice() const;
    virtual void show() const = 0;
};