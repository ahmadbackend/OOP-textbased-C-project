#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include"Wallet.h"

int main()
{

   // MerkelMain app{};
   // app.init();
   Wallet wall{};
   wall.insertCurrency("BTC",10);
  cout<<wall.doesContainCurrency("BTC",10)<<endl;
  cout<<wall.removeCurrency("BTC",5);
  cout<<wall.toString()<<endl;
  cout<<wall.removeCurrency("BTC",5)<<endl;
}






//     std::vector<OrderBookEntry> orders;

//     orders.push_back(  OrderBookEntry{1000, 
//                           0.02, 
//                         "2020/03/17 17:01:24.884492", 
//                         "BTC/USDT", 
//                         OrderBookType::bid}    );

//     orders.push_back(  OrderBookEntry{2000, 
//                           0.02, 
//                         "2020/03/17 17:01:24.884492", 
//                         "BTC/USDT", 
//                         OrderBookType::bid}    );
        

//    // std::cout << "The price is " << orders[1].price << std::endl;

//     for (OrderBookEntry& order : orders)
//     {
//         std::cout << "The price is " << order.price << std::endl;
//     }

//     for (unsigned int i = 0; i < orders.size() ; ++i)
//     {
//         std::cout << "The price is " << orders[i].price << std::endl;
//     }

//     for (unsigned int i = 0; i < orders.size() ; ++i)
//     {
//         std::cout << "The price is " << orders.at(i).price << std::endl;
//     }




 
