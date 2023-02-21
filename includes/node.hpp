/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:48:53 by athirion          #+#    #+#             */
/*   Updated: 2023/02/21 09:39:06 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# define RED 	0
# define BLACK	1

namespace ft {

	template <class Key, class T, class Compare, class Alloc>
	class map;

	template < class T>
	class node {

		public:
			
			typedef T				value_type;
			typedef node*			node_ptr;
			typedef const node*		const_node_ptr;
			typedef node&			node_ref;
			typedef const node&		const_node_ref;
	

			node_ptr	parent;
			node_ptr	left_child;
			node_ptr	right_child;
			int			color;
			value_type	data;
				
			/*
			 ** CONSTRUCTORS
			 */ 

			node(void): parent(NULL), left_child(NULL), right_child(NULL), color(RED){}

			node(const value_type val, node_ptr p = NULL, node_ptr l_child = NULL, node_ptr r_child = NULL, int c = RED): 
				parent(p),
				left_child(l_child),
				right_child(r_child),
				color(c), 
				data(val){}

			/*
			 ** COPY CONSTRUCTOR
			 */

			node(const_node_ref src):
				parent(src.parent),
				left_child(src.left_child),
				right_child(src.right_child),
				color(src.color),
				data(src.data){}

			/*
			 ** COPY ASSIGNMENT OPERATOR
			 */

			node_ref	operator=(const_node_ref rhs) {

				if (this != &rhs) {

					this->parent = rhs.parent;
					this->left_child = rhs.left_child;
					this->right_child = rhs.right_child;
					this->color = rhs.color;
					this->data = rhs.data;
				}
				return (*this);
			}

			/*
			 ** DESTRUCTOR
			 */

			~node(void) {}


			/*
			 ** MEMBER FUNCTIONS
			 */

			
			bool	is_left_child(void) {

				if (this->parent && this->parent->left_child == this)
					return (true);
				return (false);
			}

			bool	is_right_child(void) {

				if (this->parent && this->parent->right_child == this)
					return (true);
				return (false);
			}
			
			node_ptr	max(void) {

				if (!this->right_child)
					return (this);
				return (this->right_child->max());
			}

			node_ptr	min(void) {

				if (!this->left_child)
					return (this);
				return (this->left_child->min());
			}

			//que faire si le node est deja le plus grand de l'arbre ? le plus a
			//droite de tous les autres ?

			node_ptr	successor(void) const {

				node_ptr p;
				node_ptr tmp;

				/* if (!this) */
					/* return (NULL); */
				if (this->right_child)
					return (this->right_child->min());
				p  = this->parent;
				tmp = this;
				while (p && tmp == p->right_child) {

					tmp = p;
					p = p->parent;
				}
				return (p);
			}

			/* node_ptr	successor(void) { */

			/* 	node_ptr p; */
			/* 	node_ptr tmp; */

			/* 	if (!this) */
			/* 		return (NULL); */
				
			/* 	if (this->right_child) */
			/* 		return (this->right_child->min()); */
				
			/* 	if (this->is_left_child) */
			/* 		return (this->parent); */
				
			/* 	if (this->max() == this) */
			/* 		return (this); */
				
			/* 	p  = this->parent; */
			/* 	tmp = this; */
			/* 	while (p && tmp == p->right_child) { */

			/* 		tmp = p; */
			/* 		p = p->parent; */
			/* 	} */
			/* 	return (p); */
			/* } */

			//que faire si le node est deja le plus petit de l'arbre ? le plus a
			//guache de tous les autres ?

			node_ptr	predecessor(void) {

				node_ptr p;
				node_ptr tmp;

				/* if (!this) */
				/* 	return (NULL); */
				if (this->left_child)
					return (this->left_child->max());
				p  = this->parent;
				tmp = this;
				while (p && tmp == p->left_child) {

					tmp = p;
					p = p->parent;
				}
				return (p);
			}


			node_ptr	sibling(void) {

				if (!this->parent)
					return (NULL);
				if (this->is_left_child())
					return (this->parent->right_child);
				if (this->is_right_child())
					return (this->parent->left_child);
				return (NULL);
			}
	};

}

#endif
