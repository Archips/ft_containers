#include "common.hpp"
#include "vector.hpp"

/*
single element (1)
	iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
*/

#define TESTED_NAMESPACE ft
#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct3;

	/* std::cout << "Vct size: [" << vct.size() << "]" << std::endl; */
	/* std::cout << "Vct2 size: [" << vct2.size() << "]" << std::endl; */
	/* std::cout << "Vct3 size: [" << vct3.size() << "]" << std::endl; */

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printSize(vct);

	/* std::cout << "Vct size: [" << vct.size() << "]" << std::endl; */
	/* std::cout << "Vct2 size: [" << vct2.size() << "]" << std::endl; */
	/* std::cout << "Vct3 size: [" << vct3.size() << "]" << std::endl; */
	
	vct2.insert(vct2.end(), 42);
	std::cout << "Vct size: [" << vct.size() << "]" << std::endl;
	std::cout << "Vct2 size: [" << vct2.size() << "]" << std::endl;
	std::cout << "Vct3 size: [" << vct3.size() << "]" << std::endl;
	
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);

	vct2.resize(4);
	printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printSize(vct2);

	printSize(vct);

	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	printSize(vct3);

	return (0);
}