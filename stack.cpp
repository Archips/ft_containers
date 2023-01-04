/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:33:30 by athirion          #+#    #+#             */
/*   Updated: 2023/01/04 17:44:31 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <vector>

template < class T, class Container = std::vector<T> >
class Stack {


	public:
		
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;
		typedef Container							container_type;

		Stack(void);
		Stack(const Stack<Container<T>> &src);
		~Stack(void);

		Stack<Container<T>>	&operator=(const Stack<Container<T>> &rhs);

		// TOP

		reference 		top();
		const_reference	top() const;

		// EMPTY
		
		bool			empty() const;

		//SIZE
		
		size_type		size() const;

		//PUSH

		void			push(const value_type& value);

		//POP
		
		void			pop();

	protected:
		
		Container c;

};

#endif
