// reverse_iterator::operator- example
#include <iostream>     // std::cout
#include "../reverse_iterator.hpp"     // std::reverse_iterator
#include "../vector.hpp"       // std::vector
#include "../iterator_traits.hpp"

int main()
{
    const int a1[]{0, 1, 2};
    int a2[]{0, 1, 2, 3};
    short a3[]{40, 41, 42};

    ft::reverse_iterator<const int*> it1{std::crbegin(a1)};
    it1 = ft::reverse_iterator<int*>{ft::rbegin(a2)};   // OK
//  it1 = std::reverse_iterator<short*>{std::rbegin(a3)}; // compilation error:
                                                          // incompatible pointer types
    ft::reverse_iterator<short const*> it2{nullptr};
    it2 = ft::rbegin(a3); // OK
//  it2 = std::begin(a3);  // compilation error: no viable overloaded '='
    std::cout << *it2 << '\n';
}

/* int main () { */
/*   std::vector<int> myvector; */
/*   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9 */

/*   typedef std::vector<int>::iterator iter_type; */

/*   ft::reverse_iterator<iter_type> rev_iterator; */

/*   rev_iterator = myvector.rend() - 3; */

/*   std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n'; */

/*   return 0; */
/* } */
