 //Write a loop that prints x = 1/10,2/10,...,1. Do this
 //• with an integer loop variable
 //• with a float or double loop variable
 // How do you do the stopping test?
 // What do you observe?


#include <iostream> 

using std::cout; 
using std::cin; 
using std::endl; 


int main(){
cout << "This is an int loop" <<endl; 
for (int y = 1; y < 11; y++){ 
   cout << (y/10.) << endl; 
}
cout << "This is an float loop" <<endl; 
for (float y = .1; y < 1.1; y+=0.1){
   cout << y << endl; 
}
cout << "This is an double loop" <<endl; 
for (double z = 0.1; z < 1; z+= 0.1){
   cout << z << endl; 
}
}

