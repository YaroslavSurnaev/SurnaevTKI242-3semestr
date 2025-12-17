#include <iostream>
#include <vector>
#include "Cake.h"
#include "Cookie.h"
#include "Store.h"
#include "Supplier.h"
#include "ProductionRecord.h"

using namespace std;

int main() {
    Cake cake("Шоколадный торт", 300.0, "шоколад", "круглый", 98);
    Cookie cookie("Овсяное печенье", 45.0, "овсянка", true, 85);

    Supplier sup("Поставщик A");
    sup.addIncomingInvoice(new IncomingInvoice(&cake, 10, "Поставщик A"));
    sup.addIncomingInvoice(new IncomingInvoice(&cookie, 50, "Поставщик A"));

    Store shop("Магазин 1");
    shop.addOutgoingInvoice(new OutgoingInvoice(&cake, 2, "Магазин 1"));
    shop.addOutgoingInvoice(new OutgoingInvoice(&cookie, 10, "Магазин 1"));

    ProductionRecord rec1(&cake);
    ProductionRecord rec2(&cookie);

    cout << "Производство" << endl;
    rec1.show();
    rec2.show();

    cout << "\nНакладные" << endl;
    sup.showInvoices();
    cout << "\n" << string(50, '-') << "\n" << endl;
    shop.showInvoices();

    return 0;
}