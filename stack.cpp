/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:33:30 by athirion          #+#    #+#             */
/*   Updated: 2023/01/04 17:18:42 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <vector>

template < class T, class Container = std::vector<T> >
class Stack {


	public:
		
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		typedef Container						container_type;

	private:

};

#endif
