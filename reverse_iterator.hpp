/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:59:08 by athirion          #+#    #+#             */
/*   Updated: 2023/01/09 16:35:05 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template < class iterator > 
	class reverse_iterator {

		public :

			typedef 			iterator											iterator_type;
			typedef typename 	ft::iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename	ft::iterator_traits<iterator>::value_type			value_type;
			typedef typename	ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<iterator>::pointer				pointer;
			typedef typename	ft::iterator_traits<iterator>::reference			reference;
	
			reverse_iterator(void);
			explicit reverse_iterator( iterator_type x);
			template < class U >
			reverse_iterator (const reverse_iterator <U>& other);
	
			template < class U >
			reverse_iterator& operator=( const reverse_iterator <U>& other);
	
			iterator_type base() const;
		
			reference opetator*() const;

			pointer operator->() const;

			operator[](difference_type n) const;

			reverse_iterator& operator++();
			reverse_iterator& operator--();
			reverse_iterator& operator++(int);
			reverse_iterator& operator--(int);
			reverse_iterator  operator+(difference_type n) const;
			reverse_iterator  operator-(difference_type n) const;
			reverse_iterator& operator+=(difference_type n);
			reverse_iterator& operator-=(difference_type n);

		protected :

			iterator_type	_current;
	};

	template < class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs);

	template < class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs);

	template < class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs);

	template < class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs);

	template < class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs);

	template < class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs);

	template < class iterator >
	reverse_iterator< iterator > operator+(typename reverse_iterator<iterator>::difference_type n, 
											const reverse_iterator<iterator>& it);

	template < class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1>& lhs,
																	 const reverse_iterator<Iterator2>& rhs>);	

}

#endif
