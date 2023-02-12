/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:43:45 by athirion          #+#    #+#             */
/*   Updated: 2023/02/12 18:14:51 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template < class iterator >
	class rbt_iterator: public ft::iterator<typename iterator_traits<iterator>::iterator_category,
		typename iterator_traits<iterator>::difference_type,
		typename iterator_traits<iterator>::value_type,
		typename iterator_traits<iterator>::pointer,
		typename iterator_traits<iterator>::reference>
	{
		protected:

			iterator _current;

		public:

			typedef iterator													iterator_type;
			typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator>::reference			reference;

			/*
			 ** CONSTRUCTORS
			 */ 

			rbt_iterator(void): _current() {};

			explicit rbt_iterator(const iterator_type& x): _current(x) {}

			rbt_iterator(const rbt& other): _current(other.base()) {}

			template < class U >
			rbt_iterator(const rbt_iterator <U> &other): _current(other.base()) {}

			~rbt_iterator(void) {}

			rbt_iterator& operator=(const rbt_iterator& rhs) {

				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			}

			iterator_type base(void) const {

				return (this->_current);
			}

			reference operator*(void) const {

				return (*(this->_current));
			}

			pointer operator->(void) const {

				return (&(operator*()));
			}

			
			
















	
}

#endif
