/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:42:21 by athirion          #+#    #+#             */
/*   Updated: 2023/02/01 16:17:08 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator> // std::distance
#include <stdexcept>
#include <string>
#include "equal.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft {
    
	template < class T, class Alloc = std::allocator<T> >
    class vector {

        public:

			typedef T												        value_type;
			typedef T* 			 									      	iterator;
			typedef const T* 											 	const_iterator;
			typedef typename Alloc::reference				 		        reference;
			typedef typename Alloc::const_reference					        const_reference;
			typedef Alloc											        allocator_type;
			typedef	typename Alloc::pointer							        pointer;
			typedef typename Alloc::const_pointer					        const_pointer;
			typedef typename std::size_t							        size_type;
			typedef typename std::ptrdiff_t							        difference_type;
			typedef typename ft::reverse_iterator<iterator>			        reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	        const_reverse_iterator;

			/*
			 ** CONSTRUCTORS
			 */

			vector(): _size(0), _capacity(0), _alloc(), _start(0), _end(0) {}

			explicit vector(const Alloc& alloc): _size(0), _capacity(0),  _alloc(alloc), _start(0), _end(0) {}

			explicit vector(size_type count, const T& value = T(), const Alloc& alloc = Alloc()) :
				_size(count), _capacity(_size), _alloc(alloc), _start(_alloc.allocate(_capacity)), _end(_start + _size - 1) {

				for (size_type i = 0; i < this->_size; i++) {

					this->_alloc.construct(&this->_start[i], value);
				}

			}

			template <class InputIterator>
			vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()):
			_size(std::distance(first, last)), _capacity(_size), _alloc(alloc), _start(_alloc.allocate(_capacity)) {
				
				for (size_type i = 0; i < this->_size; i ++)
					this->_alloc.construct(&this->_start[i], *(first++));
				this->_end = this->_start + this->_size - 1;	
			}

			/*
			 ** COPY CONSTRUCTOR
			 */

			vector(const vector& x) {

                this->_size = x._size;
				this->_capacity = x._capacity;
				this->_alloc = x._alloc;
				this->_start = this->_alloc.allocate(this->_capacity);
				this->_end = this->_start + this->_size - 1;
				for (size_type i = 0; i < this->_size; i ++)
					this->_alloc.construct(&this->_start[i], x[i]);
			}

			/* 
			 ** COPY ASSIGNMENT OPERATOR
			 */

			vector&	operator=(const vector& x) {

				if (this != &x) {
					this->clear();
					this->insert(this->begin(), x.begin(), x.end());
					/* this->_alloc = x._alloc; */
					/* this->_capacity = x._capacity; */
					/* this->_start = this->_alloc.allocate(this->_capacity); */
					/* this->_size = x._size; */
					/* this->_end = this->_start + this->_size - 1; */
					/* for (size_type i = 0; i < this->_size; i ++) */
					/* 	this->_alloc.construct(&this->_start[i], x[i]); */
				}
				return (*this);
			}


			/*
			 ** DESTRUCTOR
			 */

			~vector(void) {

				clear();
				if (this->_start)
					this->_alloc.deallocate(this->_start, this->_capacity);
			}

				
			/*
			 ** MEMBER FUNCTIONS
			 */

			/* ITERATORS */
			
			iterator begin(void) {

				return (iterator(this->_start));
			}

			const_iterator begin(void) const {

				return (const_iterator(this->_start));
			}

			iterator end(void) {

				return (this->_start + this->_size);
			}

			const_iterator end(void) const {

				return (this->_start + this->_size);
			}

			reverse_iterator rbegin(void) {
				
				return (reverse_iterator(this->end()));
			}

			const_reverse_iterator rbegin(void) const {

				return (const_reverse_iterator(this->end()));
			}

			reverse_iterator rend(void) {

				return (reverse_iterator(this->begin()));
			}

			const_reverse_iterator rend(void) const {

				return (const_reverse_iterator(this->begin()));
			}

			/* ELEMENT ACCESS */

			reference operator[](size_type pos) {

				return (*(this->_start + pos));
			}

			const_reference operator[](size_type pos) const {

				return (*(this->_start + pos));
			}
			
			reference at(size_type n) {
		
				if (n < 0 || n >= this->_size)
					throw std::out_of_range("vector::_M_range_check");
				return (*(this->_start + n));
			}

			const_reference at(size_type n) const {

				if (n < 0 || n >= this->_size)
					throw std::out_of_range("vector::_M_range_check");
				return (*(this->_start + n));
			}

			reference front(void) {

				return (*(this->_start));
			}
	
			const_reference front(void) const {

				return (*(this->_start));
			}

			reference back(void) {

				return (*(this->_end));
			}

			const_reference back(void) const {

				return (*(this->_end));
			}

			/* ALLOCATOR */

			allocator_type get_allocator(void) const {

				return (this->_alloc);
			}

            /* CAPACITY */

			size_type	size(void) const {

				return (this->_size);
			}

            size_type  max_size(void) const {

                return (this->_alloc.max_size());
            }

            void    resize(size_type n, value_type val = value_type()) {

				if (n > this->max_size()) {
					
					throw std::length_error("vector::_m_fill_insert");
				}
				else if (n < this->_size) {
				
					for (size_type i = n; i < this->_size; i ++)
						this->_alloc.destroy(&this->_start[i]);
					this->_size = n;
					this->_end = this->_start + this->_size - 1;
				}
				else if (n > this->_size) {
					
					this->reserve(n);
					for (size_type i = this->_size; i < n; i ++)
						this->_alloc.construct(&this->_start[i], val);
					this->_size = n;
					this->_end = this->_start + this->_size - 1;
				}
			}

            size_type capacity(void) const {

                return (this->_capacity);
            }

			bool		empty(void) const {

				return (!(this->_size));
			}

            void    reserve(size_type n) {

                if (n > this->max_size()) {
                    
					throw std::length_error("vector::_M_fill_insert");
                }
                else if (n > this->_capacity) {
                
					pointer new_alloc = _alloc.allocate(n);
                    pointer end = new_alloc;
					for (size_type i = 0; i < this->_size; i++) {
                        this->_alloc.construct(&new_alloc[i], this->_start[i]);
                        this->_alloc.destroy(&this->_start[i]);
                        end ++;
                    }
					this->_alloc.deallocate(this->_start, this->capacity());
					this->_start = new_alloc;
                    this->_end = end;
                    this->_capacity = n;
                }
            }

            /* MODIFIERS */

			template < class InputIterator >
			void	assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
                this->clear();
                this->insert(this->begin(), first, last);
            }

			void	assign(size_type n, const value_type& val) {
                this->clear();
                if (n > this->_capacity)
                    this->reserve(n);
                for (size_type i = 0; i < n; i ++)
                    this->push_back(val);
            }

			void		push_back(const value_type& val) {

				if (this->_size + 1 > this->_capacity)
					this->reserve(this->_size + 1);
				this->_size += 1;
				this->_end = this->_start + this->_size - 1;
				this->_alloc.construct(&this->_start[this->_size - 1], val);
			}

			void		pop_back(void) {
				
				this->_alloc.destroy(&this->back());
				this->_size --;
				this->_end = this->_start + this->_size - 1;
			}

			iterator insert(iterator position, const value_type& val) {
				
				ft::vector<value_type> temp(*this);
				iterator pos = temp.begin() + std::distance(this->begin(), position);
				size_type new_elem = std::distance(this->begin(), position);
				if (this->_size + 1 > this->_capacity)
					this->reserve(this->_size + 1);
				this->clear();
				for (iterator it = temp.begin(); it != pos; it ++) {
					this->push_back(*it);
				}
				this->push_back(val);
				for (iterator it = pos; it != temp.end(); it ++) {
					this->push_back(*it);
				}
				return (&this->_start[new_elem]);
			}
			
			void	insert(iterator position, size_type n, const value_type& val) {
				
				if (!n)
					return ;
				ft::vector<value_type> temp(*this);
				iterator pos = temp.begin() + std::distance(this->begin(), position);
				if (this->_size + n > this->_capacity)
					this->reserve(this->_size + n);
				this->clear();
				for (iterator it = temp.begin(); it != pos; it ++) {
					this->push_back(*it);
				}
				for (size_type i = 0; i < n; i ++) {
					this->push_back(val);
				}
				for (iterator it = pos; it != temp.end(); it ++) {
					this->push_back(*it);
				}
			}

			template < class InputIterator >
			void insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {

				size_type count = std::distance(first, last);

				ft::vector<value_type> temp(*this);
				iterator pos = temp.begin() + std::distance(this->begin(), position);
				if (this->_size + count > this->_capacity)
					this->reserve(this->_size + count);
				this->clear();
				for (iterator it = temp.begin(); it != pos; it ++) {
					this->push_back(*it);
				}
				for (InputIterator it = first; it != last; it ++) {
					this->push_back(*it);
				}
				for (iterator it = pos; it != temp.end(); it ++) {
					this->push_back(*it);
				}
			}

			iterator erase(iterator position) {

				ft::vector<value_type> temp = *this;
				iterator pos = temp.begin() + std::distance(this->begin(), position);
				this->clear();
				iterator it = temp.begin();
				for (; it != pos; it ++)
					this->push_back(*it);
                iterator it_temp = it;
                temp._alloc.destroy(it_temp);
				it++;
				for (; it != temp.end(); it ++)
					this->push_back(*it);
				return (position);
			}

			iterator erase(iterator first, iterator last) {
				if (first == last)
					return (first);
                size_type dist = std::distance(first, last);
				iterator it = first;
                while (dist) {
                    it = erase(it);
                    dist--;
                }
				return (it);
			}

            void        clear(void) {
               
				if (this->_size) {
					for (size_type i = 0; i < this->_size; i++) {
                   	 	
						this->_alloc.destroy(&this->_start[i]);
                	}
				}
				this->_size = 0;
				this->_end = this->_start;
            }

			void		swap(vector& x) {
			
				size_type 		temp_size = this->_size;
				size_type		temp_capacity = this->_capacity;
				allocator_type	temp_alloc = this->_alloc;
				pointer			temp_start = this->_start;
				pointer			temp_end = this->_end;

				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_alloc = x._alloc;
				this->_start = x._start;
				this->_end = x._end;

				x._size = temp_size;
				x._capacity = temp_capacity;
				x._alloc = temp_alloc;
				x._start = temp_start;
				x._end = temp_end;
			}

		private:

			size_type		_size;
			size_type       _capacity;
            allocator_type  _alloc;
			pointer         _start;
			pointer         _end;

    };

	template < class T, class Alloc >
	bool operator==(const ft::vector<T, Alloc>&lhs, const ft::vector<T, Alloc>&rhs) {
	
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template < class T, class Alloc >
	bool operator!=(const ft::vector<T, Alloc>&lhs, const ft::vector<T, Alloc>&rhs) {

		return (!(lhs == rhs));
	}

	template < class T, class Alloc >
	bool operator<(const ft::vector<T, Alloc>&lhs, const ft::vector<T, Alloc>&rhs) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < class T, class Alloc >
	bool operator<=(const ft::vector<T, Alloc>&lhs, const ft::vector<T, Alloc>&rhs) {

		return (!(rhs < lhs));
	}

	template < class T, class Alloc >
	bool operator>(const ft::vector<T, Alloc>&lhs, const ft::vector<T, Alloc>&rhs) {

		return (rhs < lhs);
	}

	template < class T, class Alloc >
	bool operator>=(const ft::vector<T, Alloc>&lhs, const ft::vector<T, Alloc>&rhs) {
		
		return (!(lhs < rhs));
	}

	template < class T, class Alloc >
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {

		x.swap(y);
	}

}

#endif
