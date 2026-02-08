#pragma once
#include <string>

namespace ConfectioneryFactory {
    class Product {
    protected:
        std::string name;
        double price;
        int quantity;
        std::string department;

    public:
        Product(const std::string& name, double price, int quantity, const std::string& department);
        virtual ~Product() = default;

        std::string getName() const;
        double getPrice() const;
        int getQuantity() const;
        std::string getDepartment() const;

        void setPrice(double newPrice);
        void setQuantity(int newQuantity);

        virtual double getDiscountPrice(double totalPurchase, bool isWholesaleCustomer) const;
        virtual std::string getDescription() const = 0;
    };
}