#include<string>
#include <map>
#include "OrderBookEntry.h"
class Wallet{
    public:
        Wallet();
        /** insert currency to the wllaet*/
        void insertCurrency(std::string type, double amount);
        /**remove currency to the wllaet*/
        bool removeCurrency(std::string type, double amount);
        /** check if wallet has this currency and the amount is enough*/
        bool doesContainCurrency(std::string type, double amount);
        /**generate string representation*/
        std::string toString();
        /**check if wallet can cope with this order*/
        bool canFulfillOrder(OrderBookEntry order);
    private:
    std::map<std::string, double> currencies;

};