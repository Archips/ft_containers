/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:08:26 by athirion          #+#    #+#             */
/*   Updated: 2023/02/24 18:07:17 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iterator>
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "make_pair.hpp"
# include "pair.hpp"
# include "rbt_iterator.hpp"
# include "red_black_tree.hpp"
# include "reverse_iterator.hpp"

namespace ft {

	template<class T>
	class node;

	template < class Key, class T, class Compare = std::less<Key>,
			 class Alloc = std::allocator < ft::pair < const Key, T> > >
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
		typedef typename Alloc::template rebind<node<mapped_type> >::other	node_alloc;
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

					return (comp(lhs.first, rhs.first));
				}

			protected:

				Compare _comp;
				value_compare(Compare c): _comp(c) {}

		};

		private:

			size_type						_size;
			allocator_type					_alloc;
			node_alloc						_node_alloc;
			key_compare						_comp;
			rbt<value_type, key_compare>	_rbt;

		public:

		/* 
		 ** CONSTRUCTORS
		 */ 

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_size(0),
				_alloc(alloc), 
				_comp(comp) {}
			
			template < class InputIterator >
			map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				
				for (; first != last; first++)
					this->insert(*first);
			}

		/*
		 ** COPY CONSTRUCTOR
		 */

			map(const map& x) {

				*this = x;
			}

		/*
		 ** DESTRUCTOR
		 */

			~map(void) {

				this->clear();
			}

		/*
		 ** OPERATORS
		 */

			map& operator=(const map& x) {

				if (this != &x) {

					this->_size = x._size;
					this->_alloc = x._alloc;
					this->_node_alloc = x._node_alloc;
					this->_comp = x._comp;
					this->_rbt.clear();
					insert(x.begin(), x.end());
				}
				return (*this);
			}

		/*
		 ** MEMBER FUNCTIONS
		 */

