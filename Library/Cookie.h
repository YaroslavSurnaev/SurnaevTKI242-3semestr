#pragma once
#include "Product.h"
#include <string>
using namespace std;

class Cookie : public Product {
    string flavor;
    bool isGlazed;
    int popularity;
public:
    Cookie(string n = "", double p = 0.0, string f = "", bool glazed = false, int pop = 0);
    void show() const override;
    string getFlavor() const;
    int getPopularity() const;
};

