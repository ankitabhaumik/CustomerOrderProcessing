#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <algorithm>
#include "main.h"
using namespace std;

class Customer
{
   unordered_map<int,double>tolcost_per_customer;
   vector<pair<int,double>>customerasperprice;
   vector<int>vipcustomer;
   map<int,int>mostfreqprod;


   public:
   void get_tot_amt_each_customer(unordered_map<int,double>& product_price_map, vector<Order>& order);
   void getvipcustomer(int amount);
   void most_freq_product(vector<Order>order);
   void deleteduplicateorder(vector<Order> &order);
   void sortcustomer(); //Sort Customer as per total cost;
   void printVector(vector<Order> vec);

};

#endif