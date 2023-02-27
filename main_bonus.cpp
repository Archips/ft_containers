/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:07:17 by athirion          #+#    #+#             */
/*   Updated: 2023/02/27 17:36:18 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/set.hpp"
# include <set>
#include <iostream>

using namespace NAMESPACE;

void set_constructor(void) {

	std::cout << ">>> SET CONSTRUCTORS <<<\n" << std::endl;
	
	// (1) Default constructor
	set<std::string> a;
	a.insert("cat");
	a.insert("dog");
	a.insert("horse");
	set<std::string>::iterator it1 = a.begin();
	set<std::string>::iterator ite1 = a.end();
	for(; it1 != ite1; it1++) 
		std::cout << *it1 << ' ';
	std::cout << '\n';

	// (2) Iterator constructor
	set<std::string> b(a.find("dog"), a.end());
	set<std::string>::iterator it2 = b.begin();
	set<std::string>::iterator ite2 = b.end();
	for(; it2 != ite2; it2++) 
		std::cout << *it2 << ' ';
	std::cout << '\n';

	// (3) Copy constructor
	set<std::string> c(a);
	c.insert("another horse");
	set<std::string>::iterator it3 = c.begin();
	set<std::string>::iterator ite3 = c.end();
	for(; it3 != ite3; it3++) 
		std::cout << *it3 << ' ';
	std::cout << '\n';

	std::cout << std::endl;
}

void set_assignment_op(void) {

	std::cout << ">>> SET ASSIGNMENT OPERATOR <<<\n" << std::endl;
	
	int myints[]={ 12,82,37,64,15 };
	set<int> first (myints,myints+5);   // set with 5 ints
	set<int> second;                    // empty set

	second = first;                          // now second contains the 5 ints
	first = set<int>();                 // and first is empty

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';

	std::cout << std::endl;
}

void set_begin_end(void) {

	std::cout << ">>> SET BEGIN END <<<\n" << std::endl;
	
	int myints[] = {75,23,65,42,13};
	set<int> myset (myints,myints+5);

	std::cout << "myset contains:";
	for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;

	std::cout << '\n';

	std::cout << std::endl;
}

void set_rbegin_rend(void) {

	std::cout << ">>> SET RBEGIN REND <<<\n" << std::endl;
	
	int myints[] = {21,64,17,78,49};
	set<int> myset (myints,myints+5);

	set<int>::reverse_iterator rit;

	std::cout << "myset contains:";
	for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
	std::cout << ' ' << *rit;

	std::cout << '\n';


	std::cout << std::endl;
}

void set_empty(void) {

	std::cout << ">>> SET EMPTY <<<\n" << std::endl;
	
	set<int> myset;

	myset.insert(20);
	myset.insert(30);
	myset.insert(10);

	std::cout << "myset contains:";
	while (!myset.empty())
	{
		std::cout << ' ' << *myset.begin();
		myset.erase(myset.begin());
	}
	std::cout << '\n';

	std::cout << std::endl;
}

void set_size(void) {

	std::cout << ">>> SET SIZE <<<\n" << std::endl;
	
	set<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; ++i) myints.insert(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.erase(5);
	std::cout << "3. size: " << myints.size() << '\n';

	std::cout << std::endl;
}

void set_max_size(void) {

	std::cout << ">>> SET MAX_SIZE <<<\n" << std::endl;
	
	int i;
	set<int> myset;

	if (myset.max_size()>1000)
	{
	for (i=0; i<1000; i++) myset.insert(i);
	std::cout << "The set contains 1000 elements.\n";
	}
	else std::cout << "The set could not hold 1000 elements.\n";

	std::cout << std::endl;
}

void set_insert(void) {

	std::cout << ">>> SET INSERT <<<\n" << std::endl;
	
	set<int> myset;
	set<int>::iterator it;
	pair<set<int>::iterator,bool> ret;

	// set some initial values:
	for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

	ret = myset.insert(20);               // no new element inserted

	if (ret.second==false) it=ret.first;  // "it" now points to element 20

	myset.insert (it,25);                 // max efficiency inserting
	myset.insert (it,24);                 // max efficiency inserting
	myset.insert (it,26);                 // no max efficiency inserting

	int myints[]= {5,10,15};              // 10 already in set, not inserted
	myset.insert (myints,myints+3);

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void set_erase(void) {

	std::cout << ">>> SET ERASE <<<\n" << std::endl;
	
	set<int> myset;
	set<int>::iterator it;

	// insert some values:
	for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

	it = myset.begin();
	++it;                                         // "it" points now to 20

	myset.erase (it);

	myset.erase (40);

	it = myset.find (60);
	myset.erase (it, myset.end());

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void set_swap(void) {

	std::cout << ">>> SET SWAP <<<\n" << std::endl;
	
	int myints[]={12,75,10,32,20,25};
	set<int> first (myints,myints+3);     // 10,12,75
	set<int> second (myints+3,myints+6);  // 20,25,32

	first.swap(second);

	std::cout << "first contains:";
	for (set<int>::iterator it=first.begin(); it!=first.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (set<int>::iterator it=second.begin(); it!=second.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void set_clear(void) {

	std::cout << ">>> SET CLEAR <<<\n" << std::endl;
	
	set<int> myset;

	myset.insert (100);
	myset.insert (200);
	myset.insert (300);

	std::cout << "myset contains:";
	for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	myset.clear();
	myset.insert (1101);
	myset.insert (2202);

	std::cout << "myset contains:";
	for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void set_key_comp(void) {

	std::cout << ">>> SET KEY COMP <<<\n" << std::endl;

	set<int> myset;
	int highest;

	set<int>::key_compare mycomp = myset.key_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	highest=*myset.rbegin();
	set<int>::iterator it=myset.begin();
	do {
	std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';

	std::cout << std::endl;
}

void set_value_comp(void) {

	std::cout << ">>> SET VALUE COMP <<<\n" << std::endl;

	set<int> myset;

	set<int>::value_compare mycomp = myset.value_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	int highest=*myset.rbegin();
	set<int>::iterator it=myset.begin();
	do {
	std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';

	std::cout << std::endl;
}

void set_find(void) {

	std::cout << ">>> SET FIND <<<\n" << std::endl;

	set<int> myset;
	set<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

	it=myset.find(20);
	myset.erase (it);
	myset.erase (myset.find(40));

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void set_count(void) {

	std::cout << ">>> SET COUNT <<<\n" << std::endl;

	set<int> myset;

	// set some initial values:
	for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

	for (int i=0; i<10; ++i)
	{
	std::cout << i;
	if (myset.count(i)!=0)
		std::cout << " is an element of myset.\n";
	else
		std::cout << " is not an element of myset.\n";
	}

	std::cout << std::endl;
}

void set_lower_upper_bound(void) {

	std::cout << ">>> SET LOWERBOUND UPPERBOUND <<<\n" << std::endl;

	set<int> myset;
	set<int>::iterator itlow,itup;

	for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

	itlow=myset.lower_bound (30);                //       ^
	itup=myset.upper_bound (60);                 //                   ^

	myset.erase(itlow,itup);                     // 10 20 70 80 90

	std::cout << "myset contains:";
	for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void set_equal_range(void) {

	std::cout << ">>> SET LOWERBOUND UPPERBOUND <<<\n" << std::endl;

	set<int> myset;

	for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

	pair<set<int>::const_iterator,set<int>::const_iterator> ret;
	ret = myset.equal_range(30);

	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';

	std::cout << std::endl;
}

void set_get_allocator(void) {

	std::cout << ">>> SET GET ALLOCATOR <<<\n" << std::endl;

	set<int> myset;
	int * p;
	unsigned int i;

	// allocate an array of 5 elements using myset's allocator:
	p=myset.get_allocator().allocate(5);

	// assign some values to array
	for (i=0; i<5; i++) p[i]=(i+1)*10;

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	myset.get_allocator().deallocate(p,5);

	std::cout << std::endl;
}

void set_relational_op(void) {

	std::cout << ">>> SET RELATIONAL OPERATORS <<<\n" << std::endl;

    set<int> alice;
	alice.insert(1);
	alice.insert(2);
	alice.insert(3);
    set<int> bob;
	bob.insert(7);
	bob.insert(8);
	bob.insert(9);
	bob.insert(10);
    set<int> eve;
	eve.insert(1);
	eve.insert(2);
	eve.insert(3);
 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';

	std::cout << std::endl;
}

int main()
{

	/*
	** SET
	*/

	set_constructor();
	set_assignment_op();
	set_begin_end();
	set_rbegin_rend();
	set_empty();
	set_size();
	set_max_size();
	set_insert();
	set_erase();
	set_swap();
	set_clear();
	set_key_comp();
	set_value_comp();
	set_find();
	set_count();
	set_lower_upper_bound();
	set_equal_range();
	set_get_allocator();
	set_relational_op();

}
