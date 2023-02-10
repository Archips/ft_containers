/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:36:06 by athirion          #+#    #+#             */
/*   Updated: 2023/02/10 14:05:28 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft {

	template < class iterator >
	class random_access_iterator: public ft::iterator<typename iterator_traits<iterator>::iterator_category,
				typename iterator_traits<iterator>::difference_type,
				typename iterator_traits<iterator>::value_type,
				typename iterator_traits<iterator>::pointer,
				typename iterator_traits<iterator>::reference>

	{

		protected:

			iterator _current;
		
		public:

			typedef	iterator													iterator_type;
			typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator>::reference			reference;

			/*
			 ** CONSTRUCTORS
			 */

			random_access_iterator(void): _current() {}
			explicit random_access_iterator(const iterator_type& x): _current(x) {}
			random_access_iterator(const random_access_iterator& other): _current(other.base()) {}
			
			template < class U >
			random_access_iterator(const random_access_iterator <U> &other): _current(other.base()) {}

			~random_access_iterator(void) {}

			random_access_iterator& operator=(const random_access_iterator& other) {

				if (this != &other)
					this->_current = other._current;
				return (*this);
			}

			iterator_type	base(void) const {
				
				return (this->_current);
			}

			reference operator*(void) const {

				return (*(this->_current));
			}

			pointer operator->(void) const {
	
				return (&(operator*()));
			}

			reference operator[](const difference_type& n) const {

				return (*(*this + n));
			}

			random_access_iterator& operator++(void) {

				++ this->_current;
				/* this->_current++; */
				return (*this);
			}

			random_access_iterator& operator--(void) {

				-- this->_current;
				return (*this);
			}

			random_access_iterator operator++(int) {

				random_access_iterator temp = *this;
				++(*this);
				return (temp);
			}

			random_access_iterator operator--(int) {

				random_access_iterator temp = *this;
				--(*this);
				return (temp);
			}

			bool	operator==(const random_access_iterator &it) const {

				return (this->_current == it.base());
			}

			bool	operator!=(const random_access_iterator &it) const {

				return (!(this->_current == it.base()));
			}

			random_access_iterator operator+(const difference_type n) const {

				return (random_access_iterator(this->_current + n));
			}

			random_access_iterator operator-(const difference_type n) const {

				return (random_access_iterator(this->_current - n));
			}

			random_access_iterator& operator+=(const difference_type n) {

				this->_current = this->_current + n;
				return (*this);
			}

			random_access_iterator& operator-=(const difference_type n) {

				this->_current = this->_current - n;
				return (*this);
			}
	};

	template < class Iterator1, class Iterator2 >
	bool operator==(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) {

		return (lhs.base() == rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator!=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) {

		return (!(lhs == rhs));
	}

	template < class Iterator1, class Iterator2 >
	bool operator<( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) {

		return (lhs.base() < rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator<=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) {

		return (!(rhs < lhs));
	}

	template < class Iterator1, class Iterator2 >
	bool operator>(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) {

		return (rhs < lhs);
	}

	template < class Iterator1, class Iterator2 >
	bool operator>=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs) {

		return (!(lhs < rhs));
	}

	template < typename T>
    random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T>& y) {
        
		return (random_access_iterator<T>(y.base() + n));
	}

    template< typename lhs, typename rhs>
    typename ft::random_access_iterator<lhs>::difference_type operator-(const random_access_iterator<lhs>& x, const random_access_iterator<rhs>& y){ 

		return (x.base() - y.base()); 
	}

  }

#endif
