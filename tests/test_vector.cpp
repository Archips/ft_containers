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
		std::cout << "Size of myvector is: " << myvector.size() << std::endl;
		myvector.pop_back();
		std::cout << "Last of myvector is: " << myvector.back() << std::endl;
		std::cout << "Size of myvector is: " << myvector.size() << std::endl;
		
		myvector.clear();

		for (unsigned i=0; i<myvector.size(); i++)
   			myvector.at(i)=i;
		std::cout << "-------------------------------" << std::endl;
		std::cout << "First of myvector is: " << myvector.front() << std::endl;
		std::cout << "Last of myvector is: " << myvector.back() << std::endl;
		std::cout << "Size of myvector is: " << myvector.size() << std::endl;
		std::cout << "-------------------------------" << std::endl;

		std::cout << "End of scope" << std::endl;
	}

	{
		ft::vector<int> vectoooor;
	}

	{
		ft::vector<int> myvector(5);
		myvector[0] = 1; 
		myvector[1] = 2;
		myvector[2] = 3;
		myvector[3] = 0;
		myvector[4] = 0;

		for (unsigned i = 0; i < myvector.size(); i ++)
			std::cout << ' ' << myvector.at(i);

		std::cout << std::endl;

		std::cout << "my vector capacity : " << myvector.capacity() << std::endl;

		myvector.resize(2);

		for (unsigned i = 0; i < myvector.size(); i ++)
			std::cout << ' ' << myvector.at(i);
	
		std::cout << std::endl;

		std::cout << "my vector capacity : " << myvector.capacity() << std::endl;

		myvector.resize(5);

		for (unsigned i = 0; i < myvector.size(); i ++)
			std::cout << ' ' << myvector.at(i);

		std::cout << std::endl;
		
		std::cout << "my vector capacity : " << myvector.capacity() << std::endl;
		
		myvector.resize(7, 10);

		for (unsigned i = 0; i < myvector.size(); i ++)
			std::cout << ' ' << myvector.at(i);
		
		std::cout << std::endl;

		std::cout << "my vector capacity : " << myvector.capacity() << std::endl;
		
		std::cout << std::endl;


	}

	return (0);
}

