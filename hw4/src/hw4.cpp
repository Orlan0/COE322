//Name: Orlan Oconer 
//EID: ojo366
//TACC Username: orlan 

#include <cmath>
#include <iostream> 
#include <functional> 

using std::function;
using std::cout; 
using std::cin; 
using std::endl; 


//using da notes 
double newton_root
    (function <double(double)> f,
    function <double(double) >fprime)
    {
    //setting initial double x value 
    double x = 1000; 
    while(abs(f(x) > pow(10,-5))){
        x -= f(x)/fprime(x); 
    }
    return x; 
}

double newton_root
    (function <double(double)> f)
    {
    return newton_root(f, [f] (double x) {return (f(x + 1e-6) - f(x)) / 1e-6;;});
}

//now here I will make a for loop to call all the numbers 
int main() {
    cout << "This method is using the derivitive" << endl; 
    for(int i = 2; i <= 8; i++){
        cout<< "the sqrt of " << i << " is " << newton_root([i] (double x) {return x*x-i;}, [] (double x){return 2*x;}) << endl; 
    }
    //yooo this is wild so the compiler will know which one to use by funciton overloading

    cout << "this method is using explicity calculated deriv" << endl; 
     for(int i = 2; i <= 8; i++){
        cout<< "the sqrt of " << i << " is " << newton_root([i] (double x) {return x*x-i;}) <<endl;
    }
}


