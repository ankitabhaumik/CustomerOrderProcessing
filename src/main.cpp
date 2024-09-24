#include "main.h"
#include "customer.h"


int main() 
{
    // Example product price mapping (Product ID -> Price)
    //unordered_map<int, double>productPriceMap = {{1, 100.0}, {2, 50.0}, {3, 75.0}, {4, 200.0}, {5, 150.0}};
    unordered_map<int, double> productPriceMap = {{1, 100.0}, {2, 50.0}, {3, 75.0}, {4, 200.0}, {5, 150.0}};

    // Orders: (Customer ID, Order ID, List of Product IDs)
    vector<Order> orders = {
        {1, 1001, {1, 2, 3}},    // Customer 1 bought products 1, 2, 3
        {2, 1002, {2, 4}},       // Customer 2 bought products 2, 4
        {1, 1003, {1, 3, 5}},    // Customer 1 placed another order with products 1, 3, 5
        {3, 1004, {3}},          // Customer 3 bought product 3
        {2, 1005, {4}},          // Customer 2 placed another order with product 4
        {1, 1001, {1, 2, 3}}     // Duplicate order by customer 1 (should be removed)
    };

    Customer c;
    c.deleteduplicateorder(orders);
    c.get_tot_amt_each_customer(productPriceMap,orders);
    c.sortcustomer();
    c.getvipcustomer(200);
    c.most_freq_product(orders);

}