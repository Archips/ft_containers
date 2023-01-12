/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:42:21 by athirion          #+#    #+#             */
/*   Updated: 2023/01/12 15:18:22 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
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
			/* typedef value_type&								 		        reference; */
			/* typedef const value_type&								        const_reference; */
			typedef Alloc											        allocator_type;
			typedef	typename Alloc::pointer							        pointer;
			typedef typename Alloc::const_pointer					        const_pointer;
			typedef typename std::size_t							        size_type;
			typedef typename std::ptrdiff_t							        difference_type;
			typedef typename ft::reverse_iterator<iterator>			        reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	        const_reverse_iterator;

			/* CONSTRUCTOR */

			vector(): _alloc(), _start(0), _end(0), _capacity(0), _size(0) {

				std::cout << "Vector default constructor called" << std::endl;
			}

			explicit vector(const Alloc& alloc): _alloc(alloc), _start(0), _end(0), _capacity(0), _size(0) {};

			explicit vector(size_type count, const T& value = T(), const Alloc& alloc = Alloc()) :
				_alloc(alloc), _size(count), _capacity(count), _start(_alloc.allocate(_capacity)), _end(0) {

				for (size_type i = 0; i < this->_size; i++) {
					_alloc.construct(&_start[i], value);
				}
			}

			/* COPY CONSTRUCTOR */

			vector(const vector& x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity),  _start(_alloc.allocate(x._capacity)), _end(x._end) {

				std::cout << "Vector copy constructor called" << std::endl;
				std::cout << "Vector _size: " << x._size << " copy _size: " << this->_size << std::endl;
			}

			/* OPERATORS */

			vector&	operator=(const vector& x) {

				if (this != &x) {

					this->_alloc = x._alloc;
					this->_start = x._start;
					this->_end   = x._end;
					this->_size  = x._size;
					this->_capacity = x._capacity;
				}
				std::cout << "Vector _size: " << x._size << " copy= _size: " << this->_size << std::endl;
				return (*this);
			}

			reference operator[](size_type pos) {

				return (*(this->_start + pos));
			}

			const_reference operator[](size_type pos) const {

				return (*(this->_start + pos));
			}

			/* DESTRUCTOR */

			~vector() {

				std::cout << "Vector destructor called" << std::endl;
			}

				
			/* MEMBER FUNCTIONS */

			allocator_type get_allocator() const {

				return (this->_alloc);
			}

			size_type	size() const {

				return (this->_size);
			}

			bool		empty() const {

				return (!(this->_size));
			}

		private:

            allocator_type  _alloc;
			pointer         _start;
			pointer         _end;
			size_type       _capacity;
			size_type		_size;

    };
}

#endif
