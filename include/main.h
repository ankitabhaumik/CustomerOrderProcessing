#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Order {
    int customerId;
    int orderId;
    vector<int> productIds;
};

#endif