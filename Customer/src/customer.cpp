#include "customer.h"


void Customer :: get_tot_amt_each_customer(unordered_map<int,double>& product_price_map, vector<Order>& order)
{
   cout<<endl<<endl<<"Calculating Total Cost of each Customer"<<endl;
   cout<<"---------------------------------------"<<endl;
   for(const auto& ordr : order)
   {
       double totalamount=0;
       for(const auto& prodid : ordr.productIds)
       {
          if(product_price_map.find(prodid) != product_price_map.end())
          {
             totalamount = totalamount+product_price_map[prodid];
          }
       }
       tolcost_per_customer[ordr.customerId] += totalamount;
   }

   cout<<"Customer id" <<"  "<<"Total Cost"<<endl;
   for(auto itr : tolcost_per_customer)
   {
      cout<<itr.first<<"            "<<itr.second<<endl;
   }

}

void Customer :: getvipcustomer(int amount)
{
    vipcustomer.resize(customerasperprice.size());

    transform(customerasperprice.begin(),customerasperprice.end(),vipcustomer.begin(),[amount](auto& a) -> int {
         return (a.second>amount)? a.first : 0;
    });

   cout<<endl<<endl<<"VIP Customer"<<endl;
   cout<<"-----------"<<endl;
   cout<<"Customer ID"<<endl;

   for(auto i : vipcustomer)
   {
      if(i>0)
        cout<<i<<endl;
   }
}

void Customer :: most_freq_product(vector<Order>order)
{
   int mostfreq=0;int prodid;
   for(auto ordr : order)
   {
       for(auto prodid : ordr.productIds)
       {
            mostfreqprod[prodid]++;
       }
   } 

  for(auto itr : mostfreqprod)
  {
     if(itr.second > mostfreq)
     {
          mostfreq = itr.second;
          prodid = itr.first;
     }
  }

   cout<<endl<<endl<<"Most Frequent Used Product ID : " <<prodid<<endl;
}


void Customer :: deleteduplicateorder(vector<Order> &order)
{
    sort(order.begin(),order.end(),[](auto& a, auto& b)
    {
        return a.orderId < b.orderId;
    });
      
    auto uniqueele = unique(order.begin(),order.end(),[](auto& a, auto& b)
    {
        return a.orderId == b.orderId;
    });

    order.erase(uniqueele,order.end());
    
    cout<<endl<<endl<<"Order After Deleting Duplicates"<<endl;
    cout<<"---------------------------------------"<<endl;

    printVector(order);

}

void Customer :: sortcustomer()
{
    for(auto it : tolcost_per_customer)
    {
         customerasperprice.push_back(it);
    }

    sort(customerasperprice.begin(),customerasperprice.end(),[](auto& a, auto& b){
        return a.second>b.second;
    });

    cout<<endl<<endl<<"Sorting Customer as per Total Cost"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Customer id" <<" "<<"Total Cost"<<endl;
    for(auto it : customerasperprice)
    {
        cout<<it.first<<"            "<<it.second<<endl;
    }
}


void Customer :: printVector(vector<Order> vec)
{
   cout<<endl<<"Customerid  " <<"Orderid  "<<"Product IDS "<<endl;
   for(const auto& it : vec)
   {
      cout<<it.customerId<<"           "<<it.orderId<<"         ";
      for(const auto& prodid : it.productIds)
      {
         cout<<prodid<<" ";
      }
      cout<<endl;
   }
}
