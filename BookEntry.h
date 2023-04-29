#include<string>
using namespace std;
enum class OrderType {sell,bid};
class BookEntry{

public:
        BookEntry(double _price,
            double _amount,
            string _timeStamp,
            string _product,
            OrderType _order) ;
          
       
        double price;
        double amount;
        string timeStamp;
        string product;
        OrderType order;
};
