#include "BookEntry.h"


BookEntry::BookEntry(double _price,
            double _amount,
            string _timeStamp,
            string _product,
            OrderType _order) 
: price(_price),amount(_amount),timeStamp(_timeStamp), 
product(_product), order(_order)
            {

            }
OrderType BookEntry::StringToType( string s){
 if (s=="bid"){
    return OrderType::bid;
 }
 if (s=="sell"){
    return OrderType::sell;
 }
 
    return OrderType::unkown;
 
}
          
