#include "../vector.hpp"
#include <iostream>

int main(void)
{
	ft::vector<int> first;
	ft::vector<int> copy(first);
	ft::vector<int> op;
	ft::vector<int> second(4, 100);
	ft::vector<int> third(second);
	op = copy;

	std::cout << "First size : " << first.size() << std::endl;
	std::cout << "Is first empty ? " << first.empty() << std::endl;

	second[2] = 300;

	for (int i = 0; i < 4; i ++)
		std::cout << second[i] << std::endl;

	std::cout << "Second size : " << second.size() << std::endl;
	std::cout << "Is second empty ? " << second.empty() << std::endl;

	copy = second;

	for (int i = 0; i < 4; i ++)
		std::cout << copy[i] << std::endl;

	for (int i = 0; i < 4; i++)
		std::cout << third[i] << std::endl;

	return (0);
}

