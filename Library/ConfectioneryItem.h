#pragma once
#include "Product.h"
#include <string>
using namespace std;

class ConfectioneryItem : public Product {
    string flavor;
    int popularity;
public:
    ConfectioneryItem(string n = "", double p = 0.0, string f = "", int pop = 0);
    void show() const override; // переопределяем

    string getFlavor() const { return flavor; }
    int getPopularity() const { return popularity; }
};