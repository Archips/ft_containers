/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:43:45 by athirion          #+#    #+#             */
/*   Updated: 2023/02/14 14:16:57 by athirion         ###   ########.fr       */
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

			rbt_iterator& operator++(void) {

				return (this->_current->successor());
			}

			rbt_iterator& operator--(void) {

				return (this->_current->predecessor());
			}

			rbt_iterator& operator++(int) {

				rbt_iterator temp = *this;
				++(*this);
				return (temp);
			}

			rbt_iterator& operator--(int) {

				rbt_iterator temp = *this;
				--(*this);
				return (temp);
			}

			bool operator==(const rbt_iterator &it) const {

				return (this->_current == it.base());
			}

			bool operator!=(const rbt_iterator &it) const {

				return (!(this->_current == it.base()));
			}
	
	};

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

			rbt_const_iterator(void): _current() {};

			explicit rbt_const_iterator(const iterator_type& x): _current(x) {}

			rbt_const_iterator(const rbt& other): _current(other.base()) {}

			template < class U >
			rbt_const_iterator(const rbt_iterator <U> &other): _current(other.base()) {}

			~rbt_const_iterator(void) {}

			rbt_const_iterator& operator=(const rbt_iterator& rhs) {

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

			rbt_const_iterator& operator++(void) {

				return (this->_current->successor());
			}

			rbt_const_iterator& operator--(void) {

				return (this->_current->predecessor());
			}

			rbt_const_iterator operator++(int) {

				rbt_const_iterator temp = *this;
				++(*this);
				return (temp);
			}

			rbt_const_iterator operator--(int) {

				rbt_const_iterator temp = *this;
				--(*this);
				return (temp);
			}

			bool operator==(const rbt_const_iterator &it) const {

				return (this->_current == it.base());
			}

			bool operator!=(const rbt_const_iterator &it) const {

				return (!(this->_current == it.base()));
			}
	
	};
}

#endif
