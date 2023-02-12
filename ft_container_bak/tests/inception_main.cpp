/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inception_main.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2023/02/12 12:09:43 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "../includes/vector.hpp"

# define NAMESPACE ft

using namespace NAMESPACE;

int main()
{
	vector<int>			test(3, 3);

	cout << "self assignation test\n";
	vector<vector<int> >	self_assign;
	vector<vector<int> >	*ptr = &self_assign;
	vector<vector<int> >	*ptr2 = &self_assign;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#1] <<<<<<<<<<<<<<<<<" << std::endl;
	self_assign.assign(4, test);
	*ptr = *ptr2;

	cout << std::boolalpha << (*ptr == *ptr2) << '\n';
//	self_assign = self_assign; //compiler doesn't like it!



	vector<vector<int> > JOHN;
	vector<vector<int> > BOB(5, test);
	cout << "BOB(5, test(test, 5)) : \n";
	for (size_t i = 0; i < BOB.size(); i++)
	{
		for (size_t j = 0; j < BOB[i].size(); j++)
			cout << BOB[i][j] << ' ';
		cout << '\n';
	}
	vector<vector<int> > MIKE(BOB);

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#2] <<<<<<<<<<<<<<<<<" << std::endl;
	// CTORs
	cout << "\nCTORS\n";
	cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	cout << "BOB is empty? " << BOB.empty() << '\n';

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#3] <<<<<<<<<<<<<<<<<" << std::endl;
	// RESIZE
	size_t	bob_resize = 2;
	cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#4] <<<<<<<<<<<<<<<<" << std::endl;
	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, test);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
		{
			cout << MIKE[i][j] << ' ';
		}
	cout << std::endl;
	}

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#5] <<<<<<<<<<<<<<<<<" << std::endl;

	// RESERVE
	cout << "\nRESERVE\n";

	size_t	john_reserve = 0;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 4;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#6] <<<<<<<<<<<<<<<<<" << std::endl;
	//AT
	cout << "\nAT\n";
	try
	{
		cout << MIKE.at(2).front() << '\n';
		cout << MIKE.at(87).back() << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		cout << "OOR error caught\n";
	}
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#7] <<<<<<<<<<<<<<<<<" << std::endl;

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#8] <<<<<<<<<<<<<<<<<" << std::endl;
	//ASSIGN
	cout << "\nASSIGN\n";
	test.assign(3, 17);
	BOB.assign(3, test);
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#9] <<<<<<<<<<<<<<<<<" << std::endl;

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	vector<vector<int> >	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#10] <<<<<<<<<<<<<<<<<" << std::endl;

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "BOB is empty ? " << BOB.empty() << '\n';
	cout << "BOB at(1) : " << BOB.at(1).front() << '\n';
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#11] <<<<<<<<<<<<<<<<<" << std::endl;

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	test.assign(2, 42);
	BOB.push_back(test);
	cout << "last elem of BOB : " << BOB.back().back() << '\n';
	BOB.pop_back();
	cout << "last elem of BOB : " << BOB.back().back() << '\n';
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#12] <<<<<<<<<<<<<<<<<" << std::endl;

	//INSERT
	cout << "\nINSERT\n";
	vector<vector<int> >	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		vector<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			cout << insert_in_me.at(i).at(j) << ' ';
		cout << '\n';
	}
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#13] <<<<<<<<<<<<<<<<<" << std::endl;

	vector<vector<int> >::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, test);
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			cout << insert_in_me.at(i).at(j) << ' ';
		cout << '\n';
	}

	vector<vector<int> >::const_iterator const_it(insert_in_me.begin());
	cout << "Const it.front() : " << std::endl;
	cout << (*const_it).front() << '\n';

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#14] <<<<<<<<<<<<<<<<<" << std::endl;

	//INSERT
	cout << "\nINSERT\n";
	vector<vector<int> >	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		cout << std_insert_in_me.at(i).front() << ' ';
	cout << '\n';
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#15] <<<<<<<<<<<<<<<<<" << std::endl;

	vector<vector<int> >::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		cout << std_insert_in_me.at(i).back() << ' ';
	cout << '\n';
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#16] <<<<<<<<<<<<<<<<<" << std::endl;


	//INSERT RANGE
	cout << "\nINSERT RANGE\n";
	vector<vector<int> >	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		vector<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	for (size_t i = 0; i < insert_bis.size(); i++)
		cout << insert_bis[i].back() << ' ';
	cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		cout << insert_bis[i].back() << ' ';
	cout << '\n';

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#17] <<<<<<<<<<<<<<<<<" << std::endl;

	//ERASE
	cout << "\nERASE\n";
	vector<vector<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		vector<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	for (size_t i = 0; i < erase_in_me.size(); i++)
		cout << erase_in_me.at(i).front() << ' ';
	cout << '\n';
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#18] <<<<<<<<<<<<<<<<<" << std::endl;

	erase_in_me.erase(erase_in_me.begin() + 7);
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ERASEEEEEEE [1] <<<<<<<<<<<<<<<<<<<" <<std::endl;
	for (size_t i = 0; i < erase_in_me.size(); i++)
		cout << erase_in_me.at(i).front() << ' ';
	cout << '\n';
	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ERASEEEEEEE [2] <<<<<<<<<<<<<<<<<<<" <<std::endl;
	for (size_t i = 0; i < erase_in_me.size(); i++)
		cout << erase_in_me.at(i).front() << ' ';
	cout << '\n';
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#19] <<<<<<<<<<<<<<<<<" << std::endl;

	//SWAP
	cout << "\nSWAP\n";
	john_reserve = 4;
	JOHN.reserve(john_reserve);
	BOB.swap(MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#20] <<<<<<<<<<<<<<<<<" << std::endl;

	MIKE.swap(JOHN);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#21] <<<<<<<<<<<<<<<<<" << std::endl;

	//CLEAR
	cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#22] <<<<<<<<<<<<<<<<<" << std::endl;

	//NON MEMBER Functions
	cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [#23] <<<<<<<<<<<<<<<<<" << std::endl;
	
	//RELATIONAL OPERATORS
	cout << "\nRELATIONAL OPERATORS\n";
	vector<vector<int> > MIKE_2(MIKE);
	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	cout << "\nReal Vector\n";
	vector<vector<int> > real;
	real.assign(5, test);
	for (vector<vector<int> >::iterator it = real.begin(); it != real.end(); it++)
		cout << (*it).front() << " ";
	cout << '\n';

	cout << std::endl;
	return (0);
}

