/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:33:17 by athirion          #+#    #+#             */
/*   Updated: 2023/02/23 17:04:46 by athirion         ###   ########.fr       */
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

			typedef	T													value_type;
			typedef typename T::first_type								key;
			typedef typename T::second_type								value;
			typedef Compare												key_compare;	
			
			typedef rbt*												rbt_ptr;
			typedef const rbt*											const_rbt_ptr;
			typedef rbt&												rbt_ref;
			typedef const rbt&											const_rbt_ref;

			typedef typename node::node_ptr								node_ptr;
			typedef typename node::const_node_ptr						const_node_ptr;
			typedef typename node::node_ref								node_ref;
			typedef typename node::const_node_ref						const_node_ref;
			
			typedef AllocNode											alloc_node;
			typedef typename AllocNode::size_type						size_type;

			typedef typename ft::rbt_iterator<node, key_compare>		iterator;
			typedef typename ft::rbt_const_iterator<node, key_compare>	const_iterator;

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

// print rbt fct 

			void    print_prefix( node_ptr cur, int level ) const
			{
					std::cout << std::string(2 * level, ' ');
					if (!cur)
							std::cout << "NULL (B)" << std::endl;
					else
					{
							std::cout << cur->data.first << "(";
							if (cur->color == RED)
									std::cout << "R)" << std::endl;
							else
									std::cout << "B)" << std::endl;
							level += 1;
							print_prefix(cur->left_child, level);
							print_prefix(cur->right_child, level);
					}
			}

			/*
			 ** MEMBER FUNCTIONS
			 */

			bool	value_compare(const value_type& x, const value_type& y) const {
				
				return (_comp(x.first, y.first));
			}

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
				return (iterator(begin));
			}

			const_iterator const_begin(void) const {
				
				node_ptr begin = this->min(this->_root);
				return (const_iterator(begin));
			}

			iterator end(void) const {
			
				node_ptr end = this->max(this->_root);
				return (iterator(end));
			}

			const_iterator const_end(void) const {
				
				node_ptr end = this->max(this->_root);
				return (const_iterator(end));
			}

			ft::pair<iterator, bool>	create_node(const T &new_node) {

				if (this->_root == NULL) {
					std::cout << ">>> create_node #0 <<<" << std::endl;
					this->_root = this->_alloc.allocate(1);
					this->_alloc.construct(this->_root, node(new_node));
					this->_root->color = BLACK;
					this->_root->parent = NULL;
					this->_size += 1;
					return (ft::make_pair<iterator, bool>(iterator(this->_root), true));
				}

				node_ptr tmp_node = this->_root;
				node_ptr tmp_parent = NULL;
				std::cout << ">>> create_node #1 <<<" << std::endl;
				while (tmp_node) {

					tmp_parent = tmp_node;
					if (value_compare(new_node, tmp_node->data)) { 
						
						/* std::cout << ">>>>> create node #2 <<<<<<" << std::endl; */
						tmp_node = tmp_node->left_child;
					}
					else if (value_compare(tmp_node->data, new_node)) {
						
						/* std::cout << ">>>>> create node #3 <<<<<<" << std::endl; */
						tmp_node = tmp_node->right_child;
					}	
					else
						return (ft::make_pair<iterator, bool>(iterator(tmp_node), false));
				}
				std::cout << ">>> create_node #2<<<" << std::endl;

				tmp_node = this->_alloc.allocate(1);
				this->_alloc.construct(tmp_node, node(new_node));
				tmp_node->color = RED;
				tmp_node->parent = tmp_parent;
				this->_size += 1;
				if (value_compare(tmp_parent->data, tmp_node->data))
					tmp_parent->right_child = tmp_node;
				else
					tmp_parent->left_child = tmp_node;
				
				tmp_node = insert_node(tmp_node);
				
				return (ft::make_pair<iterator, bool>(iterator(tmp_node), true));
			}

			node_ptr	insert_node(node_ptr new_node) {

				if (!new_node) {

					std::cout << ">>> insert #1 <<<" << std::endl;
					return (new_node);
				}

				if (!new_node->parent) {
					
					std::cout << ">>> insert #2 <<<" << std::endl;
					new_node->color = BLACK;
					return (new_node);
				}

				node_ptr parent = new_node->parent;

				if (!parent && parent->color == BLACK) {
				
					std::cout << ">>> insert #3 <<<" << std::endl;
					return (new_node);
				}

				node_ptr uncle = parent->sibling();
				if (parent->color == RED && uncle && uncle->color == RED) {
					
					std::cout << ">>> insert #4 <<<" << std::endl;
					parent->color = BLACK;
					uncle->color = BLACK;
					parent->parent->color = RED;
					insert_node(parent->parent);
				
					return (new_node);
				}

				if (parent->is_left_child()) {

					if (new_node->is_right_child()) {
						
						std::cout << ">>> insert #5 <<<" << std::endl;
						new_node = parent;
						left_rotate(parent);
					}
					parent->color = BLACK;
					if (parent->parent) {
						
						std::cout << ">>> insert #6 <<<" << std::endl;
						parent->parent->color = RED;
						right_rotate(parent->parent);
					}
					return (new_node);
				}
				else if (parent->is_right_child()) {
					std::cout << ">>> insert #### <<<" << std::endl;

					if (new_node->is_left_child()) {

						std::cout << ">>> insert #7 <<<" << std::endl;
						new_node = parent;
						right_rotate(parent);
					}
					parent->color = BLACK;
					if (parent->parent) {
						
						std::cout << ">>> insert #8 <<<" << std::endl;
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
				n->right_child = right_son->left_child;
				if (right_son->left_child != NULL) {
					right_son->left_child->parent = n;
				}
				if (!n->parent) {
					this->_root = right_son;
				}
				else if (n->is_left_child()) {
					n->parent->left_child = right_son;
				}
				else {
					n->parent->right_child = right_son;
				}
				/* right_son->parent = n->parent; */
				right_son->left_child = n;
				n->parent = right_son;
			}
		}

		void	right_rotate(node_ptr n) {

			if (n->left_child) {

				node_ptr left_son = n->left_child;
				n->left_child = left_son->right_child;
				if (left_son->right_child != NULL) {
					left_son->right_child->parent = n;
				}
				if (!n->parent)
					this->_root = left_son;
				else if (n->is_left_child())
					n->parent->left_child = left_son;
				else
					n->parent->right_child = left_son;

				/* left_son->parent = n->parent; */
				left_son->right_child = n;
				n->parent = left_son;
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
