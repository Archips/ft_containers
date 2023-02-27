/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyComp_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2023/02/27 09:29:29 by athirion         ###   ########.fr       */
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
  int highest;

  set<int>::key_compare mycomp = myset.key_comp();

  for (int i=0; i<=5; i++) myset.insert(i);

  cout << "myset contains:";

  highest=*myset.rbegin();
  set<int>::iterator it=myset.begin();
  do {
    cout << ' ' << *it;
  } while ( mycomp(*(++it),highest) );

  cout << '\n';

  return 0;
}
