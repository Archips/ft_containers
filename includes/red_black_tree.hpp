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
			
			typedef typename node::node_ptr						node_ptr;
			typedef typename node::const_node_ptr				const_node_ptr;
			typedef typename node::node_ref						node_ref;
			typedef typename node::const_node_ref				const_node_ref;
			
			typedef typename allocator::AllocNode				alloc_node;
			typedef typename allocator::AllocNode::size_type;	size_type;

			typedef rbt_iterator								iterator;

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

			bool	empty(void) {

				return (this->_root == NULL);
			}

			iterator max(void) {
			
				if (this->_root)
					return (iterator(this->root->max()));
					return (iterator());
			}

			iterator min(void) {
				
				if (this->_root)
					return (iterator(this->_root->min()));
				return (iterator());
			}
			
			iterator begin(void){

				return (this->min());
			}

			iterator end(void) {

				return (iterator());
			}

		private:

			node_ptr		_root;
			size_type		_size;			
			alloc_node		_alloc;
			key_compare		_comp;

	};
}

#endif
