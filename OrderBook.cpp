
#include "OrderBook.h"
#include <iostream>
#include "CSVReader.h"
#include <math.h>
using namespace std;
 OrderBook::OrderBook (string filename){
 orders=CSVReader::readCSV(filename);


}
    /** return vector of all known products*/
  vector<string> OrderBook::getKnownProducts(){
        vector<string> products;
        map<string,bool>prodMap;
        for( OrderBookEntry e:orders){
            prodMap[e.product]=true;
        }
         for( auto  e :prodMap){
            products.push_back(e.first);
        }
        return products;
    };
    /** return orders according to their type and time and product name*/
     vector<OrderBookEntry>OrderBook::getOrders(OrderBookType type, 
     string product, string timeStamp){
        vector<OrderBookEntry> orders_sub;
        for(OrderBookEntry& e: orders){
            if(e.orderType==type&&
             e.product==product &&
            e.timestamp==timeStamp){
                orders_sub.push_back(e);

            }
        }
        return orders_sub;
     };
    double OrderBook:: getHighestPrice( vector<OrderBookEntry>& orders){
        double max= orders[0].price;
        for(OrderBookEntry& e: orders ){
            if(e.price>max)  max=e.price;
            
            
        }
        return max;
    };
    double OrderBook:: getLOwestestPrice( vector<OrderBookEntry>& orders){
        double min= orders[0].price;
        for(OrderBookEntry& e: orders ){
            if(e.price<min)  min=e.price;
                
            
        }

        return min;
};
 double OrderBook::pricesSpread(vector<OrderBookEntry>& orders,vector<OrderBookEntry>& orderss){
   double spread=0;
    for(int i=0;i<orders.size(); i++){
     
    spread+= abs(orders[i].price-orderss[i].price);
    }
 return spread/orders.size();
 }
