
#include "Merkel.h"
#include<iostream>
#include<vector>
//#include "BookEntry.h"
using namespace std;
Merkel::Merkel(){

};

void Merkel::init(){
    while (true){
        instructions();
        loadBookEntry();
    int input = getUserOption();
    processUserOption( input);
    }


};
int Merkel ::getUserOption(){
    int userOPtion;
     cin>>userOPtion;
     return userOPtion;
   
}
void Merkel::loadBookEntry(){
    
     
    orders.push_back( BookEntry{256,0.02,"2012/02/13 11:55","BTC/USDT"
    ,OrderType::bid});

    orders.push_back(BookEntry{1000,0.07,"2019/02/13 11:55","BTC/USDT"
    ,OrderType::sell});

    
};
void Merkel::invalid(){
 cout<<"invalid"<<endl;  
};
void Merkel:: help(){
cout<<"your aim is to make money"<<endl;
}; 
void Merkel:: status(){
cout<<"there are " <<orders.size()<<" entries "<<endl;
};
void Merkel:: makeBid(){
cout<<"Make a bid"<<endl;
};
void Merkel::makeOffer(){
cout<<"Make an offer"<<endl;
}; 
void Merkel:: checkWallet(){
cout<<"Your wallet is empty."<<endl;
}; 
void Merkel:: nextFrame(){
cout<<"Going to next time frame"<<endl;
};
void Merkel:: instructions(){
    //1 print help
cout<<"1: print help"<<endl;

//2 print exchange stats
cout<<"2: print exchange stats"<<endl;
//3 make an offer=sell
cout<<"3: Make an offer"<<endl;
//make a bid =buy
cout<<"4: Make a bid "<<endl;
//5 print wallet
cout<<"5: print wallet"<<endl;

//6 continue = next time step
cout<<"6: Continue"<<endl;

cout<<"==================="<<endl;
cout<<"Type 1-6, Type 0 to break"<<endl;
}

void Merkel:: processUserOption(int userOption)
{
    
switch (userOption)
 {
    case 0:
    {
    invalid();
  
    break;
    }
    case 1:
    {
    help();
    break;
    }
   case 2:
    {
    status();
    break;
    }
    case 3:
    {
    makeOffer();
    break;
    }
    case 4:
    {
    makeBid();
    break;
    }
    case 5:
    {
    checkWallet();
    break;
    }
    default:
    {
    nextFrame();
    }
}
}