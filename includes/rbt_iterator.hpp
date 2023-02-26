/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:43:45 by athirion          #+#    #+#             */
/*   Updated: 2023/02/26 16:21:46 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

#include "pair.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"

namespace ft {

	template <class node, class Compare>
	class rbt_const_iterator;

	template < class node, class Compare >
	class rbt_iterator: public ft::iterator<std::bidirectional_iterator_tag, typename node::value_type>
	{
	
		public:

			typedef node*					 		node_ptr;
			typedef typename node::value_type		value_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;

		private:

			node_ptr _current;
			node_ptr _parent;

		public:

			/*
			 ** CONSTRUCTORS
			 */ 

			rbt_iterator(void): _current(NULL), _parent(NULL) {}

			explicit rbt_iterator(node_ptr x, node_ptr y): _current(x), _parent(y) {}

			rbt_iterator(const rbt_iterator &other): _current(other._current), _parent(other._parent) {}

			~rbt_iterator(void) {}

			rbt_iterator& operator=(const rbt_iterator& rhs) {

				if (this != &rhs) {
					this->_current = rhs._current;
					this->_parent = rhs._parent;
				}
				return (*this);
			}

			node_ptr base(void) const {

				return (this->_current);
			}

			node_ptr parent(void) const {

				return (this->_parent);
			}

			reference operator*(void) const {

				return (this->_current->data);
			}

			pointer operator->(void) const {

				return (&operator*());
			}

			node_ptr max(node_ptr n) {
				
				if (!n)
					return (NULL);
				while (n->right_child)
					n = n->right_child;
				return (n);
			}

			node_ptr min(node_ptr n) {
				
				if (!n)
					return (NULL);
				while (n->left_child)
					n = n->left_child;
				return (n);
			}

			node_ptr successor(node_ptr n) {

				if (!n)
					return (NULL);
				if (n->right_child) {
				
					return (min(n->right_child));
				}
				node_ptr p = n->parent;
				while (p && n == p->right_child) {

					n = p;
					p = p->parent;
				}
				return (p);
			}

			node_ptr predecessor(node_ptr n) {

				if (!n) {
					return (NULL);
				}
				if (n->left_child)
					return (this->max(n->left_child));
				node_ptr p = n->parent;
				while (p && n == p->left_child) {

					n = p;
					p = p->parent;
				}
				return (p);
			}

			rbt_iterator& operator++(void) {

				this->_parent = this->_current;
				this->_current = this->successor(this->_current);
				return (*this);
			}

			rbt_iterator& operator--(void) {
			
				if (!this->_current)
					this->_current = this->_parent;
				else
					this->_current = this->predecessor(this->_current);
				return (*this);
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

	template < class node, class Compare >
	class rbt_const_iterator: public ft::iterator<std::bidirectional_iterator_tag, typename node::value_type>
	{
	
		public:

			typedef node*					 			node_ptr;
			typedef typename node::value_type const		value_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;

		private:

			node_ptr _current;
			node_ptr _parent;

		public:

			/*
			 ** CONSTRUCTORS
			 */ 

			rbt_const_iterator(void): _current(NULL), _parent(NULL) {}

			explicit rbt_const_iterator(node_ptr x, node_ptr y): _current(x), _parent(y) {}

			rbt_const_iterator(const rbt_const_iterator &other): _current(other._current), _parent(other._parent) {}

			rbt_const_iterator(const rbt_iterator<node, Compare> &src) {

				this->_current = src.base();
				this->_parent = src.parent();
			}

			~rbt_const_iterator(void) {}

			rbt_const_iterator& operator=(const rbt_const_iterator& rhs) {

				if (this != &rhs) {
				
					this->_current = rhs._current;
					this->_parent = rhs._parent;
				}
				return (*this);
			}

			node_ptr base(void) const {

				return (this->_current);
			}

			node_ptr parent(void) const {

				return (this->_parent);
			}

			reference operator*(void) const {

				return (this->_current->data);
			}

			pointer operator->(void) const {

				return (&operator*());
			}

			node_ptr max(node_ptr n) {
				
				if (!n)
					return (NULL);
				while (n->right_child)
					n = n->right_child;
				return (n);
			}

			node_ptr min(node_ptr n) {
				
				if (!n)
					return (NULL);
				while (n->left_child)
					n = n->left_child;
				return (n);
			}

			node_ptr successor(node_ptr n) {

				if (!n)
					return (NULL);
				if (n->right_child) {
				
					return (min(n->right_child));
				}
				node_ptr p = n->parent;
				while (p && n == p->right_child) {

					n = p;
					p = p->parent;
				}
				return (p);
			}

			node_ptr predecessor(node_ptr n) {

				if (!n) {
					return (NULL);
				}
				if (n->left_child)
					return (this->max(n->left_child));
				node_ptr p = n->parent;
				while (p && n == p->left_child) {

					n = p;
					p = p->parent;
				}
				return (p);
			}

			rbt_const_iterator& operator++(void) {

				this->_parent = this->_current;
				this->_current = this->successor(this->_current);
				return (*this);
			}

			rbt_const_iterator& operator--(void) {
			
				if (!this->_current)
					this->_current = this->_parent;
				else
					this->_current = this->predecessor(this->_current);
				return (*this);
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

	template< typename node, class Compare >
	std::ostream & operator<<(std::ostream & o, rbt_iterator<node, Compare> const & max_op)
	{
		o << *max_op._node->value->first;
		return (o);
	}
}

#endif
