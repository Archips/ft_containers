/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:33:17 by athirion          #+#    #+#             */
/*   Updated: 2023/02/01 16:17:43 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "node.hpp"


namespace ft {

	template < class T, class Compare, class node = node < T >, class AllocNode = std::allocator < node > >
	class rbt {

		public:

			typedef	T											value_type;
			typedef	rbt*										rbt_ptr;
			typedef const rbt*									const_rbt_ptr;
			typedef rbt&										rbt_ref;
			typedef const rbt&									const_rbt_ref;

			typedef typename T::first_type						key;
			typedef typename T::second_type						value;
			typedef Compare										key_compare;	
			
			typedef typename node::node_ptr						node_ptr;
			typedef typename node::const_node_ptr				const_node_ptr;
			typedef typename node::node_ref						node_ref;
			typedef typename node::const_node_ref				const_node_ref;
			
			typedef typename allocator::AllocNode				alloc_node;
			typedef typename allocator::AllocNode::size_type;	size_type;

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

			/* rbt(const_rbt_ref src) {}; */


			/*
			 ** COPY ASSIGNMENT OPERATOR 
			 */

			/* rbt_ref operator=(const_rbt_ref rhs) {}; */

		private:

			node_ptr		_root;
			size_type		_size;			
			alloc_node		_alloc;
			key_compare		_comp;

	};
}

#endif
