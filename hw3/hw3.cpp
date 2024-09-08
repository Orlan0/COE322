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


// REAL HOMEWORK 3 


int num_w_highest_iteration = 0; 
int max_iteration = 0; 

for (int x =1; x < 1000; x++) {

   int og_x = x; 
   int iteration = 1; 

while (x !=1) {
    if (x%2 == 0){
      x = x/2; 
 }
   else {
      x = 3*x +1; 
   }
   iteration ++;
}


if (iteration > max_iteration){
   max_iteration = iteration; 
   num_w_highest_iteration = og_x; 
   cout << num_w_highest_iteration << " took " << max_iteration << " iterations " << endl; 

}
   x = og_x; 


}

   cout << "At the very very end: " << num_w_highest_iteration << " took " << max_iteration << " iterations " << endl; 


}
