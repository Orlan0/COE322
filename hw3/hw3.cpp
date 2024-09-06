
#include <iostream> 

using std::cout; 
using std::cin; 
using std::endl; 






int main(){


// REAL HOMEWORK 3 

 int x; 
 cout << "give me a number please: .\n"; 
 cin >> x;
 int iteration = 0; 


while (x !=1) {
   int xnew; 
    if (x%2 == 0){
      xnew = x/2; 
      cout << xnew << endl; 
 }
   else {
      xnew = 3*x +1; 
      cout << xnew << endl; 
   }
   x = xnew; 
   iteration ++;
}


cout << "it took " << iteration << " iterations to finish" << endl; 

}
/*
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
}*/

