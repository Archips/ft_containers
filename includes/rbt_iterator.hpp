/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:43:45 by athirion          #+#    #+#             */
/*   Updated: 2023/02/21 14:05:07 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

#include "pair.hpp"
#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"

namespace ft {

	template <class iterator>
	class rbt_const_iterator;

	template < class node >
	/* class rbt_iterator: public ft::iterator<typename iterator_traits<iterator>::iterator_category, */
	/* 	typename iterator_traits<iterator>::difference_type, */
	/* 	typename iterator_traits<iterator>::value_type, */
	/* 	typename iterator_traits<iterator>::pointer, */
	/* 	typename iterator_traits<iterator>::reference> */
	class rbt_iterator: public ft::iterator<random_access_iterator_tag, typename node::value_type>
	{
	
		public:

			typedef typename node::node_ptr																			node_ptr;
			typedef typename node::value_type																		value_type;
			typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::difference_type	difference_type;
			typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::pointer			pointer;
			typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::reference			reference;

			/* typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category; */
			/* typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; */
			/* typedef typename ft::iterator_traits<iterator>::value_type			value_type; */
			/* typedef typename ft::iterator_traits<iterator>::pointer				pointer; */
			/* typedef typename ft::iterator_traits<iterator>::reference			reference; */

		protected:

			node_ptr _current;

		public:

			/*
			 ** CONSTRUCTORS
			 */ 

			rbt_iterator(void): _current() {};

			/* explicit rbt_iterator(const rbt_iterator& x): _current(x) {} */

			rbt_iterator(const node_ptr other): _current(other) {}

			template < class U >
			rbt_iterator(const rbt_iterator <U> &other): _current(other->base()) {}

			~rbt_iterator(void) {}

			rbt_iterator& operator=(const rbt_iterator& rhs) {

				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			}

			node_ptr base(void) const {

				return (this->_current);
			}

			reference operator*(void) const {

				return (this->_current->data);
			}

			pointer operator->(void) const {

				return (&operator*());
			}

			rbt_iterator& operator++(void) {

				if (this->_current) {
				
					node_ptr temp = this->_current;
					if (this->_current->right_child) {
					
						this->_current = this->_current->right_child;
						while (this->_current->left_child)
							this->_current = this->_current->left_child;
					}
					else {
						while (this->_current->parent && this->_current == this->_current->parent->right_child) {
							this->_current = this->_current->parent;
						this->_current = this->_current->parent;
					/* this->_current->parent = this->_current->parent->parent; */
					}
				}
				return (*temp);
			}

			rbt_iterator& operator--(void) {

				return (*this->_current->predecessor());
			}

			rbt_iterator operator++(int) {

				rbt_iterator temp = *this;
				++(*this);
				return (temp);
			}

			rbt_iterator operator--(int) {

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

	template < class node >
	/* class rbt_const_iterator: public ft::iterator<typename iterator_traits<iterator>::iterator_category, */
	/* 	typename iterator_traits<iterator>::difference_type, */
	/* 	typename iterator_traits<iterator>::value_type, */
	/* 	typename iterator_traits<iterator>::pointer, */
	/* 	typename iterator_traits<iterator>::reference> */
	class rbt_const_iterator: public ft::iterator<random_access_iterator_tag, typename node::value_type>
	{
	
		public:

			typedef typename node::node_ptr																			node_ptr;
			typedef typename node::value_type																		value_type;
			typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::difference_type	difference_type;
			typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::pointer			pointer;
			typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::reference			reference;

			/* typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category; */
			/* typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; */
			/* typedef typename ft::iterator_traits<iterator>::value_type			value_type; */
			/* typedef typename ft::iterator_traits<iterator>::pointer				pointer; */
			/* typedef typename ft::iterator_traits<iterator>::reference			reference; */

		protected:

			node_ptr _current;

		/* protected: */

		/* 	iterator _current; */

		/* public: */

		/* 	typedef iterator													iterator_type; */
		/* 	typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category; */
		/* 	typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; */
		/* 	typedef typename ft::iterator_traits<iterator>::value_type			value_type; */
		/* 	typedef typename ft::iterator_traits<iterator>::pointer				pointer; */
		/* 	typedef typename ft::iterator_traits<iterator>::reference			reference; */

		public:

			/*
			 ** CONSTRUCTORS
			 */ 

			rbt_const_iterator(void): _current() {};

			/* explicit rbt_const_iterator(const iterator_type& x): _current(x) {} */

			rbt_const_iterator(const node_ptr& other): _current(other) {}

			template < class U >
			rbt_const_iterator(const rbt_const_iterator <U> &other): _current(other.base()) {}

			~rbt_const_iterator(void) {}

			rbt_const_iterator& operator=(const rbt_const_iterator& rhs) {

				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			}

			node_ptr base(void) const {

				return (this->_current);
			}

			reference operator*(void) const {

				return (this->_current->data);
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
