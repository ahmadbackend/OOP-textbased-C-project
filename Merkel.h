#pragma once
#include<vector>

#include "BookEntry.h"
class Merkel
{
    public:
        Merkel();
      
        void init();
       
    private:
        void invalid();
        void loadBookEntry();
        void help();
        void status();
        void makeBid();
        void makeOffer();
        void checkWallet();
        void nextFrame();
        void instructions();
        int getUserOption();
        void processUserOption(int userOption);
        vector<BookEntry> orders;
};
