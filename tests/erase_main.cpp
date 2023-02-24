/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2023/02/24 10:17:03 by athirion         ###   ########.fr       */
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
		cout << it->first << " => " << it->second << '\n';
}

int main ()
{
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
  cout << "found b\n";
  mymap.erase (it);                   // erasing by iterator
  cout << "erase iterator to b\n";
  mymap.erase ('c');                  // erasing by key
  cout << "erase by key 'c'\n";
  it=mymap.find ('e');
  cout << "erase by range 'e' to end\n";
  mymap.erase ( it, mymap.end() );    // erasing by range

  cout << " display :\n";
  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  return 0;
}
