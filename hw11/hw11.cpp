//Name: Orlan Oconer 
//EID: ojo366
//TACC Username: orlan 

#include <cmath>
#include <iostream> 
#include <functional> 
#include <complex> 

using std::function;
using std::cout; 
using std::cin; 
using std::endl; 
using std::complex; 



//using da notes 

// I am modifying this to take in a template instead

// Template just basically takes any input variable and translates it 
template <typename T> 
//So I think more or less, everywhere there is a double, instead it will 
// Be replaced by this "T" This will allow the new function to take any variable 

T newton_root
    (function <T(T)> f,
    function <T(T) >fprime)
    {
    //setting initial double x value 
    T x = 1000; 
    while(std::abs(f(x)) > pow(10,-5)){
        x -= f(x)/fprime(x); 
    }
    return x; 
}


//Same thing here just create a Template so that values know where to go 
template <typename T> 
T newton_root
    (function <T(T)> f)
    {
    return newton_root(f, [f] (T x) {return (f(x + 1e-6) - f(x)) / 1e-6;;});
}

//now here I will make a for loop to call all the numbers 
int main() {
    
     // Test with "float"
    cout << "Using float:" << endl;
    for (float i = 2; i <= 8; i++) {
        cout << "The sqrt of " << i << " is " << newton_root<float>([i](float x) { return x * x - i; }, [](float x) { return 2 * x; }) << endl;
    }

    //yooo this is wild so the compiler will know which one to use by funciton overloading

    // Test with integer
    cout << "Using integer:" << endl;
    for (int i = 2; i <= 8; i++) {
        cout << "The sqrt of " << i << " is " << newton_root<double>([i](double x) { return x * x - i; }, [](double x) { return 2 * x; }) << endl;
    }
    
    // Test with complex<double>

    cout << "Using complex<double>:" << endl;
    for (int i = 2; i <= 8; i++) {
        complex<double> root = newton_root<complex<double>>(
            [i](complex<double> z) { return z * z - complex<double>(i); },
            [](complex<double> z) { return 2.0 * z; }
        );
        cout << "The sqrt of " << i << " is " << root << endl;
    }


    //this will test the complex with a complext number in the thing 
    cout << "Using complex<double>, this will have a value of 2i in the imaginary part:"<< endl; 
    for (int i = 2; i <= 8; i++) {
        // Add an imaginary part to `i`, creating complex numbers like (2.0 + 2.0i)
        complex<double> target = complex<double>(i, 2.0); 
        complex<double> root = newton_root<complex<double>>(
            [target](complex<double> z) { return z * z - target; },
            [](complex<double> z) { return 2.0 * z; }
        );
        cout << "The sqrt of " << target << " is " << root << endl;
    }

    /*
   auto x_float = newton_root<float>(2.0f); 
   auto x_double = newton_root<double>(2.0); 
   auto x_complex = newton_root<complex<float>>(2.0+2.i);
    */




}
