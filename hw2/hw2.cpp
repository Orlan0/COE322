//Homework #2


// Excersize #1 from the conditionals homework 

 /*Read in a positive integer. If it’s a multiple of three print ‘Fizz!’; if
 it’s a multiple of five print ‘Buzz!’. It is a multiple of both three
 and five print ‘Fizzbuzz!’. Otherwise print nothing.
 Note:
 • Capitalization.
 • Exclamation mark.
 • Your program should display at most one line of output. */


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
    if (x%3 == 0 && x%5 ==0){
        cout << "Fizzbuzz!" <<endl; 
    }
    else if (x%3 == 0 && x%5 !=0){ 
        cout << "Fizz!" <<endl; 
    }
    else if (x%5 == 0 && x%3 !=0){
        cout<< "Buzz!" << endl; 
    }
    else { 
        cout<< "Its nothing sadge" <<endl;
    }
/*
Excersize #2
 int x; 
 cout << "give me a number please: .\n"; 
 cin >> x;25
 

if(x & 1) {
    cout << "this number is odd:" << x << "\n"; 
} else {
    cout << "this number is even:" << x << "\n";
}
*/


return 0; 
}
