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



  

int read_number() {  // Use the same function name as declared earlier
    int x;
    cout << "Please enter a number: " <<endl;
    cin >> x;
    return x;
}

/*
int main() { //Main function, runs fizzbuzz
        if (int number = read_number();int(number) % 3 == 0 && int(number) % 5 == 0) {15
            cout << "Fizzbuzz!" << endl; //Printed if number is a multiple of 3 and 5
        } else if (int(number) % 3 == 0) {
            cout << "Fizz!" << endl; //Printed if number is a multiple of 3
        } else if (int(number) % 5 == 0) {
            cout << "Buzz!" << endl; //Printed if number is a multiple of 5
        }

    return 0;
}
*/
int main() {
    // Exercise 3
    if (int number = read_number(); int(number) % 3 == 0 && int(number) % 5 == 0) {
        cout << "Fizzbuzz!" << endl; 
    }
    else if (int(number) % 3 == 0 && int(number) % 5 != 0 ) { 
        cout << "Fizz!" << endl; 
    }
    else if (int(number) % 5 == 0 && int(number) % 3 != 0) {
        cout << "Buzz!" << endl; 
    }
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
