#pragma once
#include <string>
using namespace std;

class Product {
protected:
    string name;
    double price;
public:
    Product(string n = "", double p = 0.0);
    virtual ~Product() {}

    string getName() const { return name; }
    double getPrice() const { return price; }

    virtual void show() const; // виртуальный Ч дл¤ полиморфизма
};