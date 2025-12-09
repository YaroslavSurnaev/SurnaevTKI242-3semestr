#include <iostream>
#include <vector>
#include "Product.h"
#include "ConfectioneryItem.h"
#include "Supplier.h"
#include "Store.h"
#include "ProductionRecord.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Создаём товары
    Product chocolate("Шоколад", 50.0);
    Product candies("Конфеты", 30.0);
    ConfectioneryItem cake("Торт", 250.0, "клубника", 95);
    ConfectioneryItem cookies("Печенье", 40.0, "овсяное", 80);

    // Магазины
    Store shop1("Магазин 1");
    shop1.addOrder(&chocolate);
    shop1.addOrder(&cake);

    Store shop2("Магазин 2");
    shop2.addOrder(&candies);
    shop2.addOrder(&cookies);

    Store shop3("Магазин 3");
    shop3.addOrder(&cake);

    vector<Store*> shops = { &shop1, &shop2, &shop3 };

    // Поставщики
    Supplier sup1("Поставщик А");
    sup1.addProduct(&chocolate);
    sup1.addProduct(&candies);

    Supplier sup2("Поставщик Б");
    sup2.addProduct(&cake);
    sup2.addProduct(&cookies);

    vector<Supplier*> suppliers = { &sup1, &sup2 };

    // Производство
    ProductionRecord rec1(&chocolate, 100);
    ProductionRecord rec2(&candies, 200);
    ProductionRecord rec3(&cake, 50);
    ProductionRecord rec4(&cookies, 150);

    vector<ProductionRecord*> records = { &rec1, &rec2, &rec3, &rec4 };

    // === ЗАДАНИЕ 1: магазины, заказавшие "Торт" ===
    cout << "1. Магазины, заказавшие 'Торт':" << endl;
    for (Store* s : shops) {
        if (s->hasProduct("Торт")) {
            cout << "  - " << s->getName() << endl;
        }
    }

    // === ЗАДАНИЕ 2: товары от поставщика А ===
    cout << "\n2. Товары от 'Поставщик А':" << endl;
    sup1.showProducts();

    // === ЗАДАНИЕ 3: ассортимент и цена "Торт" ===
    cout << "\n3. Информация о 'Торте':" << endl;
    cake.show();

    // === ЗАДАНИЕ 4: самый популярный ===
    ConfectioneryItem* best = &cake;
    if (cookies.getPopularity() > best->getPopularity()) {
        best = &cookies;
    }
    cout << "\n4. Самый популярный товар:" << endl;
    best->show();

    // === ЗАДАНИЕ 5: общая стоимость производства ===
    double total = 0;
    for (ProductionRecord* r : records) {
        total += r->getTotalCost();
    }
    cout << "\n5. Общая стоимость производства: " << total << " руб." << endl;

    return 0;
}