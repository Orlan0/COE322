//Homework #2

#include <iostream>

using std::cout; 
using std::cin; 
using std::endl; 



//logic if the least significant bit is 1, if it is a zero, then it is even. Logic --> Create one loop to see
// if it has the last bit of 1. 

int main() {
 int x; 
 cout << "give me a number please: .\n"; 
 cin >> x;

if(x & 1) {
    cout << "this number is odd:" << x << "\n"; 
} else {
    cout << "this number is even:" << x << "\n";
}
return 0; 
}
