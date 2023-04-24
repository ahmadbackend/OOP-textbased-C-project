#include<iostream>
void instructions();
void invalid(); void help(); void status(); void makeBid();
void makeOffer(); void checkWallet(); void nextFrame();
int main()
{

int userOption;

bool isTrading=true;
while (isTrading)
{
    /* code */
    instructions();
    std::cin>>userOption;
    std::cout<<"you choosed: "<<userOption<<std::endl;
    
 switch (userOption)
 {
    case 0:
    {
    invalid();
    isTrading=false;
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

return 0;
}