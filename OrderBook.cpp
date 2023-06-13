
#include "OrderBook.h"
#include <iostream>
#include "CSVReader.h"
#include <math.h>
#include<algorithm>
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
       string OrderBook:: getEarliestTime(){
       return orders[0].timestamp;
       };
      string OrderBook::getNextTimeFrame( string tim){
        for(OrderBookEntry& e : orders){
            if (e.timestamp>tim){
                return e.timestamp;
            }
        }
        return orders[0].timestamp;
      };
std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timeStamp)
{
// asks = orderbook.asks in this timeframe
std:: vector<OrderBookEntry> asks=getOrders(OrderBookType::ask,
                                            product,
                                            timeStamp
                                            );
// bids = orderbook.bids in this timeframe
std:: vector<OrderBookEntry> bids=getOrders(OrderBookType::bid,
                                            product,
                                            timeStamp
                                            );
// sales = []
std:: vector<OrderBookEntry> sales; 
// sort asks lowest first
std::sort(asks.begin(),asks.end(),OrderBookEntry::compareByPriceAsc);
// sort bids highest first
std::sort(bids.begin(),bids.end(),OrderBookEntry::compareByPriceDesc);

// for ask in asks:
 for(OrderBookEntry& ask : asks){
   
// for bid in bids:
     for(OrderBookEntry& bid : bids){
        if(bid.price>=ask.price)
        {
           OrderBookEntry sale{ask.price,0,timeStamp,
           product,
           OrderBookType::sale};
           /* OrderBookEntry( double _price, 
                        double _amount, 
                        std::string _timestamp, 
                        std::string _product, 
                        OrderBookType _orderType);*/
        
// if bid.price >= ask.price # we have a match
            
// sale = new orderbookentry()
// sale.price = ask.price
            sale.price=ask.price;
// if bid.amount == ask.amount: # bid completely clears ask
            if(bid.amount==ask.amount)
            {
                sale.amount = ask.amount;
                sales.push_back(sale);
                //make sure the bid is not processed again
                bid.amount = 0 ;
            // # can do no more with this ask
            // # go onto the next ask
                break;
            }
            if (bid.amount > ask.amount)// # ask is completely gone slice the bid
            {
                 sale.amount = ask.amount;
                 sales.push_back(sale);
                // # we adjust the bid in place
                // # so it can be used to process the next ask
                 bid.amount = bid.amount - ask.amount;
                // # ask is completely gone, so go to next ask
                 break;
            }
            if (bid.amount < ask.amount) // # bid is completely gone, slice the ask
            {
                sale.amount = bid.amount;
                sales.push_back(sale);
                // # update the ask
                // # and allow further bids to process the remaining amount
                ask.amount = ask.amount - bid.amount;
                 bid.amount = 0;// # make sure the bid is not processed again
                //2
                // # some ask remains so go to the next bid
                continue;
           }
        }
    }
}
 return sales;

}

