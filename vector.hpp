/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:42:21 by athirion          #+#    #+#             */
/*   Updated: 2023/01/06 15:50:57 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {
    
	template < class T, class Alloc = allocator<T> >
    class vector {


        public:

			typedef T												        value_type;
			typedef Alloc											        allocator_type;
			typedef value_type&								 		        reference;
			typedef const value_type&								        const_reference;
			typedef	typename allocator::pointer						        pointer;
			typedef typename allocator::const_pointer				        const_pointer;
			typedef typename std::size_t							        size_type;
			typedef typename std::ptrdiff_t							        difference_type;
			typedef typename std::random_access_iterator<value_type>        iterator
			typedef typename std::random_access_iterator<const value_type>  const_iterator
			typedef typename std::reverse_iterator<iterator>		        reverse_iterator;
			typedef typename std::reverse_iterator<const_iterator>	        const_reverse_iterator;



			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n,
							 const value_type& val = value_type(),
							 const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type());
			vector (const vector& x);

		private:

            allocator_type  _alloc;
			pointer         _start;
			pointer         _end;
			size_type       _capacity;

    };
}
