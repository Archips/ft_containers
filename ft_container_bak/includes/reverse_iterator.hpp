/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:59:08 by athirion          #+#    #+#             */
/*   Updated: 2023/02/08 14:28:44 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template < class iterator > 
	class reverse_iterator: public ft::iterator<typename iterator_traits<iterator>::iterator_category,
			typename iterator_traits<iterator>::value_type,
			typename iterator_traits<iterator>::difference_type,
			typename iterator_traits<iterator>::pointer,
			typename iterator_traits<iterator>::reference>
	{

		protected :

			iterator	_current;
		
		public :

			typedef 			iterator											iterator_type;
			typedef typename 	ft::iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename	ft::iterator_traits<iterator>::value_type			value_type;
			typedef typename	ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<iterator>::pointer				pointer;
			typedef typename	ft::iterator_traits<iterator>::reference			reference;
	
			reverse_iterator(void): _current(){}
			
			explicit reverse_iterator( iterator_type x): _current(x){}
			
			template < class U >
			reverse_iterator (const reverse_iterator <U>& other): _current(other.base()){}

			operator reverse_iterator<const iterator>() const {
				return (reverse_iterator<const iterator>(this->_current));
			}

			template < class U >
			reverse_iterator& operator=( const reverse_iterator <U>& other) {
			
				this->_current = other.base();
				return (*this);
			}
	
			iterator_type base() const {
				
				return (this->_current);
			}
		
			reference operator*() const {

				iterator temp = _current;
				return (*--temp);
			}

			pointer operator->() const {

				return (&(operator*()));
			}

			reference operator[](difference_type n) const {

				return (base()[-n-1]);
			}

			reverse_iterator& operator++() {
			
				--this->_current;
				return (*this);
			}

			reverse_iterator& operator--() {
				
				++this->_current;
				return (*this);
			}

			reverse_iterator operator++(int) {
				
				reverse_iterator temp = *this;
				++(*this);
				return(temp);
			}

			reverse_iterator operator--(int) {

				reverse_iterator temp = *this;
				--(*this);
				return (temp);
			}
			
			reverse_iterator  operator+(difference_type n) const {

				return (reverse_iterator(_current - n));
			}

			reverse_iterator  operator-(difference_type n) const {

				return (reverse_iterator(_current + n));
			}

			reverse_iterator& operator+=(difference_type n) {

				this->_current = this->_current - n;
				return (*this);
			}

			reverse_iterator& operator-=(difference_type n) {

				this->_current = this->_current + n;
				return (*this);

			}

	};

	template < class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {

		return (!(lhs == rhs));
	}

	template < class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {

		return (rhs.base() < lhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {

		return (!(rhs < lhs));
	}

	template < class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {

		return (!(lhs < rhs));
	}

	template < class iterator >
	reverse_iterator< iterator > operator+(typename reverse_iterator<iterator>::difference_type n, 
											const reverse_iterator<iterator>& it) {
			
		return reverse_iterator<iterator>(it.base() - n);
	}

	template < class Iterator1, class Iterator2 >
	typename ft::reverse_iterator<Iterator1>::difference_type operator-( const ft::reverse_iterator<Iterator1>& lhs,
																	 const ft::reverse_iterator<Iterator2>& rhs) {

		return (rhs.base() - lhs.base());
	}

}

#endif
