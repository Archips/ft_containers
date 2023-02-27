/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:07:17 by athirion          #+#    #+#             */
/*   Updated: 2023/02/27 18:15:47 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/vector.hpp"
# include "includes/stack.hpp"
# include "includes/map.hpp"
# include "includes/set.hpp"
# include <vector>
# include <map>
# include <stack>
# include <set>
# include <deque>
#include <iostream>

/* #ifndef NAMESPACE */
/* # define NAMESPACE ft */
/* #else */
/* # define NAMESPACE std */
/* #endif */

using namespace NAMESPACE;

void stack_constructor(void) {

	std::cout << ">>> STACK CONTRUCTOR <<<\n" << std::endl;

	std::deque<int> mydeque (3,100);          // deque with 3 elements
	vector<int> myvector (2,200);        // vector with 2 elements

	stack<int> first;                    // empty stack
	stack<int, std::deque<int> > second(mydeque);         // stack initialized to copy of deque

	stack<int, vector<int> > third;  // empty stack using vector
	stack<int, vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	std::cout << std::endl;

}

void stack_empty(void) {

	std::cout << ">>> STACK EMPTY <<<\n" << std::endl;
	
	stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';

	std::cout << std::endl;

}

void stack_size(void) {

	std::cout << ">>> STACK SIZE <<<\n" << std::endl;
	
	stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

	std::cout << std::endl;

}

void stack_top(void) {

	std::cout << ">>> STACK TOP <<<\n" << std::endl;
	
	stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';

	std::cout << std::endl;

}

void stack_push(void) {

	std::cout << ">>> STACK PUSH <<<\n" << std::endl;
	
	std::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

	std::cout << std::endl;

}

void stack_pop(void) {

	std::cout << ">>> STACK POP <<<\n" << std::endl;
	
	stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

	std::cout << std::endl;

}

void stack_relational_op(void) {

	std::cout << ">>> STACK RELATIONAL OPERATORS <<<\n" << std::endl;
	
	stack<int> stack1;
	stack<int> stack2;
	stack<int> stack3;

	for (int i = 0; i < 5; ++i) stack1.push(i);
	for (int i = 5; i > 0; --i) stack2.push(i);
	for (int i = 0; i < 5; ++i) stack3.push(i);

	if (stack1 == stack2)
		std::cout << "stack1 is equal to stack2" << std::endl;
	if (stack1 != stack2)
		std::cout << "stack1 is not equal to stack2" << std::endl;
	if (stack1 >= stack2)
		std::cout << "stack1 is greater or equal to stack2" << std::endl;
	if (stack1 > stack2)
		std::cout << "stack1 is greater than stack2" << std::endl;
	if (stack1 <= stack2)
		std::cout << "stack2 is greater or equal to stack1" << std::endl;
	if (stack1 < stack2)
		std::cout << "stack2 is greater than stack1" << std::endl;

	std::cout << "-----------------------" << std::endl;

	if (stack1 == stack3)
		std::cout << "stack1 is equal to stack3" << std::endl;
	if (stack1 != stack3)
		std::cout << "stack1 is not equal to stack3" << std::endl;
	if (stack1 >= stack3)
		std::cout << "stack1 is greater or equal to stack3" << std::endl;
	if (stack1 > stack3)
		std::cout << "stack1 is greater than stack3" << std::endl;
	if (stack1 <= stack3)
		std::cout << "stack3 is greater or equal to stack1" << std::endl;
	if (stack1 < stack3)
		std::cout << "stack3 is greater than stack1" << std::endl;

	std::cout << std::endl;

}

