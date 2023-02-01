/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:48:53 by athirion          #+#    #+#             */
/*   Updated: 2023/02/01 13:23:22 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# define RED 	0
# define BLACK	1

namespace ft {

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

			node(void): p(NULL), left_child(NULL), right_child(NULL), color(RED){}

			node(node_ptr p, node_ptr l_child, node_ptr r_child, int c, value_type pair): 
				parent(p),
				left_child(l_child),
				right_child(r_child),
				color(c), 
				data(pair){}

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

				if (this != &src) {

					this->parent = src.parent;
					this->left_child = src.left_child;
					this->right_child = src.right_child;
					this->color = src.color;
					this->data = src.data;
				}
				return (*this);
			}

			/*
			 ** DESTRUCTOR
			 */

			~node(void);


	};

}

#endif
