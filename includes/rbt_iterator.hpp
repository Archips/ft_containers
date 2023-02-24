/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:43:45 by athirion          #+#    #+#             */
/*   Updated: 2023/02/23 14:44:58 by athirion         ###   ########.fr       */
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
	/* class rbt_iterator: public ft::iterator<typename iterator_traits<iterator>::iterator_category, */
	/* 	typename iterator_traits<iterator>::difference_type, */
	/* 	typename iterator_traits<iterator>::value_type, */
	/* 	typename iterator_traits<iterator>::pointer, */
	/* 	typename iterator_traits<iterator>::reference> */
	class rbt_iterator
	{
	
		public:

			typedef typename node::value_type		value_type;
			typedef	typename node::value_type&		reference;
			typedef typename node::value_type*		pointer;
			typedef bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t						difference_type;
			typedef rbt_iterator<node, Compare> 	iterator;
			typedef node*					 		node_ptr;


			/* typedef typename node::node_ptr																			node_ptr; */
			/* typedef typename node::value_type																		value_type; */
			/* typedef rbt_iterator<node, Compare>																		iterator; */
			/* typedef typename ft::iterator_traits<rbt_iterator>::iterator_category	iterator_category; */
			/* typedef typename ft::iterator_traits<rbt_iterator>::difference_type		difference_type; */
			/* typedef typename ft::iterator_traits<rbt_iterator>::pointer				pointer; */
			/* typedef typename ft::iterator_traits<rbt_iterator>::reference			reference; */
			/* typedef random_access_iterator_tag																		iterator_category; */
			/* typedef ptrdiff_t																						difference_type; */
			/* typedef typename node::value_type*																		pointer; */
			/* typedef typename node::value_type&																		reference; */

			/* typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category; */
			/* typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; */
			/* typedef typename ft::iterator_traits<iterator>::value_type			value_type; */
			/* typedef typename ft::iterator_traits<iterator>::pointer				pointer; */
			/* typedef typename ft::iterator_traits<iterator>::reference			reference; */

		private:

			node_ptr _current;

		public:

			/*
			 ** CONSTRUCTORS
			 */ 

			rbt_iterator(void): _current(NULL) {};

			explicit rbt_iterator(node_ptr other): _current(other) {}

			rbt_iterator(const rbt_iterator &other): _current(other._current) {}

			rbt_iterator(const rbt_const_iterator<node, Compare> &src) {

				this->_current = src.base();
			}

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

				return (&(this->_current->data));
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

				if (!n)
					return (NULL);
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

				this->_current = this->successor(this->_current);
				return (*this);
			}

			rbt_iterator& operator--(void) {
				
				this->_current = this->predecessor(this->_current);
				return (*this);
			}

			rbt_iterator operator++(int) {

				rbt_iterator temp = *this;
				/* this->_current = this->successor(this->_current); */
				++(*this);
				return (temp);
			}

			rbt_iterator operator--(int) {

				rbt_iterator temp = *this;
				/* this->_current = this->predecessor(this->_current); */
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
	class rbt_const_iterator
	{
	
		public:

			typedef typename node::value_type			value_type;
			typedef	typename node::value_type&			reference;
			typedef typename node::value_type*			pointer;
			typedef bidirectional_iterator_tag			iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef rbt_const_iterator<node, Compare> 	const_iterator;
			typedef node*					 			node_ptr;

		private:

			node_ptr _current;

		public:

			/*
			 ** CONSTRUCTORS
			 */ 

			rbt_const_iterator(void): _current(NULL) {};

			explicit rbt_const_iterator(node_ptr other): _current(other) {}

			rbt_const_iterator(const rbt_const_iterator &other): _current(other._current) {}

			rbt_const_iterator(const rbt_iterator<node, Compare> &src) {

				this->_current = src.base();
			}

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

				return (&(this->_current->data));
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

				if (!n)
					return (NULL);
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

				this->_current = this->successor(this->_current);
				return (*this);
			}

			rbt_const_iterator& operator--(void) {
				
				this->_current = this->predecessor(this->_current);
				return (*this);
			}

			rbt_const_iterator operator++(int) {

				rbt_const_iterator temp = *this;
				/* this->_current = this->successor(this->_current); */
				++(*this);
				return (temp);
			}

			rbt_const_iterator operator--(int) {

				rbt_const_iterator temp = *this;
				/* this->_current = this->predecessor(this->_current); */
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

	// template < class node, class Compare>
	// /* class rbt_const_iterator: public ft::iterator<typename iterator_traits<iterator>::iterator_category, */
	// /* 	typename iterator_traits<iterator>::difference_type, */
	// /* 	typename iterator_traits<iterator>::value_type, */
	// /* 	typename iterator_traits<iterator>::pointer, */
	// /* 	typename iterator_traits<iterator>::reference> */
	// class rbt_const_iterator: public ft::iterator<random_access_iterator_tag, typename node::value_type>
	// {
	
	// 	public:
			
	// 		typedef node*																			node_ptr;
	// 		typedef typename node::value_type																		value_type;
	// 		typedef rbt_const_iterator<node, Compare>						const_iterator;
	// 		typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::iterator_category	iterator_category;
	// 		typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::difference_type	difference_type;
	// 		typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::pointer			pointer;
	// 		typedef typename ft::iterator<random_access_iterator_tag, typename node::value_type>::reference			reference;

	// 		/* typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category; */
	// 		/* typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; */
	// 		/* typedef typename ft::iterator_traits<iterator>::value_type			value_type; */
	// 		/* typedef typename ft::iterator_traits<iterator>::pointer				pointer; */
	// 		/* typedef typename ft::iterator_traits<iterator>::reference			reference; */

	// 	private:

	// 		node_ptr _current;

	// 	/* public: */

	// 	/* 	typedef iterator													iterator_type; */
	// 	/* 	typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category; */
	// 	/* 	typedef typename ft::iterator_traits<iterator>::difference_type		difference_type; */
	// 	/* 	typedef typename ft::iterator_traits<iterator>::value_type			value_type; */
	// 	/* 	typedef typename ft::iterator_traits<iterator>::pointer				pointer; */
	// 	/* 	typedef typename ft::iterator_traits<iterator>::reference			reference; */

	// 	public:

	// 		/*
	// 		 ** CONSTRUCTORS
	// 		 */ 

	// 		rbt_const_iterator(void): _current() {};

	// 		/* explicit rbt_const_iterator(const iterator_type& x): _current(x) {} */

	// 		rbt_const_iterator(const node_ptr& other): _current(other) {}

	// 		rbt_const_iterator(const rbt_const_iterator <node, Compare> &other): _current(other.base()) {}

	// 		~rbt_const_iterator(void) {}

	// 		rbt_const_iterator& operator=(const rbt_const_iterator& rhs) {

	// 			if (this != &rhs)
	// 				this->_current = rhs._current;
	// 			return (*this);
	// 		}

	// 		node_ptr base(void) const {

	// 			return (this->_current);
	// 		}

	// 		reference operator*(void) const {

	// 			return (this->_current->data);
	// 		}

	// 		pointer operator->(void) const {

	// 			return (&(operator*()));
	// 		}

	// 		rbt_const_iterator& operator++(void) {

	// 			return (this->_current->successor());
	// 		}

	// 		rbt_const_iterator& operator--(void) {

	// 			return (this->_current->predecessor());
	// 		}

	// 		rbt_const_iterator operator++(int) {

	// 			rbt_const_iterator temp = *this;
	// 			++(*this);
	// 			return (temp);
	// 		}

	// 		rbt_const_iterator operator--(int) {

	// 			rbt_const_iterator temp = *this;
	// 			--(*this);
	// 			return (temp);
	// 		}

	// 		bool operator==(const rbt_const_iterator &it) const {

	// 			return (this->_current == it.base());
	// 		}

	// 		bool operator!=(const rbt_const_iterator &it) const {

	// 			return (!(this->_current == it.base()));
	// 		}
	
	// };
	template< typename node, class Compare >
	std::ostream & operator<<(std::ostream & o, rbt_iterator<node, Compare> const & max_op)
	{
		o << *max_op._node->value->first;
		return (o);
	}
}

#endif