//A RETIRER APRES!!! debug only
rbt<value_type, key_compare>	get_rbt()
{
	return (_rbt);
}	

		/* ITERATORS */

			iterator begin(void) {

				return (this->_rbt.begin());
			}

			const_iterator begin(void) const {

				return (this->_rbt.const_begin());
			}

			iterator end(void) {

				return (this->_rbt.end());
			}

			const_iterator end(void) const {
				
				return (this->_rbt.const_end());
			}

			reverse_iterator rbegin(void) {

				return (reverse_iterator(this->_rbt.end()));
			}

			const_reverse_iterator rbegin(void) const {

				return (const_reverse_iterator(this->_rbt.const_end()));
			}

			reverse_iterator rend(void) {

				return (reverse_iterator(this->_rbt.begin()));
			}

			const_reverse_iterator rend(void) const {
				
				return (const_reverse_iterator(this->_rbt.const_begin()));
			}


		/* CAPACITY */

			bool empty(void) const {

				return (this->_rbt.empty());
			}

			size_type size(void) const {

				return (this->_rbt.size());
			}

			size_type max_size(void) const {

				return (this->_rbt.max_size());
			}

		/* ELEMENT ACCESS */

			mapped_type& operator[](const key_type& k) {

				ft::pair<key_type, mapped_type> new_pair = ft::make_pair(k, mapped_type());

				ft::pair<iterator, bool> ret = insert(new_pair);
				iterator it = ret.first;
				mapped_type &val = it->second;

				return (val);
			}
	
			mapped_type& at(const key_type &k) {

				node_ptr x = this->_rbt.root();
				
				while (x && x->data.first != k)
				{
					if (x && this->_rbt.value_compare(k, x->data.first))
						x = x->left_child;
					else if (x && this->_rbt.value_compare(x->data.first, k))
						x = x->right_child;
				}
				return (x->data.second);
			}

			const mapped_type& at(const key_type& k) const {

				node_ptr x = this->_rbt.root();
				
				while (x && x->data.first != k)
				{
					if (x && this->_rbt.value_compare(k, x->data.first))
						x = x->left_child;
					else if (x && this->_rbt.value_compare(x->data.first, k))
						x = x->right_child;
				}
				return (x->data.second);
			}

		/* MODIFIERS */

			ft::pair<iterator, bool> insert(const value_type& val) {
				
				return (this->_rbt.create_node(val));
			}
			
			iterator insert(iterator position, const value_type& val) {

				(void) position;
				return(this->insert(val).first);
			}


			template < class InputIterator >
			void insert(InputIterator first, InputIterator last) {
			
				for (; first != last; first++)
					insert(*first);
			}

			void erase(iterator position) {

				this->erase(position->first);
			}

			size_type erase(const key_type& k) {

				return (this->_rbt.erase(k));
			}
				

			void erase (iterator first, iterator last) {
			
				iterator	temp;

				for (; first != last; first++) {
						
						temp = first;
						first ++;
						this->erase(temp->first);
				}
			}

			void swap(map& x) {

				size_type						temp_size = this->_size;
				allocator_type					temp_alloc = this->_alloc;
				node_alloc						temp_node_alloc = this->_node_alloc;
				key_compare						temp_comp = this->_comp;

				this->_size = x._size;
				this->_alloc = x._alloc;
				this->_node_alloc = x._node_alloc;
				this->_comp = x._comp;
				this->_rbt.swap(x._rbt);

				x._size = temp_size;
				x._alloc = temp_alloc;
				x._node_alloc = temp_node_alloc;
				x._comp = temp_comp;
			}

			void clear(void) {

				this->_rbt.clear();
			}


		/* OBSERVERS */

			key_compare key_comp(void) const {

				return (this->_comp);
			}

			value_compare value_comp(void) const {

				return (value_compare(this->_comp));
			}

		/* OPERATIONS */

			iterator find(const key_type &k) {
				
				node_ptr x = this->_rbt.root();
				
				while (x && x->data.first != k)
				{
					if (x && this->_rbt.value_compare(k, x->data.first))
						x = x->left_child;
					else if (x && this->_rbt.value_compare(x->data.first, k))
						x = x->right_child;
				}
				if (!x)
					return (this->end());
				return (iterator(x, x->parent));
			}

			const_iterator find(const key_type& k) const {

				node_ptr x = this->_rbt.root();
				
				while (x && x->data.first != k)
				{
					if (x && this->_rbt.value_compare(k, x->data.first))
						x = x->left_child;
					else if (x && this->_rbt.value_compare(x->data.first, k))
						x = x->right_child;
				}
				if (!x)
					return (this->end());
				return (const_iterator(x, x->parent));
			}

			size_type count(const key_type& k) const {

				node_ptr x = this->_rbt.root();
				
				while (x && x->data.first != k)
				{
					if (x && this->_rbt.value_compare(k, x->data.first))
						x = x->left_child;
					else if (x && this->_rbt.value_compare(x->data.first, k))
						x = x->right_child;
				}
				if (!x)
					return (0);
				return (1);
			}

			iterator lower_bound(const key_type& k) {

				iterator it = this->find(k);
				if (it == this->end()) {
					node_ptr x = this->_rbt.root();
					while (x && x->data.first < k) {
						if (x && this->_rbt.value_compare(x->data.first, k))
							x = x->right_child;
					}
					return (iterator(x, x->parent));
				}
				else
					return (it);
			}

			const_iterator lower_bound(const key_type& k) const {

				const_iterator it = this->find(k);
				if (it == this->end()) {
					node_ptr x = this->_rbt.root();
					while (x && x->data.first < k) {
						if (x && this->_rbt.value_compare(x->data.first, k))
							x = x->right_child;
					}
					return (const_iterator(x, x->parent));
				}
				else
					return (it);
			}

			iterator upper_bound(const key_type& k) {
				
				node_ptr x = this->_rbt.root();
				while (x && x->data.first < k) {
					if (x && this->_rbt.value_compare(x->data.first, k))
						x = x->right_child;
					x = x->right_child;
				}
				if (!x)
					return (this->end());
				else
					return (iterator(x, x->parent));
			}

			const_iterator upper_bound(const key_type& k) const {
				
				node_ptr x = this->_rbt.root();
				while (x && x->data.first < k) {
					if (x && this->_rbt.value_compare(x->data.first, k))
						x = x->right_child;
					x = x->right_child;
				}
				if (!x)
					return (this->end());
				else
					return (const_iterator(x, x->parent));
			}
			
			ft::pair<iterator, iterator> equal_range(const key_type& k) {

				ft::pair<iterator, iterator> bound = ft::make_pair(this->lower_bound(k), this->upper_bound(k));
				return (bound);
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {

				ft::pair<const_iterator, const_iterator> bound = ft::make_pair(this->lower_bound(k), this->upper_bound(k));
				return (bound);
			}

		/* ALLOCATOR */

			allocator_type get_allocator(void) const {

				return (this->_alloc);
			}

	};

	template < class Key, class T, class Compare, class Alloc >
	bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.end()));
	}

	template < class Key, class T, class Compare, class Alloc >
	bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		return (!(lhs == rhs));
	}

	template < class Key, class T, class Compare, class Alloc >
	bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < class Key, class T, class Compare, class Alloc >
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		return (!(rhs < lhs));
	}

	template < class Key, class T, class Compare, class Alloc >
	bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		return (rhs < lhs);

	template < class Key, class T, class Compare, class Alloc >
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) {

		return (!(lhs < rhs));
	}

	template < class Key, class T, class Compare, class Alloc >
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
	
		x.swap(y);
	}

}

#endif
