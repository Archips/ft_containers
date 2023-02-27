/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonMemberSwap_main.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2023/02/27 09:31:29 by athirion         ###   ########.fr       */
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
  int myints[]={12,75,10,32,20,25};
  set<int> first (myints,myints+3);     // 10,12,75
  set<int> second (myints+3,myints+6);  // 20,25,32

  swap(first,second);

  cout << "first contains:";
  for (set<int>::iterator it=first.begin(); it!=first.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  cout << "second contains:";
  for (set<int>::iterator it=second.begin(); it!=second.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}
