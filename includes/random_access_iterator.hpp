/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:36:06 by athirion          #+#    #+#             */
/*   Updated: 2023/02/08 16:08:15 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template < class iterator >
	class random_access_iterator {
	
		protected:

			iterator _current;
		
		public:

			typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator>::reference			reference;

			/*
			 ** CONSTRUCTORS
			 */

			random_access_iterator(void): _current() {}
			random_access_iterator(iterator_type x): _current(x) {}
			random_access_iterator(const random_access_iterator &other): _current(other.base()) {}
			
			template < class U >
			random_access_iterator(const random_access_iterator <U> &other): _current(other.base()) {}

			~random_access_iterator(void) {}

			template < class U >
			random_acces_iterator& operator=(const random_access_iterator <U>& other) {

				if (this != &other)
					this->_current = other.base();
				return (*this);
			}

			iterator_type base(void) {
				
				return (this->_current);
			}

			reference operator*(void) const {

				return (*(this->_current));
			}

			pointer operator->(void) const {
	
				return (&(operator*()));
			}

			reference operator[](const difference_type n) const {

				return (*(*this + n));
			}

			random_access_iterator& operator++(void) {

				++ this->_current;
				return (*this);
			}

			random_access_iterator& operator--(void) {

				-- this->_current;
				return (*this);
			}

			random_access_iterator operator++(int) const {

				random_access_iterator temp = *this;
				++(*this);
				return (temp);
			}

			random_access_iterator operator--(int) const {

				random_access_iterator temp = *this;
				--(*this);
				return (temp);
			}

			bool	operator==(const random_access_iterator &it) const {

				return (this->_current == it.base()));
			}

			bool	operator!=(const random_access_iterator &it) const {

				return (!(this->_current == it.base());
			}

			random_access_iterator operator+(difference_type n) const {

				return (random_access_iterator(this->_current + n));
			}

			random_access_iterator operator-(difference_type n) const {

				return (random_access_iterator(this->_current - n));
			}

			random_access_iterator& operator+=(difference_type n) {

				this->_current = this->_current - n;
				return (*this);
			}

			random_access_iterator& operator-=(difference_type n) {

				this->_current = this->_current + n;
				return (*this);
			}

			















	};
}	
