/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:33:17 by athirion          #+#    #+#             */
/*   Updated: 2023/02/15 14:41:20 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "node.hpp"
# include "rbt_ierator.hpp"

# define RED	0
# define BLACK	1

namespace ft {

	template < class T, class Compare, class node = node < T >, class AllocNode = std::allocator < node > >
	class rbt {

		public:

			typedef	T											value_type;
			typedef typename T::first_type						key;
			typedef typename T::second_type						value;
			typedef Compare										key_compare;	
			
			typedef rbt*										rbt_ptr;
			typedef const*										const_rbt_ptr;
			typedef rbt&										rbt_ref;
			typedef const &rbt									const_rbt_ref;

			typedef typename ft::node::node_ptr					node_ptr;
			typedef typename ft::node::const_node_ptr			const_node_ptr;
			typedef typename ft::node::node_ref					node_ref;
			typedef typename ft::node::const_node_ref			const_node_ref;
			
			typedef typename allocator::AllocNode				alloc_node;
			typedef typename allocator::AllocNode::size_type;	size_type;

			typedef typename ft::rbt_iterator<T>				iterator;
			typedef typename ft::const_rbt_iterator<T>			const_iterator;

			/*
			 ** CONSTRUCTORS
			 */


			rbt(void):
				_root(NULL), _size(0), _alloc(), _comp() {}

			rbt(node_ptr root = NULL, size_type size = 0, alloc_node alloc, key_compare comp):
				_root(root), _size(size), _alloc(alloc), _comp(comp) {}

			/*
			 ** COPY CONSTRUCTOR
			 */

			rbt(const_rbt_ref src) {

				this->_root = src._root;
				this->_size = src._size;
				this->_alloc = src._alloc;
				this->_comp = src._comp;
			}


			/*
			 ** COPY ASSIGNMENT OPERATOR 
			 */

			rbt_ref operator=(const_rbt_ref rhs) {
	
				if (this != &rhs) {

					this->_root = rhs._root;
					this->_size = rhs._size;
					this->_alloc = rhs._alloc;
					this->_comp = rhs._comp;
				}	
				return (*this);
			}

			/*
			 ** MEMBER FUNCTIONS
			 */

			/* bool	comp(const value& x, const value& y) { */
			bool	value_compare(const value& x, const value& y) {

				return (_comp(x.first, y.first);
			}

			/* bool	comp(const key& x, const key& y) { */
			bool	value_compare(const key& x, const key& y) {

				return (_comp(x, y);
			}

			size_type size(void) const {

				return (this->_size);
			}

			size_type max_size(void) const {

				return (this->_alloc.max_size());
			}

			node_ptr root(void) const {

				return (this->_root);
			}
			
			bool	empty(void) {

				return (this->_root == NULL);
			}

			node_ref operator*(void) const {

				return (this->_root);
			}

			node_ptr operator->(void) const {

				return (&this->_root);
			}

			iterator max(void) const {
			
				if (this->_root)
					return (iterator(this->_root.max()));
				return (iterator());
			}
			
			const_iterator max(void) const {

				if (this->_root)
					return (const_iterator(this->_root.max()));
				return (const_iterator());
			}

			iterator min(void) const {
				
				if (this->_root)
					return (iterator(this->_root.min()));
				return (iterator());
			}
			
			const_iterator min(void) const {

				if (this->_root)
					return (const_iterator(this->_root.min()))l
				return (const_iterator());
			}

			iterator begin(void) const {

				return (this->min());
			}

			const_iterator begin(void) const {

				return (this->min());
			}

			iterator end(void) const {

				return (this->max());
			}

			const_iterator end(void) const {

				return (this->max());
			}

		private:

			node_ptr		_root;
			size_type		_size;			
			alloc_node		_alloc;
			key_compare		_comp;

	};
}

#endif
