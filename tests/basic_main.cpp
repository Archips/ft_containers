/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:07:47 by hbaudet           #+#    #+#             */
/*   Updated: 2023/02/21 14:05:34 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "../includes/map.hpp"

# define NAMESPACE ft

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}

int main()
{
	pair<int, string>			my_pair(8, "salut");
	map<int, string>			test;
	map<int, string>::iterator	it;

	test.insert(my_pair);
	std::cout << "after first insert" << std::endl;
	test.insert(pair<int, string>(-4, "bar"));
	std::cout << "after #2 insert" << std::endl;
	test.insert(pair<int, string>(2, "machin"));
	std::cout << "after #3 insert" << std::endl;
	test.insert(pair<int, string>(3, "foo"));
	std::cout << "after #4 insert" << std::endl;
	test.insert(pair<int, string>(746, "Marcel"));
	std::cout << "after #5 insert" << std::endl;
	/* test.insert(pair<int, string>(1, "truc")); */
	std::cout << "after insert" << std::endl;
	it = test.begin();
	map<int, string>::iterator ite = test.end();
	std::cout << "test.begin() -> " << it->first << " | " << it->second << std::endl;
	std::cout << "test.end() -> " << ite->first << " | " << ite->second << std::endl;
	cout << '\n';

	while (it != test.end())
	{
		cout << "start of while\n";
		cout << it->first << ", " << it->second << '\n';
		it++;
 		cout << "iterator incremented\n";

// #ifndef STD
// 		cout << it.getPointer() << '\n';
// 		cout << test.end().getPointer() << '\n';
// #endif

	}
	cout << "End of display loop\n";
}
