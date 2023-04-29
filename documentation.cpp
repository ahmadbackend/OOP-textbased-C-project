
#include<iostream>
void invalid(){
 std::cout<<"invalid"<<std::endl;  
};
void help(){
std::cout<<"your aim is to make money"<<std::endl;
}; 
void status(){
std::cout<<"Market looks good"<<std::endl;
};
void makeBid(){
std::cout<<"Make a bid"<<std::endl;
};
void makeOffer(){
std::cout<<"Make an offer"<<std::endl;
}; 
void checkWallet(){
std::cout<<"Your wallet is empty."<<std::endl;
}; 
void nextFrame(){
std::cout<<"Going to next time frame"<<std::endl;
};
void instructions(){
    //1 print help
std::cout<<"1: print help"<<std::endl;

//2 print exchange stats
std::cout<<"2: print exchange stats"<<std::endl;
//3 make an offer=sell
std::cout<<"3: Make an offer"<<std::endl;
//make a bid =buy
std::cout<<"4: Make a bid "<<std::endl;
//5 print wallet
std::cout<<"5: print wallet"<<std::endl;

//6 continue = next time step
std::cout<<"6: Continue"<<std::endl;

std::cout<<"==================="<<std::endl;
std::cout<<"Type 1-6, Type 0 to break"<<std::endl;
}

void getUserOption(int userOption)
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