#include "CsvReader.h"
#include<vector>
#include "BookEntry.h"

CVSReader::CVSReader(){

};

vector<BookEntry> CVSReader::  readCsv(string csvFile){
 vector<BookEntry> enteries;
 return enteries;
};
 vector<string>CVSReader::  tokenise(string csvLine, char separator){
 vector<string> tokens;
 return tokens;
};
 BookEntry CVSReader::  StringToBOOK(vector<string>tokens)
 {
 double price, amount;
  if (tokens.size()!=5){
    throw exception{};
  }
try{
    price= stod (tokens[3]);
    amount= stod (tokens[4]);

}
catch(exception& e){
    throw;
}

  BookEntry entry{price,amount,tokens[0],tokens[1],BookEntry::StringToType(tokens[2])};
  return entry;
};