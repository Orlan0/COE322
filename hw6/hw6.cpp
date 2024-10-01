//Name: Orlan Oconer 
//EID: ojo366
//TACC Username: orlan 

#include <cmath>
#include <iostream> 
#include <functional> 
#include <ranges>
#include <algorithm> 

using std::function;
using std::cout; 
using std::cin; 
using std::endl; 
using std::ranges::for_each; 
namespace rng = std::ranges;


//goal find the perfect numbers using ranges and algorithms 



int main (){
//this will generate all the numbers, starting form 2  
    
  //need to find the sum of the the divisors 
  auto sum = [](int i){
    auto divisors = rng::views::iota(1,i)
      //i is the values from iota, n is the value that keeps i in place, so for instance (1,1) n is 1 and i is 1, so
      // when dividing it takes into account of all the previous n value to the current i value in place
      |rng::views::filter([i](int n) {return i % n == 0;});


    // this takes the sum of the value above
    int instance_sum = 0; 
    rng::for_each ( divisors, [&instance_sum] (int i) {
      instance_sum += i;});
    return instance_sum; 
      };




  

  auto numbers = rng::views::iota(2); 

  auto perfect_numbers = numbers
    |rng::views::filter([&sum](int i){
      return sum(i) == i;
    })
    |rng::views::take(4); 
	

  //outputting the numbers 
    rng::for_each(perfect_numbers, [](int n) {
      cout<< n << endl;
    }); 

    return 0; 
      
}

      
