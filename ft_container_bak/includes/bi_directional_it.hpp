/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_directional_it.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:34:43 by athirion          #+#    #+#             */
/*   Updated: 2023/02/08 17:21:31 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BI_DIRECTIONAL_IT_HPP
# define BI_DIRECTIONAL_IT_HPP

#include <iterator>
#include "iterator_traits.hpp"

namespace ft {

	template < class iterator >
	class bidirectional_iterator_tag {

		protected:

			iterator	_current;

		public:

			typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_catagory;
			typedef typename ft::iterator_traits<iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator>::reference			reference;

			/*
			 ** CONSTRUCTORS
			 */
		
			bidirectional_iterator_tag(void): _current() {}

			explicit bidirectional_iterator_tag(iterator_type x): _current(x) {}

			bidirectional_iterator_tag(const bidirectional_iterator_tag &other): _current(other.base()) {}

			template < class U >
			bidirectional_iterator_tag (const bidirectional_iterator_tag <U> &other): _current(other.base()) {}

			~bidirectional_iterator_tag(void) {}

			template < class U >
			bidirectional_iterator_tag& operator=( const bidirectional_iterator_tag <U>& other) {

				if (this != &other)
					this->_current = other.base();
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

			bidirectional_iterator_tag& operator++(void) {

				++ this->_current;
				return (*this);
			}

			bidirectional_iterator_tag& operator--(void) {

				-- this->_current;
				return (*this);
			}

			bidirectional_iterator_tag operator++(int) const {
				
				bidirectional_iterator_tag temp = *this;
				++(*this);
				return (temp);
			}

			bidirectional_iterator_tag operator--(int) const {

				bidirectional_iterator_tag temp = *this;
				--(*this);
				return (temp);
			}

			bool	operator==(const bidirectional_iterator_tag &it) const {

				return (this->_current == it.base());
			}

			bool	operator!=(const bidirectional_iterator_tag &it) const {

				return (!(this->_current == it.base()));
			}

	};

	template < class Iterator1, class Iterator2 >
	bool operator==(const bidirectional_iterator_tag<Iterator1>& lhs, const bidirectional_iterator_tag<Iterator2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator!=(const bidirectional_iterator_tag<Iterator1>& lhs, const bidirectional_iterator_tag<Iterator2>& rhs) {

		return (!(lhs == rhs));
	}
	
}

#endif