void vector_constructor(void) {

	std::cout << ">>> VECTOR CONSTRUCTOR <<<\n" << std::endl;
	
	vector<int> first;                                // empty vector of ints
	vector<int> second (4,100);                       // four ints with value 100
	vector<int> third (second.begin(),second.end());  // iterating through second
	vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of first are:";
	for (vector<int>::iterator it = first.begin(); it != first.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of second are:";
	for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of third are:";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of fourth are:";
	for (vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of fifth are:";
	for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}


void vector_assignment_op(void) {

	std::cout << ">>> VECTOR ASSIGNMENT OPERATOR <<<\n" << std::endl;
	
	vector<int> foo (3,0);
	vector<int> bar (5,0);

	bar = foo;
	foo = vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';

	std::cout << std::endl;
}

void vector_begin(void) {

	std::cout << ">>> VECTOR BEGIN <<<\n" << std::endl;
	
	vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_end(void) {

	std::cout << ">>> VECTOR END <<<\n" << std::endl;
	
	vector<int> myvector(6);
	for (int i=0; i<=5; i++) myvector.at(i) = i;

	std::cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_rbegin(void) {

	std::cout << ">>> VECTOR RBEGIN <<<\n" << std::endl;
	
	vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
	*rit = ++i;

	std::cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_rend(void) {

	std::cout << ">>> VECTOR REND <<<\n" << std::endl;
	
	vector<int> myvector(6);
	for (int i=0; i<=5; i++) myvector.at(i) = i;

	std::cout << "myvector contains:";
	vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_size(void) {

	std::cout << ">>> VECTOR SIZE <<<\n" << std::endl;
	
	vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';

	std::cout << std::endl;
}

void vector_max_size(void) {

	std::cout << ">>> VECTOR MAX_SIZE <<<\n" << std::endl;
	
	vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";

	std::cout << std::endl;
}

void vector_resize(void) {

	std::cout << ">>> VECTOR RESIZE <<<\n" << std::endl;
	
	vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (size_t i =0; i < myvector.size(); i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_capacity(void) {

	std::cout << ">>> VECTOR CAPACITY <<<\n" << std::endl;
	
	vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';

	std::cout << std::endl;
}

void vector_empty(void) {

	std::cout << ">>> VECTOR EMPTY <<<\n" << std::endl;
	
	vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';

	std::cout << std::endl;
}

void vector_reserve(void) {

	std::cout << ">>> VECTOR RESERVE <<<\n" << std::endl;
	
	vector<int>::size_type sz;

	vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
	foo.push_back(i);
	if (sz!=foo.capacity()) {
		sz = foo.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
	bar.push_back(i);
	if (sz!=bar.capacity()) {
		sz = bar.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::cout << std::endl;
}

void vector_accessor(void) {

	std::cout << ">>> VECTOR OPERATOR[] <<<\n" << std::endl;
	
	vector<int> myvector (10);   // 10 zero-initialized elements

	vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
	int temp;
	temp = myvector[sz-1-i];
	myvector[sz-1-i]=myvector[i];
	myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_at(void) {

	std::cout << ">>> VECTOR AT <<<\n" << std::endl;
	
	vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
	myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	std::cout << ' ' << myvector.at(i);
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_front(void) {

	std::cout << ">>> VECTOR FRONT <<<\n" << std::endl;
	
	vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';

	std::cout << std::endl;
}

void vector_back(void) {

	std::cout << ">>> VECTOR BACK <<<\n" << std::endl;
	
	vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
	myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << std::endl;
}

// void vector_data(void) {

// 	std::cout << ">>> VECTOR DATA <<<\n" << std::endl;
	
// 	vector<int> myvector (5);

// 	int* p = myvector.data();

// 	*p = 10;
// 	++p;
// 	*p = 20;
// 	p[2] = 100;

// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size(); ++i)
// 	std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	std::cout << std::endl;
// }

void vector_assign(void) {

	std::cout << ">>> VECTOR ASSIGN <<<\n" << std::endl;
	
	vector<int> first;
	vector<int> second;
	vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';

	std::cout << std::endl;
}

void vector_push_back(void) {

	std::cout << ">>> VECTOR PUSH_BACK <<<\n" << std::endl;
	
    vector<std::string> letters;
 
    letters.push_back("abc");
    std::string s = "def";
    letters.push_back(s);
	letters.push_back("ghi");

    std::cout << "vector `letters` holds: ";
	vector<std::string>::iterator it = letters.begin();
	vector<std::string>::iterator ite = letters.end();
    for (; it != ite; it ++) 
		std::cout << *it << ' ';

	std::cout << std::endl;
}

void vector_pop_back(void) {

	std::cout << ">>> VECTOR POP_BACK <<<\n" << std::endl;
	
	vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
	sum+=myvector.back();
	myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';

	std::cout << std::endl;
}

void vector_insert(void) {

	std::cout << ">>> VECTOR INSERT <<<\n" << std::endl;
	
	vector<int> myvector (3,100);
	vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_erase(void) {

	std::cout << ">>> VECTOR ERASE <<<\n" << std::endl;
	
	vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_swap(void) {

	std::cout << ">>> VECTOR SWAP <<<\n" << std::endl;
	
	vector<int> foo (3,100);   // three ints with a value of 100
	vector<int> bar (5,200);   // five ints with a value of 200

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	std::cout << ' ' << bar[i];
	std::cout << '\n';

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	std::cout << ' ' << bar[i];
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_clear(void) {

	std::cout << ">>> VECTOR CLEAR <<<\n" << std::endl;
	
	vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << std::endl;
}

void vector_get_allocator(void) {

	std::cout << ">>> VECTOR GET_ALLOCATOR <<<\n" << std::endl;
	
	vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);

	std::cout << std::endl;
}

void vector_relational_op(void) {

	std::cout << ">>> VECTOR RELATIONAL OPERATOR <<<\n" << std::endl;
	
	vector<int> foo (3,100);   // three ints with a value of 100
	vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl;
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void map_constructor(void) {

	std::cout << ">>> MAP CONSTRUCTORS <<<\n" << std::endl;
	
	map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	map<char,int> second (first.begin(),first.end());

	map<char,int> third (second);

	map<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	std::cout << std::endl;
}

void map_assignment_op(void) {

	std::cout << ">>> MAP ASSIGNMENT OPERATOR <<<\n" << std::endl;
	
	map<char,int> first;
	map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second = first;                // second now contains 3 ints
	first = map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';

	std::cout << std::endl;
}

void map_begin_end(void) {

	std::cout << ">>> MAP BEGIN END <<<\n" << std::endl;
	
	map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;
}

void map_rbegin_rend(void) {

	std::cout << ">>> MAP RBEGIN REND <<<\n" << std::endl;
	
	map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
	std::cout << rit->first << " => " << rit->second << '\n';

	std::cout << std::endl;
}

void map_empty(void) {

	std::cout << ">>> MAP EMPTY <<<\n" << std::endl;
	
	map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
	std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
	mymap.erase(mymap.begin());
	}

	std::cout << std::endl;
}

void map_size(void) {

	std::cout << ">>> MAP SIZE <<<\n" << std::endl;
	
	map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';

	mymap.erase('b');

	std::cout << "mymap.size() is " << mymap.size() << '\n';

	std::cout << std::endl;
}

void map_max_size(void) {

	std::cout << ">>> MAP MAX SIZE <<<\n" << std::endl;
	
	int i;
	map<int,int> mymap;

	if (mymap.max_size()>100000)
	{
		for (i=0; i<100000; i++) mymap[i]=0;
			std::cout << "The map contains 100000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";

	std::cout << std::endl;
}

void map_accessor(void) {

	std::cout << ">>> MAP ACCESSOR <<<\n" << std::endl;
	
	map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";

	std::cout << std::endl;
}

/* void map_at(void) { */

/* 	std::cout << ">>> MAP AT <<<\n" << std::endl; */
	
/* 	map<std::string,int> mymap; */

/* 	mymap.insert(pair<std::string, int>("alpha", 0)); */
/* 	mymap.insert(pair<std::string, int>("beta", 0)); */
/* 	mymap.insert(pair<std::string, int>("gamma", 0)); */

/* 	mymap.at("alpha") = 10; */
/* 	mymap.at("beta") = 20; */
/* 	mymap.at("gamma") = 30; */

/* 	map<std::string, int>::iterator it = mymap.begin(); */
/* 	map<std::string, int>::iterator ite = mymap.end(); */

/* 	for (; it != ite; ++it) { */
/* 		std::cout << it->first << ": " << it->second << '\n'; */
/* 	} */

/* 	std::cout << std::endl; */
/* } */

void map_insert(void) {

	std::cout << ">>> MAP INSERT <<<\n" << std::endl;
	
	map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert (pair<char,int>('a',100) );
	mymap.insert (pair<char,int>('z',200) );

	pair<map<char,int>::iterator,bool> ret;
	ret = mymap.insert (pair<char,int>('z',500) );
	if (ret.second==false) {
	std::cout << "element 'z' already existed";
	std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;
}

void map_erase(void) {

	std::cout << ">>> MAP ERASE <<<\n" << std::endl;
	
	map<char,int> mymap;
	map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;
}

void map_swap(void) {

	std::cout << ">>> MAP SWAP <<<\n" << std::endl;
	
	map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;
}

void map_clear(void) {

	std::cout << ">>> MAP CLEAR <<<\n" << std::endl;
	
	map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;
}

void map_key_comp(void) {

	std::cout << ">>> MAP KEY COMP <<<\n" << std::endl;
	
	map<char,int> mymap;

	map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	map<char,int>::iterator it = mymap.begin();
	do {
	std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

	std::cout << std::endl;
}

void map_value_comp(void) {

	std::cout << ">>> MAP VALUE COMP <<<\n" << std::endl;
	
	map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	pair<char,int> highest = *mymap.rbegin();          // last element

	map<char,int>::iterator it = mymap.begin();
	do {
	std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );

	std::cout << std::endl;
}

void map_find(void) {

	std::cout << ">>> MAP FIND <<<\n" << std::endl;
	
	map<char,int> mymap;
	map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
	mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';

	std::cout << std::endl;
}

void map_count(void) {

	std::cout << ">>> MAP COUNT <<<\n" << std::endl;
	
	map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
	std::cout << c;
	if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
	else 
		std::cout << " is not an element of mymap.\n";
	}

	std::cout << std::endl;
}

void map_lower_upper_bound(void) {

	std::cout << ">>> MAP LOWERBOUND UPPERBOUND <<<\n" << std::endl;
	
	map<char,int> mymap;
	map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;
}

void map_equal_range(void) {

	std::cout << ">>> MAP EQUAL RANGE <<<\n" << std::endl;
	
	map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	pair<map<char,int>::iterator, map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	std::cout << std::endl;
}

void map_get_allocator(void) {

	std::cout << ">>> MAP GET ALLOCATOR <<<\n" << std::endl;
	
	int psize;
	map<char,int> mymap;
	pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p = mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);

	std::cout << std::endl;
}

void map_relational_op(void) {

	std::cout << ">>> MAP RELATIONAL OPERATORS <<<\n" << std::endl;
	
    map<int, char> alice;
	alice[1] = 'a';
	alice[2] = 'b';
	alice[3] = 'c';
    map<int, char> bob;
	bob[7] = 'Z';
	bob[8] = 'Y';
	bob[9] = 'X';
	bob[10] = 'W';
    map<int, char> eve;
	eve[1] = 'a';
	eve[2] = 'b';
	eve[3] = 'c';
 
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
	 ** STACK
	 */

	stack_constructor();
	stack_empty();
	stack_size();
	stack_top();
	stack_push();
	stack_pop();
	stack_relational_op();

	/*
	** VECTOR
	*/

	vector_constructor();
	vector_assignment_op();
	vector_begin();
	vector_end();
	vector_rbegin();
	vector_rend();
	vector_size();
	vector_max_size();
	vector_resize();
	vector_capacity();
	vector_empty();
	vector_reserve();
	vector_accessor();
	vector_at();
	vector_front();
	vector_back();
	// vector_data();
	vector_assign();
	vector_push_back();
	vector_pop_back();
	vector_insert();
	vector_erase();
	vector_swap();
	vector_clear();
	vector_get_allocator();
	vector_relational_op();

	/*
	** MAP
	*/

	map_constructor();
	map_assignment_op();
	map_begin_end();
	map_rbegin_rend();
	map_empty();
	map_size();
	map_max_size();
	map_accessor();
	/* map_at(); */
	map_insert();
	map_erase();
	map_swap();
	map_clear();
	map_key_comp();
	map_value_comp();
	map_find();
	map_count();
	map_lower_upper_bound();
	map_equal_range();
	map_get_allocator();
	map_relational_op();

}
