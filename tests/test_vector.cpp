#include "../vector.hpp"
#include <iostream>

int main(void)
{
    /* { */
    /*     ft::vector<int> first; */
    /*     ft::vector<int> copy(first); */
    /*     ft::vector<int> op; */
    /*     ft::vector<int> second(4, 100); */
    /*     ft::vector<int> third(second); */
    /*     op = copy; */

    /*     std::cout << "First size : " << first.size() << std::endl; */
    /*     std::cout << "Is first empty ? " << first.empty() << std::endl; */

    /*     second[2] = 300; */

    /*     for (int i = 0; i < 4; i++) */
    /*         std::cout << second[i] << std::endl; */

    /*     std::cout << "Second size : " << second.size() << std::endl; */
    /*     std::cout << "Is second empty ? " << second.empty() << std::endl; */

    /*     copy = second; */

    /*     for (int i = 0; i < 4; i++) */
    /*         std::cout << copy[i] << std::endl; */

    /*     for (int i = 0; i < 4; i++) */
    /*         std::cout << third[i] << std::endl; */
    /* } */

    /* { */
    /*     ft::vector<int> myvector(100, 100); */

    /*     std::cout << "Size: " << (int) myvector.size() << std::endl; */
    /*     std::cout << "Capacity: " << myvector.capacity() << std::endl; */
    /*     std::cout << "Max size: " << myvector.max_size() << std::endl; */

    /* } */

	{

	 	ft::vector<int> myvector (10);   // 10 zero-initialized ints

  		// assign some values:
  		
		for (unsigned i=0; i<myvector.size(); i++)
   			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
  		std::cout << std::endl;

		std::cout << "First of myvector is: " << myvector.front() << std::endl;
		std::cout << "Last of myvector is: " << myvector.back() << std::endl;

	}

	{
		ft::vector<int> vectoooor;
	}

	return (0);
}

