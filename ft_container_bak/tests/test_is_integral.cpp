#include "../is_integral.hpp"
#include <iostream>
#include <string>
/* #include <type_traits> */

int main(void) {
  /* std::cout << std::boolalpha; */
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << ft::is_integral<char>::value << std::endl;
  std::cout << "string: " << ft::is_integral<std::string>::value << std::endl;
  std::cout << "int: " << ft::is_integral<int>::value << std::endl;
  std::cout << "float: " << ft::is_integral<float>::value << std::endl;
  std::cout << "long long int: " << ft::is_integral<long long int>::value << std::endl;
  return 0;
}

