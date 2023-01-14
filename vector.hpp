/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:42:21 by athirion          #+#    #+#             */
/*   Updated: 2023/01/14 16:18:51 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft {
    
	template < class T, class Alloc = std::allocator<T> >
    class vector {

        public:

			typedef T												        value_type;
			typedef T* 			 									      	iterator;
			typedef const T* 											 	const_iterator;
			typedef T&										 		        reference;
			typedef const T&										        const_reference;
			typedef Alloc											        allocator_type;
			typedef	typename Alloc::pointer							        pointer;
			typedef typename Alloc::const_pointer					        const_pointer;
			typedef typename std::size_t							        size_type;
			typedef typename std::ptrdiff_t							        difference_type;
			typedef typename ft::reverse_iterator<iterator>			        reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	        const_reverse_iterator;

			/* CONSTRUCTOR */

			vector(): _size(0), _capacity(0), _alloc(), _start(0), _end(0) {

				std::cout << "Vector default constructor called" << std::endl;
			}

			explicit vector(const Alloc& alloc): _size(0), _capacity(0),  _alloc(alloc), _start(0), _end(0) {};

			explicit vector(size_type count, const T& value = T(), const Alloc& alloc = Alloc()) :
				_size(count), _capacity(_size), _alloc(alloc), _start(_alloc.allocate(_capacity)), _end(0) {

				for (size_type i = 0; i < this->_size; i++) {
					this->_alloc.construct(&this->_start[i], value);
				}
			}

			/* COPY CONSTRUCTOR */

			vector(const vector& x) {
	
                this->_size = x._size;
				this->_capacity = x._capacity;
				this->_alloc = x._alloc;
				this->_start = _alloc.allocate(this->_capacity);
				this->_end = 0;
				for (size_type i = 0; i < this->_size; i ++)
					this->_alloc.construct(&this->_start[i], x[i]);
				std::cout << "Vector copy constructor called" << std::endl;
				std::cout << "Vector _size: " << x._size << " copy _size: " << this->_size << std::endl;
		

			}

			/* OPERATORS */

			vector&	operator=(const vector& x) {

				std::cout << "Vector _size: " << x._size << " copy= _size: " << this->_size << std::endl;
				if (this != &x) {
                    clear();
					this->_alloc = x._alloc;
					this->_start = x._start;
					this->_end   = x._end;
					this->_size  = x._size;
					this->_capacity = x._capacity;
				}
				return (*this);
			}


			/* DESTRUCTOR */

			~vector(void) {
				clear();
				if (this->_start)
					this->_alloc.deallocate(this->_start, this->_capacity);
				std::cout << "Vector destructor called" << std::endl;
			}

				
			/* MEMBER FUNCTIONS */

			// ELEMENT ACCESS

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

				return (*(this->_start + this->_size - 1));
			}

			const_reference back(void) const {

				return (*(this->_start + this->_size - 1));
			}

			// ALLOCATOR

			allocator_type get_allocator(void) const {

				return (this->_alloc);
			}

            // CAPACITY

			size_type	size(void) const {

				return (this->_size);
			}

            size_type  max_size(void) const {

                return (this->_alloc.max_size());
            }

            size_type capacity(void) const {

                return (this->_capacity);
            }

			bool		empty(void) const {

				return (!(this->_size));
			}

            // MODIFIERS

			void		pop_back(void) {

				this->_alloc.destroy(&this->back());
				this->_size --;
			}

            void        clear(void) {
                for (size_type i = 0; i < this->_size; i++) {
                    this->_alloc.destroy(&this->_start[i]);
                }
            }

		private:

			size_type		_size;
			size_type       _capacity;
            allocator_type  _alloc;
			pointer         _start;
			pointer         _end;

    };
}

#endif
