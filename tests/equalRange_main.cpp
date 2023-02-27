/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalRange_main.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2023/02/27 08:51:15 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"
#include "../includes/set.hpp"

# define NAMESPACE ft

using namespace NAMESPACE;

template <class T>
void	print(set<T>& lst)
{
	for (typename set<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  set<int> myset;

  for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

  pair<set<int>::const_iterator,set<int>::const_iterator> ret;
  ret = myset.equal_range(30);

  cout << "the lower bound points to: " << *ret.first << '\n';
  cout << "the upper bound points to: " << *ret.second << '\n';

  return 0;
}
