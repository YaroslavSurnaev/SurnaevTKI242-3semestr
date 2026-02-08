#pragma once
#include "Department.h"
#include <vector>
#include <memory>
#include <map>

namespace ConfectioneryFactory {
    class Store {
    private:
        std::vector<std::unique_ptr<Department>> departments;
        std::map<std::string, double> sales;

    public:
        Store();

        void addDepartment(std::unique_ptr<Department> department);
        Department* getDepartment(const std::string& name) const;

        std::pair<Product*, Department*> findProductDepartment(const std::string& productName) const;
        std::vector<std::string> getDepartmentProducts(const std::string& departmentName) const;
        double getDepartmentSales(const std::string& departmentName) const;
        double calculatePurchase(const std::vector<std::pair<Product*, int>>& items,
            bool isWholesaleCustomer) const;

        bool checkCake(const std::string& productName,
            const std::string& flavor,
            int layers,
            bool hasFrosting) const;

        bool checkCookie(const std::string& productName,
            const std::string& shape,
            bool isGlazed) const;

        bool checkChocolate(const std::string& productName,
            const std::string& cocoaPercent,
            const std::string& filling) const;

        void addSale(const std::string& departmentName, double amount);
    };
}