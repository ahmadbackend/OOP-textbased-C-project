#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include "OrderBook.h"
#include<limits>
#include <stdio.h>
#include <ctime>
MerkelMain::MerkelMain()
{


}

void MerkelMain::init()
{
    /** now  earliest time will be initialized to first time stamp
     * of orders
    */
    currentTime=orderBook.getEarliestTime();
    int input;
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}



void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue   
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
    std::cout <<"current time is " <<currentTime  <<endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats()
{
   
  for( string const & p: orderBook.getKnownProducts()){
    cout<<"product is "<<p<<endl;
    vector<OrderBookEntry>entries=orderBook.getOrders(OrderBookType::ask,p,
                                    currentTime);
     vector<OrderBookEntry>entriesBid=orderBook.getOrders(OrderBookType::bid,p,
                                    currentTime);
    cout<<"ask"<< entries.size()<<endl;
    cout<<"average spread is "<< orderBook.pricesSpread(entries,entriesBid)<<endl;
    cout<<"highest price"<< orderBook.getHighestPrice(entries) <<endl;
    cout<<"lowest price"<< orderBook.getLOwestestPrice(entries) <<endl;

  }
    
    
}

void MerkelMain::enterASK()
{
    std::cout << "Make an ask - enter the amount: product,price, amount, eg ETH/BTC,200,0.5 " << std::endl;
    std::string input ;
    //cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    std::getline(cin,input);

   vector<string>token= CSVReader::tokenise(input,',');
   if(token.size()!=3){
        cout<<"CSVReader::tokenise bad input  "<< input <<endl;
   }
   else {
    OrderBookEntry ob= CSVReader::stringsToOBE(
        token[1],token[2],currentTime,token[0],OrderBookType::ask);
        orderBook.insertOrder(ob);
   }
  

}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - product,price, amount, eg ETH/BTC,200,0.5 t" << std::endl;

    std::string input ;
    //cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    std::getline(cin,input);

   vector<string>token= CSVReader::tokenise(input,',');
   if(token.size()!=3){
        cout<<"CSVReader::tokenise bad input  "<< input <<endl;
   }
   else {
    OrderBookEntry ob= CSVReader::stringsToOBE(
        token[1],token[2],currentTime,token[0],OrderBookType::bid);
        orderBook.insertOrder(ob);

   }
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void MerkelMain::gotoNextTimeframe()
{
    currentTime=orderBook.getNextTimeFrame(currentTime);
   std::vector<OrderBookEntry>sales=orderBook.matchAsksToBids("ETH/BTC",currentTime);
   for(OrderBookEntry& sale:sales){
    std::cout <<"sale amount "<<sale.amount<< " sale price"<<sale.price<<std::endl;
   }
}
 
int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try{
    userOption = std::stoi(line);
    }catch(const std::exception& e)
    {
}
std::cout << "You chose: " << userOption << std::endl;
return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1) 
    {
        printHelp();
    }
    if (userOption == 2) 
    {
        printMarketStats();
    }
    if (userOption == 3) 
    {
        enterASK();
    }
    if (userOption == 4) 
    {
        enterBid();
    }
    if (userOption == 5) 
    {
        printWallet();
    }
    if (userOption == 6) 
    {
        gotoNextTimeframe();
    }       
}
 
