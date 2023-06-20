#include "Wallet.h"
#include<iostream>
#include "CSVReader.h"
Wallet:: Wallet()
                {

                };
        void Wallet::insertCurrency(std::string type, double amount){
            double balance;
            if(amount<0){
                throw std::exception{};
            }
            if(currencies.count(type)==0){
                balance=0;
            }
            else {
                balance=currencies[type];
            }
            balance+=amount;
            currencies[type]=balance;
            std::cout<<balance<<std::endl;
        };
        bool Wallet:: doesContainCurrency(std::string type, double amount){
            if(currencies.count(type)==0) return false;
            else return currencies[type]>amount;
        };
        /**generate string representation*/
        std::string Wallet:: toString(){
            std::string s="";
            for(std::pair<std::string,double> pair:currencies){
                std::string currency=pair.first;
                double amount= pair.second;
                s+=currency+" : "+std::to_string(amount) + "\n";
            }
            return s;
        };
         bool Wallet::removeCurrency(std::string type, double amount){
            if(amount<0){
               return false;
            }
            if(currencies.count(type)==0){
                return false;
            }
            else {
                // do we have enough
                if(doesContainCurrency(type,amount)){
                   currencies[type]-=amount;
                    std::cout<<"we reached this"<<std::endl;
                    return true;
                }
                
            }
            //they have but not enough 
            return false;
         };
           bool Wallet::canFulfillOrder(OrderBookEntry order){
            std::vector<std::string> currs=CSVReader::tokenise(order.product,'/');
            //ask order
            if(order.orderType==OrderBookType::ask){
                double price=order.price;
                double amount=order.amount;
                std::string currency=currs[0];
                return doesContainCurrency(currency,amount);
            }
            //bid logic
            if(order.orderType==OrderBookType::bid){
                double price=order.price;
                double amount=order.amount*price;
                std::string currency=currs[1];
                return doesContainCurrency(currency,amount);
            }

            return false;
           };