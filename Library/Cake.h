#pragma once
#include "Product.h"
#include <string>
using namespace std;

class Cake : public Product {
    string flavor;
    string shape;
    int popularity;
public:
    Cake(string n = "", double p = 0.0, string f = "", string s = "круглый", int pop = 0);
    void show() const override;
    string getFlavor() const;
    int getPopularity() const;
};