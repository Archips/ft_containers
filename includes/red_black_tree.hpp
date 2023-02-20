/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:33:17 by athirion          #+#    #+#             */
/*   Updated: 2023/02/20 17:08:49 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "node.hpp"
# include "pair.hpp"
# include "random_access_iterator.hpp"
# include "rbt_iterator.hpp"

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
			typedef const rbt*									const_rbt_ptr;
			typedef rbt&										rbt_ref;
			typedef const rbt&									const_rbt_ref;

			typedef typename node::node_ptr						node_ptr;
			typedef typename node::const_node_ptr				const_node_ptr;
			typedef typename node::node_ref						node_ref;
			typedef typename node::const_node_ref				const_node_ref;
			
			typedef AllocNode									alloc_node;
			typedef typename AllocNode::size_type				size_type;

			typedef typename ft::rbt_iterator<node>				iterator;
			typedef typename ft::rbt_const_iterator<node>		const_iterator;

			/*
			 ** CONSTRUCTORS
			 */


			rbt(void):
				_root(NULL), _size(0), _alloc(), _comp() {}

			rbt(alloc_node alloc, key_compare comp, node_ptr root = NULL, size_type size = 0):
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
			bool	value_compare(const value_type& x, const value_type& y) const {

				return (_comp(x.first, y.first));
			}

			/* bool	comp(const key& x, const key& y) { */
			bool	value_compare(const key& x, const key& y) const {

				return (_comp(x, y));
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
			
			bool	empty(void) const {

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
					return (iterator(this->_root->max()));
				return (iterator());
			}
			
			const_iterator const_max(void) const {

				if (this->_root)
					return (const_iterator(this->_root->max()));
				return (const_iterator());
			}

			iterator min(void) const {
				
				if (this->_root)
					return (iterator(this->_root->min()));
				return (iterator());
			}
			
			const_iterator const_min(void) const {

				if (this->_root)
					return (const_iterator(this->_root->min()));
				return (const_iterator());
			}

			iterator begin(void) const {

				return (this->min());
			}

			const_iterator const_begin(void) const {

				return (this->min());
			}

			iterator end(void) const {

				return (this->max());
			}

			const_iterator const_end(void) const {

				return (this->max());
			}

			ft::pair<iterator, bool>	create_node(const T &new_node) {

				if (this->_root == NULL) {
					
					this->_root = this->_alloc.allocate(1);
					this->_alloc.construct(this->_root, node(new_node));
					this->_root->color = BLACK;
					this->_root->parent = NULL;
					this->_size += 1;
					return (ft::make_pair<iterator, bool>(iterator(this->_root), true));
				}

				node_ptr tmp_node = this->_root;
				node_ptr tmp_parent = NULL;

				while (tmp_node) {

					tmp_parent = tmp_node;
					if (value_compare(new_node, tmp_node->data)) 
						tmp_node = tmp_node->left_child;
					else if (value_compare(tmp_node->data, new_node))
						tmp_node = tmp_node->right_child;
					else
						return (ft::make_pair<iterator, bool>(iterator(tmp_node), false));
				}

				tmp_node = this->_alloc.allocate(1);
				this->_alloc.construct(tmp_node, node(new_node));
				tmp_node->color = RED;
				tmp_node->parent = tmp_parent;
				this->_size += 1;
				if (value_compare(tmp_parent->data, tmp_node->data))
					tmp_parent->right_child = tmp_node;
				else
					tmp_parent->left_child = tmp_node;
				
				insert_node(tmp_node);
				
				return (ft::make_pair<iterator, bool>(iterator(tmp_node), true));
			}

			node_ptr	insert_node(node_ptr new_node) {

				if (!new_node)
					return (new_node);

				if (!new_node->parent) {

					new_node->color = BLACK;
					return (new_node);
				}

				node_ptr parent = new_node->parent;

				if (!parent && parent->color == BLACK)
					return (new_node);

				node_ptr uncle = parent->sibling();
				if (parent->color == RED && uncle && uncle->color == RED) {

					parent->color = BLACK;
					uncle->color = BLACK;
					parent->parent->color = RED;
					insert_node(parent->parent);
				
					return (new_node);
				}

				if (parent->is_left_child()) {

					if (new_node->is_right_child()) {

						new_node = parent;
						left_rotate(parent);
					}
					parent->color = BLACK;
					if (parent->parent) {

						parent->parent->color = RED;
						right_rotate(parent->parent);
					}
					return (new_node);
				}
				else if (parent->is_right_child()) {

					if (new_node->is_left_child()) {

						new_node = parent;
						right_rotate(parent);
					}
					parent->color = BLACK;
					if (parent->parent) {

						parent->parent->color = RED;
						left_rotate(parent->parent);
					}
					return (new_node);
				}
			return (new_node);
		}

		void	left_rotate(node_ptr n) {

			if (n->right_child) {

				node_ptr right_son = n->right_child;
				if (n->right_child->left_child != NULL) {
					n->right_child = n->right_child->left_child;
					n->right_child->parent = n;
				}
				if (!n->parent)
					this->_root = right_son;
				else if (n->is_left_child())
					n->parent->left_child = right_son;
				else
					n->parent->right_child = right_son;

				right_son->parent = n->parent;
				n->parent = right_son;
				right_son->left_child = n;
			}
		}

		void	right_rotate(node_ptr n) {

			if (n->left_child) {

				node_ptr left_son = n->left_child;
				if (n->left_child->right_child) {
					n->left_child = n->left_child->right_child;
					n->left_child->parent = n;
				}
				if (n->parent)
					this->_root = left_son;
				else if (n->is_left_child())
					n->parent->left_child = left_son;
				else
					n->parent->right_child = left_son;

				left_son->parent = n->parent;
				n->parent = left_son;
				left_son->right_child = n;
			}
		}

		private:

			node_ptr		_root;
			size_type		_size;			
			alloc_node		_alloc;
			key_compare		_comp;

	};
}

#endif
