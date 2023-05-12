
//#include "Merkel.h" 

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
int userOption;


vector<string> tokenise(string csvLine, char separator){
    vector<string> tokens;
//char separator = ','; // the character that separates the tokens
int start, end; //used to delineate the position of the tokens
start = csvLine.find_first_not_of(separator,0);
string token;

do{
    end = csvLine.find_first_of (separator,start); 
   
if (start == csvLine.length() || start == end)// ## nothing more to find
{break;
}
if (end >= 0) token = csvLine.substr(start, end - start) ;//## start, substring length

else token = csvLine.substr(start, csvLine.length() - start);

tokens.push_back(token);
cout<<"test"<<"start"<<start<<"end"<<end<<endl;
start = csvLine.find_first_not_of(separator,end+1);  //## move past this token
 
}
while (end >0); //## continue loop condition
 for( string tok : tokens) cout <<tok<<endl;
return tokens;
}
int main()
{

string line;
 ifstream csv{"datas.csv"};
 try
 {
    /* code */
    (csv.is_open());{
    while(std::getline(csv,line)){
        cout<<line<<endl;

    }
    csv.close();
 }
 }
 catch(...)
 {
   cout<<"failed"<<endl;
 }


return 0;
}
