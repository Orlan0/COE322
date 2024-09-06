


#include <iostream> 

using std::cout; 
using std::cin; 
using std::endl; 


double f(double); 
double deriv(double);

int main()  {
    //find the square root of 2 
    //start somewhere while the function in the current value is too large keep looping 
    //print results 
    double current_x = 90000.;
    double function_value = f(current_x); 

    //for some reason abs wasnt working so I just doubled the funciton_value to make it positive
    for (int iteration_count = 0; function_value*function_value > 1.e-10; ++iteration_count){
        //update current x 
        current_x -= f(current_x)/deriv(current_x); 
        //calculate new function value 
        function_value = f(current_x); 
    }
    //print results 
    cout << "Function is " << f(current_x) << " at " << current_x << endl; 
    return 0; 
}
double f( double x){return x*x-2;}
double deriv(double x){return 2*x;}
