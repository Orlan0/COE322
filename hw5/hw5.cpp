//Homework #2
//Name: Orlan Oconer
//UTEID: ojo366
//Tacc username: orlan


// Excersize #1 from the conditionals homework 

 /*Read in a positive integer. If it’s a multiple of three print ‘Fizz!’; if
 it’s a multiple of five print ‘Buzz!’. It is a multiple of both three
 and five print ‘Fizzbuzz!’. Otherwise print nothing.
 Note:
 • Capitalization.
 • Exclamation mark.
 • Your program should display at most one line of output. */

#include <iostream>
#include <cstdlib> 

using std::cout; 
using std::cin; 
using std::endl; 


// TAKE THE NUMBER FROM THE .SH FILE 
int real_number(int argc, char* argv[]);
int real_number(int argc, char* argv[]){  // Use the same function name as declared earlier
    int x = std::stoi(argv[1]); // Convert argv[1] to integer
    return x;
}


int main(int argc, char* argv[]) {
    // Exercise 3

  int number = real_number(argc,argv); 
  
    if (number % 3 == 0 && number % 5 == 0) {
        cout << "Fizzbuzz!" << endl; 
    }
    else if (number % 3 == 0 && number % 5 != 0 ) { 
        cout << "Fizz!" << endl; 
    }
    else if (number % 5 == 0 && number % 3 != 0) {
        cout << "Buzz!" << endl; 
    }
    else
      cout << number << endl; 
    return 0; 
}

  /*
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
	} */
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
