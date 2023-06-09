#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include<string>
#include<vector>
#include<map>
#include <algorithm>

using namespace std;
class OrderBook{
    public :
    /** constructor to read cvs data file */
    OrderBook (string filename);
    /** return vector of all known products*/
      vector<string> getKnownProducts();
      string getEarliestTime();
      string getNextTimeFrame( string tim);
      int orderSize;
      std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

      void insertOrder(OrderBookEntry& order)

{
orders.push_back(order);
sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}
    /** return orders according to their type and time and product name*/
     vector<OrderBookEntry> getOrders(OrderBookType type, string product, string timeStamp);
     static double getHighestPrice( vector<OrderBookEntry>& orders);
     static double getLOwestestPrice( vector<OrderBookEntry>& orders);
     static double pricesSpread(vector<OrderBookEntry>& orders,vector<OrderBookEntry>& orderss);
     private:
      vector<OrderBookEntry>orders;
};