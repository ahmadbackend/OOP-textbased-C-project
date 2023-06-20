#pragma once
using namespace std;
#include <vector>
#include "OrderBook.h"
//#include "Wallet.h"
class MerkelMain
{
    public:
        MerkelMain();
         string currentTime;
        /** Call this to start the sim */
        void init();

    private: 
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterASK();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);
        
        OrderBook orderBook{"text.csv"};
       // Wallet wallet;

}; 
