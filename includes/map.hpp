/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:08:26 by athirion          #+#    #+#             */
/*   Updated: 2023/02/01 16:32:39 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iterator>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "make_pair.hpp"
#include "pair.hpp"
#include "red_black_tree.hpp"
#include "reverse_iterator.hpp"

namespace ft {

	template < class Key, class T, class Compare,
			 class Alloc = std::allocator < ft::pair < const Key, T> >
	class map {

		public:

		typedef Key															key_type;
		typedef T															mapped_type;
		typedef typename ft::pair < const Key, T >							value_type;
		typedef typename std::size_t										size_type;
		typedef typename std::ptrdiff_t										difference_type;
		typedef Compare														key_compare;
		typedef Alloc														allocator_type;
		typedef typename Alloc::reference									reference;
		typedef typename Alloc::const_reference								const_reference;
		typedef typename Alloc::pointer										pointer;
		typedef typename Alloc::const_pointer								const_pointer;
		typedef typemame Alloc::template rebind<node<mapped_value>::other	node_alloc;
		typedef node<value_type>											node_type;
		typedef node<value_type>*											node_ptr;
		typedef typename ft::rbt<value_type, key_compare>::iterator			iterator;
		typedef typename ft::rbt<value_type, key_compare>::const_iterator	const_iterator;
		typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		
		class value_compare: public std::binary_function< value_type, value_type, bool > {

			friend class ft::map <Key, T, Compare, Alloc>;

			public:
				
				typedef bool									result_type;
				typedef value_type								first_argument_type;
				typedef value_type								second_argument_type;

				bool operator() (const value_type& lhs, const value_type& rhs) const {

					return (comp(lhs.first, rhs.first);
				}

			protected:

				Compare _comp;
				value_compare(Compare c): _comp(c) {}

		};


		/* 
		 ** CONSTRUCTORS
		 */ 

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				this->_size(0),
				this->_alloc(alloc), 
				this->_comp(comp) {}
			
			/* template < class InputIterator > */
			/* map(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, */
			/* 		const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()); */

		/*
		 ** COPY CONSTRUCTOR
		 */

			/* map(const map& x); */

		/*
		 ** DESTRUCTORS
		 */

			/* ~map(void); */

		/*
		 ** OPERATORS
		 */

			/* map& operator=(const map& x); */

		/*
		 ** MEMBER FUNCTIONS
		 */

		/* ITERATORS */

			iterator begin(void) {

				return (this->_rbt.begin());
			}

			const_iterator begin(void) const {

				return (const_iterator(this->_rbt.begin()));
			}

			iterator end(void) {

				return (this->_rbt.end());
			}

			const_iterator end(void) const {

				return (const_iterator(this->_rbt.end()));
			}

			reverse_iterator rbegin(void) {

				return (reverse_iterator(this->_rbt.end()));
			}

			const_reverse_iterator rbegin(void) const {

				return (const_reverse_iterator(this->_rbt.end()));
			}

			reverse_iterator rend(void) {

				return (reverse_iterator(this->_rbt.begin()));
			}

			const_reverse_iterator rend(void) const {
				
				return (const_reverse_iterator(this->_rbt.begin()));
			}


		/* CAPACITY */

			/* bool empty(void) const; */

			/* size_type size(void) const; */

			/* size_type max_size(void) const; */

		/* ELEMENT ACCESS */

			/* mapped_type& operator[](const key_type& k); */

			/* mapped_type& at(const key_type &k); */

			/* const mapped_type& at(const key_type& k) const; */

		/* MODIFIERS */

			/* ft::pair<iterator, bool> insert(const value_type& val); */
			
			/* iterator insert(iterator position, const value_type& val); */

			/* template < class InputIterator > */
			/* void insert(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last); */

			/* void erase(iterator position); */

			/* size_type erase(const key_type& k); */

			/* void erase (iterator first, iterator last); */

			/* void swap(map& x); */

			/* void clear(void); */


		/* OBSERVERS */

			/* key_compare key_comp(void) const; */

			/* value_compare value_comp(void) const; */

		/* OPERATIONS */

			/* iterator find(const key_type &k); */

			/* const_iterator find(const key_type& k) const; */

			/* size_type count(const key_type& k) const; */

			/* iterator lower_bound(const key_type& k); */

			/* const_iterator lower_bound(const key_type& k) const; */

			/* iterator upper_bound(const key_type& k); */

			/* const_iterator upper_bound(const key_type& k) const; */

			/* ft::pair<iterator, iterator> equal_range(const key_type& k); */

			/* ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const; */

		/* ALLOCATOR */

			/* allocator_type get_allocator(void) const; */

		private:

			size_type						_size;
			allocator_type					_alloc;
			node_alloc						_node_alloc;
			key_compare						_comp;
			rbt<value_type, key_compare>	_rbt;

	};

	/* template < class Key, class T, class Compare, class Alloc > */
	/* bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs); */

	/* template < class Key, class T, class Compare, class Alloc > */
	/* bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs); */

	/* template < class Key, class T, class Compare, class Alloc > */
	/* bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs); */

	/* template < class Key, class T, class Compare, class Alloc > */
	/* bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs); */

	/* template < class Key, class T, class Compare, class Alloc > */
	/* bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs); */

	/* template < class Key, class T, class Compare, class Alloc > */
	/* bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs); */

	/* template < class Key, class T, class Compare, class Alloc > */
	/* void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y); */

}

#endif
