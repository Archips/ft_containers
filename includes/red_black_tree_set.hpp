/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_set.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:33:17 by athirion          #+#    #+#             */
/*   Updated: 2023/02/27 17:57:38 by athirion         ###   ########.fr       */
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

			typedef	T														value_type;
			typedef Compare													key_compare;	
			
			typedef rbt*													rbt_ptr;
			typedef const rbt*												const_rbt_ptr;
			typedef rbt&													rbt_ref;
			typedef const rbt&												const_rbt_ref;

			typedef typename node::node_ptr									node_ptr;
			typedef typename node::const_node_ptr							const_node_ptr;
			typedef typename node::node_ref									node_ref;
			typedef typename node::const_node_ref							const_node_ref;
			
			typedef AllocNode												alloc_node;
			typedef typename AllocNode::size_type							size_type;

			typedef typename ft::rbt_iterator_set<node, key_compare>		iterator;
			typedef typename ft::rbt_const_iterator_set<node, key_compare>	const_iterator;

			/*
			 ** CONSTRUCTORS
			 */


			rbt(void):
				_root(NULL), _size(0), _alloc(alloc_node()), _comp(key_compare()) {}


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

			bool	value_compare(const value_type& x, const value_type& y) const {
				
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

			node_ptr max(node_ptr n) const {
			
				if (!n)
					return (NULL);
				while (n->right_child)
					n = n->right_child;
				return (n);
			}
			
			node_ptr min(node_ptr n) const {
				
				if (!n)
					return (NULL);
				while (n->left_child)
					n = n->left_child;
				return (n);
			}

			iterator begin(void) const {

				node_ptr begin = this->min(this->_root);
				return (iterator(begin, NULL));
			}

			const_iterator const_begin(void) const {
				
				node_ptr begin = this->min(this->_root);
				return (const_iterator(begin, NULL));
			}

			iterator end(void) const {
			
				return (iterator(NULL, this->max(this->_root)));
			}

			const_iterator const_end(void) const {
		
				return (const_iterator(NULL, this->max(this->_root)));
			}

			ft::pair<iterator, bool>	create_node(const T &new_node) {

				if (this->_root == NULL) {
					this->_root = this->_alloc.allocate(1);
					this->_alloc.construct(this->_root, node(new_node));
					this->_root->color = BLACK;
					this->_root->parent = NULL;
					this->_size += 1;
					return (ft::make_pair<iterator, bool>(iterator(this->_root, NULL), true));
				}

				node_ptr tmp_node = this->_root;
				node_ptr tmp_parent = NULL;
				while (tmp_node) {

					tmp_parent = tmp_node;
					if (value_compare(new_node, tmp_node->data)) { 
						
						tmp_node = tmp_node->left_child;
					}
					else if (value_compare(tmp_node->data, new_node)) {
						
						tmp_node = tmp_node->right_child;
					}	
					else
						return (ft::make_pair<iterator, bool>(iterator(tmp_node, NULL), false));
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
				
				return (ft::make_pair<iterator, bool>(iterator(tmp_node, NULL), true));
			}

			void insert_node(node_ptr k) {

				node_ptr u;

				while (k->parent && k->parent->color == RED) {

					if (k->parent == k->parent->parent->left_child) {
						
						u = k->parent->parent->right_child;
						if (u && u->color == RED) {

							k->parent->color = BLACK;
							u->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else {

							if (k == k->parent->right_child) {

								k = k->parent;
								left_rotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							right_rotate(k->parent->parent);
						}
					}
					else {

						u = k->parent->parent->left_child;
						if (u && u->color == RED) {

							k->parent->color = BLACK;
							u->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else {

							if (k == k->parent->left_child) {

								k = k->parent;
								right_rotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							left_rotate(k->parent->parent);
						}
					}

					if (this->_root == k)
						break;
				}
				this->_root->color = BLACK;
			}

			void	left_rotate(node_ptr x) {

				node_ptr y = x->right_child;
				x->right_child = y->left_child;
				if (y->left_child)
					y->left_child->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL)
					this->_root = y;
				else if (x == x->parent->left_child)
					x->parent->left_child = y;
				else
					x->parent->right_child = y;
				y->left_child = x;
				x->parent = y;
			}

			void	right_rotate(node_ptr x) {

				node_ptr y = x->left_child;
				x->left_child = y->right_child;
				if (y->right_child)
					y->right_child->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL)
					this->_root = y;
				else if (x == x->parent->right_child)
					x->parent->right_child = y;
				else
					x->parent->left_child = y;
				y->right_child = x;
				x->parent = y;
			}

			size_type	erase(const value_type& key) {

				node_ptr z = this->_root;
				node_ptr x;
				node_ptr y;
				int	temp_color;
					
				while (z && z->data != key) {

					if (z && value_compare(key, z->data))
						z = z->left_child;
					else if (z && value_compare(z->data, key))
						z = z->right_child;
				}
				if (!z)
					return (0);

				y = z;
				temp_color = y->color;
				if (!z->left_child) {

					x = z->right_child;
					transplant(z, z->right_child);
				}
				else if (!z->right_child) {

					x = z->left_child;
					transplant(z, z->left_child);
				}
				else {
					
					y = min(z->right_child);
					temp_color = y->color;
					x = y->right_child;
					if (x && y->parent == z)
						x->parent = y;
					else {

						transplant(y, y->right_child);
						y->right_child = z->right_child;
						if (y->right_child)
							y->right_child->parent = y;
					}
					transplant(z, y);
					y->left_child = z->left_child;
					y->left_child->parent = y;
					y->color = z->color;
				}
				if (x && temp_color == BLACK)
					delete_fix(x);
				this->_alloc.destroy(z);
				this->_alloc.deallocate(z, 1);
				this->_size --;
				return (1);
			}

			void	transplant(node_ptr u, node_ptr v) {

				if (!u->parent)
					this->_root = v;
				else if (u == u->parent->left_child)
					u->parent->left_child = v;
				else
					u->parent->right_child = v;
				if (v)
					v->parent = u->parent;
			}

			void	clear(void) {

				this->_root = this->destroy_tree(this->_root);
			}

			void	destroy_node(node_ptr x) {

				this->_alloc.destroy(x);
				this->_alloc.deallocate(x, 1);
			}

			node_ptr	destroy_tree(node_ptr node_tree) {

				if (!node_tree)
					return (NULL);
				if (node_tree->left_child)
					destroy_tree(node_tree->left_child);
				if (node_tree->right_child)
					destroy_tree(node_tree->right_child);
				destroy_node(node_tree);
				this->_size = 0;
				return (NULL);
			}

			void	delete_fix(node_ptr x) {

				node_ptr w;

				while (x != this->_root && x->color == BLACK) {

					if (x == x->parent->left_child) {

						w = x->parent->right_child;
						if (w->color == RED) {

							w->color = BLACK;
							x->parent->color = RED;
							left_rotate(x->parent);
							w = x->parent->right_child;
						}
						if (w->left_child->color == BLACK && w->right_child->color == BLACK) {

							w->color = RED;
							x = x->parent;
						}
						else {

							if (w->right_child->color == BLACK) {

								w->left_child->color = BLACK;
								w->color = RED;
								right_rotate(w);
								w = x->parent->right_child;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right_child->color = BLACK;
							left_rotate(x->parent);
							x = this->_root;
						}
					}
					else {
					
						if (x == x->parent->right_child) {

							w = x->parent->left_child;
							if (w->color == RED) {

								w->color = BLACK;
								x->parent->color = RED;
								left_rotate(x->parent);
								w = x->parent->left_child;
							}
							if (w->right_child->color == BLACK && w->left_child->color == BLACK) {

								w->color = RED;
								x = x->parent;
							}
							else {

								if (w->right_child->color == BLACK) {

									w->right_child->color = BLACK;
									w->color = RED;
									right_rotate(w);
									w = x->parent->left_child;
								}
								w->color = x->parent->color;
								x->parent->color = BLACK;
								w->left_child->color = BLACK;
								left_rotate(x->parent);
								x = this->_root;
							}
						}
					}
				}
			
				x->color = BLACK;
			}

			void	swap(rbt &cpy) {

				node_ptr tmp_root = this->_root;
				size_type tmp_size = this->_size;
				alloc_node tmp_alloc = this->_alloc;
				key_compare tmp_comp = this->_comp;

				this->_root = cpy._root;
				this->_size = cpy._size;
				this->_alloc = cpy._alloc;
				this->_comp = cpy._comp;

				cpy._root = tmp_root;
				cpy._size = tmp_size;
				cpy._alloc = tmp_alloc;
				cpy._comp = tmp_comp;
			}

			private:

			node_ptr		_root;
			size_type		_size;			
			alloc_node		_alloc;
			key_compare		_comp;

	};
}

#endif
