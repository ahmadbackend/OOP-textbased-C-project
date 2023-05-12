#pragma once
#include "BookEntry.h"
#include <vector>
using namespace std;


class CVSReader{
    public:
        CVSReader();
        static vector<BookEntry>  readCsv(string csvFile);
    private:
        static vector<string> tokenise(string csvLine, char separator);
        static BookEntry StringToBOOK(vector<string>strings);


};