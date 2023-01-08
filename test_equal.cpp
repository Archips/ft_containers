#include "equal.hpp"
#include <iostream>     // std::cout
#include <vector>       // std::vector

int main (void) {

  int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
  std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

  myvector[3]=81;                                 // myvector: 20 40 60 81 100
  
  // using default comparison:
  if ( ft::equal (myvector.begin(), myvector.end(), myints) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";


// TEST WITH PRED DOESN'T WORK //
// TODO

  // using predicate comparison:
  /* if ( ft::equal (myvector.begin(), myvector.end(), myints, ft::pred) ) */
  /*   std::cout << "The contents of both sequences are equal.\n"; */
  /* else */
  /*   std::cout << "The contents of both sequences differ.\n"; */

  return 0;
}

